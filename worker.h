#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
	//��ʾ������Ϣ 
	virtual void ShowInfo() = 0;
	//��ȡ��λ���� 
	virtual string GetDeptName() = 0;

	string ID; //ְ����� 
	string Name; //ְ������ 
	string DeptID; //ְ�����ڵĲ������� 
};