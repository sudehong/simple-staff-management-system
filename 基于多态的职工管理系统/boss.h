#pragma once 
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int dId);
	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ��Ϣ
	virtual string getDeptName();


};