#pragma once  //防止头文件重复包含
#include<iostream>
using namespace std;
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"

#include<fstream>
#define FINENAME "empFile.txt"

class WorkerManager
{
public:
	//构造
	WorkerManager();
	//展示菜单
	void showMenu();
	//退出系统
	void exitSystem();
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在 如果存在返回职工所在数组的位置，不存在返回-1
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//按排序编号
	void Sort_Emp();

	//清空文件
	void  Clean_File();



	//析构
	~WorkerManager();

};