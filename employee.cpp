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
	cout << "员工编号:" << this->ID;
	cout << "\t员工姓名:" << this->Name;
	cout << "\t岗位:" << this->GetDeptName();
	cout << "\t岗位职责: 完成经理交给的任务 " << endl;
}
string Employee::GetDeptName()
{
	return string("员工");
}