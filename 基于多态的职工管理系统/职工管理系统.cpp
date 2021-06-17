#include<iostream>
using namespace std;
#include "workerManager.h"

int main()
{
	//实例化管理者
	WorkerManager wm;

	int choice = 0;
	while (true)
	{
		//调用展示菜单成员函数
		wm.showMenu();
		cout << "请输入你的选择； " << endl;
		cin >> choice;//接受用户的选项

		switch (choice)
		{
		case 0: //退出系统
			wm.exitSystem();

			break;
		case 1: //增加职工
			wm.Add_Emp();

			break;
		case 2: //显示职工
			wm.Show_Emp();
			break;
		case 3: //删除职工
			wm.Del_Emp();
			break;
		case 4: //修改职工
			wm.Mod_Emp();
			break;
		case 5: //查找职工
			wm.Find_Emp();
			break;
		case 6: //排序职工
			wm.Sort_Emp();
			break;
		case 7: //清空文档
			break;
		default:
			system("cls");
			break;
		}
	}



	system("pause");

	return 0;
}
