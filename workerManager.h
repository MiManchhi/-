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
	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool WorkerIsEmpty;
	//�����ļ�
	void Save();
	//�ļ���Ա��������
	int GetNum();
	//��ʼ��Ա��
	void initWorker();
	//��ʾԱ����Ϣ
	void Showworker();
	//����Ա���Ƿ����(ͨ��ID)
	int Exitisworker(int id);
	//ɾ��Ա��
	void Deleteworker();
	//�޸�Ա��
	void Modworker();
	//����Ա��
	void Findworker();
	//����ļ�
	void Clearfile();
	//����
	void Sortworker();
	//��������
	~WorkerManager();
};
