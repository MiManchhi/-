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
	// �˵�
	void ShowMenu();
	//�˳��������
	void ExitSystem();
	//���Ա��
	void Addworker();
    //Ա������
	int workNum;
	//Ա������ָ��
	Worker** workarray;
	//�����ļ�
	void Save();

	~WorkerManager();
};
