#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
	Worker() = default;
	Worker(int id, string name, string deptid) :ID(id), Name(name), DeptID(deptid) {};
	//��ʾ������Ϣ 
	virtual void ShowInfo() = 0;
	//��ȡ��λ���� 
	virtual string GetDeptName() = 0;

	int ID; //ְ����� 
	string Name; //ְ������ 
	string DeptID; //ְ�����ڵĲ������� 
};