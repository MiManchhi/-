#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;
int main()
{
	//ʵ����������� 
	WorkerManager wm;
	//���ò˵� 
	while (true)
	{
		wm.ShowMenu();
		int choice;
		cout << "��������Ҫѡ��Ĳ�����" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳��������
			wm.ExitSystem();
			break;
		case 1: //����ְ����Ϣ
			wm.Addworker();
			break;
		case 2: //��ʾְ����Ϣ
			wm.Showworker();
			break;
		case 3: //ɾ����ְְ��
			wm.Deleteworker();
			break;
		case 4: //�޸�ְ����Ϣ
			wm.Modworker();
			break;
		case 5: //����ְ����Ϣ
			wm.Findworker();
			break;
		case 6: //���ձ������
			break;
		case 7: //��������ĵ�
			wm.Clearfile();
			break;
		default:
			system("cls");	
			break;
		}
	}
	system("pause");
	return 0;
}