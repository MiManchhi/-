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
	this->workarray = new Worker * [this->workNum];
	this->initWorker();
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
			string id;
			string name;
			string did;
			cout << "�������" << i + 1 << "��Ա���ı��" << endl;
			cin >> id;
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
	if (this->workarray != NULL)
	{
		delete[] this->workarray;
		this->workarray = NULL;
	}
}

int WorkerManager::GetNum()
{
	ifstream ifs;
	string id;
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
	string id;
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
