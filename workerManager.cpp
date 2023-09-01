#include"workerManager.h"

WorkerManager::WorkerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		// 测试 cout << "文件不存在!" << endl;
		this->workNum = 0;
		this->workarray = NULL;
		this->WorkerIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，但为空
	char ch;
	ifs.open(FILENAME, ios::in);
	ifs >> ch;
	if (ifs.eof())
	{
		// 测试 cout << "文件为空！" << endl;
		this->workNum = 0;
		this->workarray = NULL;
		this->WorkerIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且有记录
	int num = GetNum();
	// 测试数据 cout << num << endl;
	this->workNum = num;
	if (num == 0)
	{
		this->workNum = 0;
		this->workarray = NULL;
		this->WorkerIsEmpty = true;
		ifs.close();
		return;
	}
	else
	{
		this->workarray = new Worker * [this->workNum];
		this->initWorker();
	}
	/*for (int i = 0; i < num; i++)
	{
		cout << this->workarray[i]->ID << "\t";
		cout << this->workarray[i]->Name << "\t";
		cout << this->workarray[i]->DeptID << endl;
	}*/
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
			int id;
			string name;
			string did;
			cout << "请输入第" << i + 1 << "个员工的编号" << endl;
			cin >> id;
			int index = this->Exitisworker(id);
			while (index != -1)
			{
				cout << "员工编号已存在！请重新输入！" << endl;
				cin >> id;
				index = this->Exitisworker(id);
			}
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
		this->WorkerIsEmpty = false;
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
	if (!this->WorkerIsEmpty)
	{
		for (int i = 0; i < this->workNum; i++)
		{
			if (this->workarray[i] != NULL)
			{
				delete this->workarray[i];
			}
		}
		delete[] this->workarray;
		this->workarray == NULL;
	}
}

int WorkerManager::GetNum()
{
	ifstream ifs;
	int id;
	string name;
	string did;
	int num = 0;
	ifs.open(FILENAME, ios::in);
	while (ifs >> id && ifs >> name && ifs >> name)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::initWorker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	string did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == "员工")
		{
			worker = new Employee(id, name, did);
		}
		if (did == "经理")
		{
			worker = new Manager(id, name, did);
		}
		if (did == "老板")
		{
			worker = new Boss(id, name, did);
		}
		this->workarray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::Showworker()
{
	if (this->WorkerIsEmpty)
	{
		cout << "文件为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->GetNum(); i++)
		{
			this->workarray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::Exitisworker(int id)
{
	int index = -1;
	for (int i = 0; i < this->GetNum(); i++)
	{
		if (this->workarray[i]->ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Deleteworker()
{
	if (this->WorkerIsEmpty)
	{
		cout << "文件不存在或者为空!" << endl;
	}
	else
	{
		cout << "请输入要删除的员工编号：" << endl;
		int id;
		cin >> id;
		if (this->Exitisworker(id) != -1)
		{
			for (int i = 0; i < this->workNum - 1; i++)
			{
				this->workarray[i] = this->workarray[i + 1];
			}
			cout << "删除成功！" << endl;
			this->workNum--;
			this->Save();
		}
		else
		{
			cout << "员工不存在！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Modworker()
{
	if (this->workNum == 0)
	{
		cout << "文件不存在或为空！" << endl;
	}
	else
	{
		cout << "请输入要修改的员工编号:" << endl;
		int id;
		cin >> id;
		int index = this->Exitisworker(id);
		if (index != -1)
		{
			int newid;
			string newname;
			string newdid;
			cout << "请输入新的员工编号：" << endl;
			cin >> newid;
			cout << "请输入新的员工姓名：" << endl;
			cin >> newname;
			cout << "请输入新的员工部门:" << endl;
			cin >> newdid;
			int temp;
			Worker* worker = NULL;
			if (newdid == "员工")
			{
				temp = 1;
			}
			if (newdid == "经理")
			{
				temp = 2;
			}
			if (newdid == "老板")
			{
				temp = 3;
			}
			switch (temp)
			{
			case 1:
				worker = new Employee(newid, newname, newdid);
				break;
			case 2:
				worker = new Manager(newid, newname, newdid);
				break;
			case 3:
				worker = new Boss(newid, newname, newdid);
				break;
			}
			delete this->workarray[index];
			this->workarray[index] = worker;
			this->Save();
			cout << "修改成功！" << endl;
		}
		else
		{
			cout << "员工不存在！" << endl;
		}
		system("pause");
		system("cls");
	}
}

void WorkerManager::Findworker()
{
	if (this->workNum == 0)
	{
		cout << "文件不存在或为空！" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1.按编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		int temp = 0;
		int id;
		string name;
		cin >> temp;
		if (temp == 1)
		{
			cout << "请输入查找的编号：" << endl;
			cin >> id;
			int index = this->Exitisworker(id);
			if (index == -1)
			{
				cout << "此员工不存在！" << endl;
			}
			else
			{
				cout << "查找成功！" << endl;
				this->workarray[index]->ShowInfo();
			}
		}
		if (temp == 2)
		{
			cout << "请输入要查找的员工姓名：" << endl;
			cin >> name;
			bool flag = true;
			while(flag)
			{
				for (int i = 0; i < this->workNum; i++)
				{
					if (this->workarray[i]->Name == name)
					{
						cout << "查找成功！" << endl;
						this->workarray[i]->ShowInfo();
					}
				}
				flag = false;
			}
		}
		if (temp != 1 && temp != 2)
		{
			cout << "输入有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sortworker()
{
	if (this->workNum == 0)
	{
		cout << "文件不存在或者为空！" << endl;
		system("pause");
	}
	else
	{
		cout << "请输入排序方式：" << endl;
		cout << "1.顺序" << endl;
		cout << "2.倒序" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			for (int i = 0; i < this->workNum - 1; i++)
			{
				for (int j = 0; j < this->workNum - 1 - i; j++)
				{
					if (this->workarray[j]->ID > this->workarray[j + 1]->ID)
					{
						Worker* temp = this->workarray[j];
						this->workarray[j] = this->workarray[j + 1];
						this->workarray[j + 1] = temp;
					}
				}
			}
			cout << "排序完成！" << endl;
			for (int i = 0; i < this->workNum; i++)
			{
				this->workarray[i]->ShowInfo();
			}
			system("pause");
			system("cls");
		}
		if (select == 2)
		{
			for (int i = 0; i < this->workNum - 1; i++)
			{
				for (int j = 0; j < this->workNum - 1 - i; j++)
				{
					if (this->workarray[j]->ID < this->workarray[j + 1]->ID)
					{
						Worker* temp = this->workarray[j];
						this->workarray[j] = this->workarray[j + 1];
						this->workarray[j + 1] = temp;
					}
				}
			}
			cout << "排序完成！" << endl;
			for (int i = 0; i < this->workNum; i++)
			{
				this->workarray[i]->ShowInfo();
			}
			system("pause");
			system("cls");
		}
		if (select != 1 && select != 2)
		{
			cout << "输入有误" << endl;
			system("pause");
			system("cls");
		}
	}
}

void WorkerManager::Clearfile()
{
	cout << "请确认是否清空！" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int temp = 0;
	cin >> temp;
	if (temp == 2)
	{
		system("pause");
		system("cls");
	}
	if (temp == 1)
	{
		//ios::trunc 如果文件存在删除并重新创建
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();

		if (!this->WorkerIsEmpty)
		{
			for (int i = 0; i < this->workNum; i++)
			{
				if (this->workarray[i] != NULL)
				{
					delete this->workarray[i];
				}
			}
			this->workNum = 0;
			delete[] this->workarray;
			this->workarray == NULL;
			this->WorkerIsEmpty = true;
		}
		cout << "清除成功！" << endl;
		system("pause");
		system("cls");
	}
	if (temp != 1 && temp != 2)
	{
		cout << "输入有误！已退出！" << endl;
		system("pause");
		system("cls");
	}
}
