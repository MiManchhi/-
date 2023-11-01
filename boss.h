#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Boss : public Worker
{
public:
	Boss(int id, string name, string did) : Worker(id, name, did) {};

	virtual void ShowInfo();

	virtual string GetDeptName();
};


