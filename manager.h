#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager : public Worker
{
public:
	Manager(int id,string name,string did) : Worker(id, name, did) {};

	virtual void ShowInfo();

	virtual string GetDeptName();
};

