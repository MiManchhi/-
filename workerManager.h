#pragma once
#include<iostream>
#include<fstream>
#include<algorithm>
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
	//显示员工信息
	void Showworker();
	//查找员工是否存在(通过ID)
	int Exitisworker(int id);
	//删除员工
	void Deleteworker();
	//修改员工
	void Modworker();
	//查找员工
	void Findworker();
	//清空文件
	void Clearfile();
	//排序
	void Sortworker();
	//析构函数
	~WorkerManager();
};
