#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
	//显示个人信息 
	virtual void ShowInfo() = 0;
	//获取岗位名称 
	virtual string GetDeptName() = 0;

	string ID; //职工编号 
	string Name; //职工姓名 
	string DeptID; //职工所在的部门名称 
};