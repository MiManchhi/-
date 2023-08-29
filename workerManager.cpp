#include"workerManager.h"

WorkerManager::WorkerManager()
{
	this->workNum = 0;
	this->workarray = NULL;
}

void WorkerManager::ShowMenu()
{
	cout << "*************************************" << endl;
	cout << "******* 欢迎使用职工管理系统 ! ******" << endl;
	cout << "********** 0.退出管理程序 ***********" << endl;
	cout << "********** 1.增加职工信息 ***********" << endl;
	cout << "********** 2.显示职工信息 ***********" << endl;
	cout << "********** 3.删除离职职工 ***********" << endl;
	cout << "********** 4.修改职工信息 ***********" << endl;
	cout << "********** 5.查找职工信息 ***********" << endl;
	cout << "********** 6.按照编号排序 ***********" << endl;
	cout << "********** 7.清空所有文档 ***********" << endl;
	cout << "*************************************" << endl;
}

//退出管理程序
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用! " << endl;
	system("pause");
	exit(0); //结束正在执行的程序 
}
void WorkerManager::Addworker()
{
	cout << "请输入添加人数：" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum >0 )
	{
		int newsize = this->workNum + addnum;
		Worker** newspace = new Worker*[newsize];
		if (this->workarray != NULL)
		{
			for (int i = 0; i < this->workNum; i++)
			{
				newspace[i] = this->workarray[i];
			}
		}
		for (int i = 0; i < addnum; i++)
		{
			string id;
			string name;
			string did;
			cout << "请输入第" << i + 1 << "个员工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个员工的姓名" << endl;
			cin >> name;
			while (true)
			{
				cout << "请输入第" << i + 1 << "个员工的岗位" << "(员工，经理，老板)" << endl;
				cin >> did;
				if (did.compare("员工") == 0 || did.compare("经理") == 0 || did.compare("老板") == 0)
				{
					break;
				}
				else
				{
					cout << "输入错误，请重新输入！" << endl;
				}
			}
			int temp = 0;
			if (did == "员工")
			{
				temp = 1;
			}
			if (did == "经理")
			{
				temp = 2;
			}
			if (did == "老板")
			{
				temp = 3;
			}
			Worker* worker = NULL;
			switch (temp)
			{
			case 1:
				worker = new Employee(id, name, did);
				break;
			case 2:
				worker = new Manager(id, name, did);
				break;
			case 3:
				worker = new Boss(id, name, did);
				break;
			default:
				break;
			}
			//添加新员工
			newspace[this->workNum + i] = worker;
		}
		//删除原来空间
		delete[] workarray;
		//更改新空间指向
		this->workarray = newspace;
		//更新人数
		this->workNum = newsize;
		cout << "成功添加" << addnum << "名员工!" << endl;
		this->Save();
	}
	else
	{
		cout << "输入有误！" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->workNum; i++)
	{
		ofs << this->workarray[i]->ID << "\t";
		ofs << this->workarray[i]->Name << "\t";
		ofs << this->workarray[i]->DeptID << endl;
	}
	ofs.close();
}

WorkerManager :: ~WorkerManager()
{
	if (this->workarray != NULL)
	{
		delete[] this->workarray;
		this->workarray = NULL;
	}
}
