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
	//判断文件是否为空的标志
	bool WorkerIsEmpty;
	//保存文件
	void Save();
	//文件中员工的人数
	int GetNum();
	//初始化员工
	void initWorker();

	~WorkerManager();
};
