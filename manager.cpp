#include<iostream>
#include"manager.h"
#include"worker.h"
using namespace std;

Manager::Manager(string id,string name,string did)
{
	this->ID = id;
	this->Name = name;
	this->DeptID = did;
}
void Manager::ShowInfo()
{
	cout << "Ա�����:" << this->ID;
	cout << "\tԱ������:" << this->Name;
	cout << "\t��λ:" << this->GetDeptName();
	cout << "\t��λְ��: ����ϰ�ַ������񣬷ַ������Ա��" << endl;
 }

string Manager::GetDeptName()
{
	return string("����");
}
