#pragma once
#include"worker.h"
using namespace std;
class Employee :public Worker
{
public:
	Employee(int id,string name,string did);

	virtual void ShowInfo();

	virtual string GetDeptName();
};
