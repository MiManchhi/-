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
	cout << "员工编号:" << this->ID;
	cout << "\t员工姓名:" << this->Name;
	cout << "\t岗位:" << this->GetDeptName();
	cout << "\t岗位职责: 完成老板分发的任务，分发任务给员工" << endl;
 }

string Manager::GetDeptName()
{
	return string("经理");
}
