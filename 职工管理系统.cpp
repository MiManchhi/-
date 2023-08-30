#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;
int main()
{
	//实例化管理对象 
	WorkerManager wm;
	//调用菜单 
	while (true)
	{
		wm.ShowMenu();
		int choice;
		cout << "请输入您要选择的操作：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //退出管理程序
			wm.ExitSystem();
			break;
		case 1: //增加职工信息
			wm.Addworker();
			break;
		case 2: //显示职工信息
			break;
		case 3: //删除离职职工
			break;
		case 4: //修改职工信息
			break;
		case 5: //查找职工信息
			break;
		case 6: //按照编号排序
			break;
		case 7: //清空所有文档
			break;
		default:
			system("cls");	
			break;
		}
	}
	system("pause");
	return 0;
}