#include"workerManager.h"

WorkerManager::WorkerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		// ���� cout << "�ļ�������!" << endl;
		this->workNum = 0;
		this->workarray = NULL;
		this->WorkerIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ���Ϊ��
	char ch;
	ifs.open(FILENAME, ios::in);
	ifs >> ch;
	if (ifs.eof())
	{
		// ���� cout << "�ļ�Ϊ�գ�" << endl;
		this->workNum = 0;
		this->workarray = NULL;
		this->WorkerIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ��������м�¼
	int num = GetNum();
	// �������� cout << num << endl;
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
	cout << "******* ��ӭʹ��ְ������ϵͳ ! ******" << endl;
	cout << "********** 0.�˳�������� ***********" << endl;
	cout << "********** 1.����ְ����Ϣ ***********" << endl;
	cout << "********** 2.��ʾְ����Ϣ ***********" << endl;
	cout << "********** 3.ɾ����ְְ�� ***********" << endl;
	cout << "********** 4.�޸�ְ����Ϣ ***********" << endl;
	cout << "********** 5.����ְ����Ϣ ***********" << endl;
	cout << "********** 6.���ձ������ ***********" << endl;
	cout << "********** 7.��������ĵ� ***********" << endl;
	cout << "*************************************" << endl;
}

//�˳��������
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��! " << endl;
	system("pause");
	exit(0); //��������ִ�еĳ��� 
}

void WorkerManager::Addworker()
{
	cout << "���������������" << endl;
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
			cout << "�������" << i + 1 << "��Ա���ı��" << endl;
			cin >> id;
			int index = this->Exitisworker(id);
			while (index != -1)
			{
				cout << "Ա������Ѵ��ڣ����������룡" << endl;
				cin >> id;
				index = this->Exitisworker(id);
			}
			cout << "�������" << i + 1 << "��Ա��������" << endl;
			cin >> name;
			while (true)
			{
				cout << "�������" << i + 1 << "��Ա���ĸ�λ" << "(Ա���������ϰ�)" << endl;
				cin >> did;
				if (did.compare("Ա��") == 0 || did.compare("����") == 0 || did.compare("�ϰ�") == 0)
				{
					break;
				}
				else
				{
					cout << "����������������룡" << endl;
				}
			}
			int temp = 0;
			if (did == "Ա��")
			{
				temp = 1;
			}
			if (did == "����")
			{
				temp = 2;
			}
			if (did == "�ϰ�")
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
			//�����Ա��
			newspace[this->workNum + i] = worker;
		}
		//ɾ��ԭ���ռ�
		delete[] workarray;
		//�����¿ռ�ָ��
		this->workarray = newspace;
		//��������
		this->workNum = newsize;
		cout << "�ɹ����" << addnum << "��Ա��!" << endl;
		this->Save();
		this->WorkerIsEmpty = false;
	}
	else
	{
		cout << "��������" << endl;
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
		if (did == "Ա��")
		{
			worker = new Employee(id, name, did);
		}
		if (did == "����")
		{
			worker = new Manager(id, name, did);
		}
		if (did == "�ϰ�")
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
		cout << "�ļ�Ϊ�գ�" << endl;
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
		cout << "�ļ������ڻ���Ϊ��!" << endl;
	}
	else
	{
		cout << "������Ҫɾ����Ա����ţ�" << endl;
		int id;
		cin >> id;
		if (this->Exitisworker(id) != -1)
		{
			for (int i = 0; i < this->workNum - 1; i++)
			{
				this->workarray[i] = this->workarray[i + 1];
			}
			cout << "ɾ���ɹ���" << endl;
			this->workNum--;
			this->Save();
		}
		else
		{
			cout << "Ա�������ڣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Modworker()
{
	if (this->workNum == 0)
	{
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա�����:" << endl;
		int id;
		cin >> id;
		int index = this->Exitisworker(id);
		if (index != -1)
		{
			int newid;
			string newname;
			string newdid;
			cout << "�������µ�Ա����ţ�" << endl;
			cin >> newid;
			cout << "�������µ�Ա��������" << endl;
			cin >> newname;
			cout << "�������µ�Ա������:" << endl;
			cin >> newdid;
			int temp;
			Worker* worker = NULL;
			if (newdid == "Ա��")
			{
				temp = 1;
			}
			if (newdid == "����")
			{
				temp = 2;
			}
			if (newdid == "�ϰ�")
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
			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			cout << "Ա�������ڣ�" << endl;
		}
		system("pause");
		system("cls");
	}
}

void WorkerManager::Findworker()
{
	if (this->workNum == 0)
	{
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1.����Ų���" << endl;
		cout << "2.����������" << endl;
		int temp = 0;
		int id;
		string name;
		cin >> temp;
		if (temp == 1)
		{
			cout << "��������ҵı�ţ�" << endl;
			cin >> id;
			int index = this->Exitisworker(id);
			if (index == -1)
			{
				cout << "��Ա�������ڣ�" << endl;
			}
			else
			{
				cout << "���ҳɹ���" << endl;
				this->workarray[index]->ShowInfo();
			}
		}
		if (temp == 2)
		{
			cout << "������Ҫ���ҵ�Ա��������" << endl;
			cin >> name;
			bool flag = true;
			while(flag)
			{
				for (int i = 0; i < this->workNum; i++)
				{
					if (this->workarray[i]->Name == name)
					{
						cout << "���ҳɹ���" << endl;
						this->workarray[i]->ShowInfo();
					}
				}
				flag = false;
			}
		}
		if (temp != 1 && temp != 2)
		{
			cout << "��������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sortworker()
{
	if (this->workNum == 0)
	{
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
		system("pause");
	}
	else
	{
		cout << "����������ʽ��" << endl;
		cout << "1.˳��" << endl;
		cout << "2.����" << endl;
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
			cout << "������ɣ�" << endl;
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
			cout << "������ɣ�" << endl;
			for (int i = 0; i < this->workNum; i++)
			{
				this->workarray[i]->ShowInfo();
			}
			system("pause");
			system("cls");
		}
		if (select != 1 && select != 2)
		{
			cout << "��������" << endl;
			system("pause");
			system("cls");
		}
	}
}

void WorkerManager::Clearfile()
{
	cout << "��ȷ���Ƿ���գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int temp = 0;
	cin >> temp;
	if (temp == 2)
	{
		system("pause");
		system("cls");
	}
	if (temp == 1)
	{
		//ios::trunc ����ļ�����ɾ�������´���
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
		cout << "����ɹ���" << endl;
		system("pause");
		system("cls");
	}
	if (temp != 1 && temp != 2)
	{
		cout << "�����������˳���" << endl;
		system("pause");
		system("cls");
	}
}
