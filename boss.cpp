#include<iostream>
#include"boss.h"
#include"worker.h"
using namespace std;

//Boss::Boss(int id, string name, string did)
//{
//	this->ID = id;
//	this->Name = name;
//	this->DeptID = did;
//}
void Boss::ShowInfo()
{
	cout << "Ա�����:" << this->ID;
	cout << "\tԱ������:" << this->Name;
	cout << "\t��λ:" << this->GetDeptName();
	cout << "\t��λְ��: �ַ����������" << endl;
}

string Boss::GetDeptName()
{
	return string("�ϰ�");
}
