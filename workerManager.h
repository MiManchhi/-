#pragma once
#include<iostream>
#include<fstream>
#define FILENAME "worker.txt"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();
	// 菜单
	void ShowMenu();
	//退出管理程序
	void ExitSystem();
	//添加员工
	void Addworker();
    //员工人数
	int workNum;
	//员工数组指针
	Worker** workarray;
	//保存文件
	void Save();

	~WorkerManager();
};
