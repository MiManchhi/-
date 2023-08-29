#include<iostream>
#include"boss.h"
#include"worker.h"
using namespace std;

Boss::Boss(string id, string name, string did)
{
	this->ID = id;
	this->Name = name;
	this->DeptID = did;
}
void Boss::ShowInfo()
{
	cout << "员工编号:" << this->ID;
	cout << "\t员工姓名:" << this->Name;
	cout << "\t岗位:" << this->GetDeptName();
	cout << "分发任务给经理" << endl;
}

string Boss::GetDeptName()
{
	return string("老板");
}
