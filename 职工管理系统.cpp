#include<iostream>
#include"workerManager.h"
using namespace std;
int main()
{
	//ʵ����������� 
	WorkerManager wm;
	//���ò˵� 
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
		break;
	case 2: //��ʾְ����Ϣ
		break;
	case 3: //ɾ����ְְ��
		break;
	case 4: //�޸�ְ����Ϣ
		break;
	case 5: //����ְ����Ϣ
		break;
	case 6: //���ձ������
		break;
	case 7: //��������ĵ�
		break;
	default:
		system("cls");
		break;
	}

	system("pause");
	return 0;
}