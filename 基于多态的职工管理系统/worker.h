#pragma once  //��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>
using namespace std;

//ְ��������
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ��Ϣ
	virtual string getDeptName() = 0;

	int m_Id;//ְ�����
	string m_Name; //ְ�����
	int m_DeptId; //ְ�����ڲ��ű��

	

};