#include"employee.h"
using namespace std;

Employee::Employee(int id,string name,string did)
{
	this->ID = id;
	this->Name = name;
	this->DeptID = did;
}
void Employee::ShowInfo()
{
	cout << "Ա�����:" << this->ID;
	cout << "\tԱ������:" << this->Name;
	cout << "\t��λ:" << this->GetDeptName();
	cout << "\t��λְ��: ��ɾ����������� " << endl;
}
string Employee::GetDeptName()
{
	return string("Ա��");
}