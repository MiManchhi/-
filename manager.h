#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager : public Worker
{
public:
	Manager(string id,string name,string did);

	virtual void ShowInfo();

	virtual string GetDeptName();
};

