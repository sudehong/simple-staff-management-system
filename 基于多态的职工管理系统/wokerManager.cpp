#include"workerManager.h"

WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FINENAME, ios::in);
	if (!ifs.is_open()) {
		//cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close() ;
		return;

	}
	//2���ļ�����
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	}
	//3.�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٺ��ļ��е�������������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();

}

//չʾ�˵�
void WorkerManager::showMenu()
{
	cout << "*************************************" << endl;
	cout << "********��ӭʹ��ְ������ϵͳ��*******" << endl;
	cout << "**********0.�˳��������*************" << endl;
	cout << "**********1.����ְ����Ϣ*************" << endl;
	cout << "**********2.��ʾְ����Ϣ*************" << endl;
	cout << "**********3.ɾ����ְְ��*************" << endl;
	cout << "**********4.�޸�ְ����Ϣ*************" << endl;
	cout << "**********5.����ְ����Ϣ*************" << endl;
	cout << "**********6.���ձ������*************" << endl;
	cout << "**********7.��������ĵ�*************" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}


void WorkerManager::exitSystem()
{
	cout << "��ӭ�´���ʹ��" << endl;
	system("pause");
	exit(0); //	�˳�

}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ����ݿ������¿ռ�
		if (this->m_EmpArray != NULL) {
			for (int  i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++) {
			int id = 0;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ��ְ����λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
			case 2:
				worker = new Manager(id, name, 1);
			case 3:
				worker = new Boss(id, name, 1);

			default:
				break;
			}
			//������ְ��ְ�𣬱��浽����
			newSpace[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ���ռ�
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;

		this->m_EmpNum = newSize;

		//�����µ�ְ������
		this->m_FileIsEmpty = false;



		//��ʾ�ɹ�
		cout << "�ɹ����" << addNum<<"��ְ��" << endl;

		//�������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "������������" << endl;
	}
	//�������ص��ϼ�
	system("pause");
	system("cls");

}

//�����ļ�
void WorkerManager::save() {

	ofstream ofs;
	ofs.open(FINENAME, ios::out);//�����ʽ���ļ�

	//��ÿ��������д�뵽�ļ�
	for (int  i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << " "<<endl;
	}

	//�ر��ļ�
	ofs.close();

}


//ͳ���ļ�������
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FINENAME, ios::in);

	int id;
	string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs>>dId) {
		num++;

	}
	return num;
}

//��ʼ��Ա��
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FINENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		 }
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else {
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index++] = worker;

	}
	//�ر��ļ�
	ifs.close();
}

//��ʾְ��
void WorkerManager::Show_Emp() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	//�������������
	system("pause");
	system("cls");

}

//ɾ��ְ��
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;

	}
	else {
		//����ְ�����ɾ��
		cout << "��������Ҫɾ��ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		
		int index = this->IsExist(id);
		if (index != -1) {//ְ�����ڣ�����Ҫɾ��indexλ���ϵ�ְ��
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���������м�¼��Ա����

			//���µ��ļ�
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ���� ������ڷ���ְ�����������λ�ã������ڷ���-1
int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			//�ҵ�ְ��
			index = i;
			return index;
			break;
		}
	} 

return index;

}

//�޸�ְ��
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;

	}
	else {
		cout << "�������޸�ְ����ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1) {
			//���ҵ���ŵ�ְ��
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "�鵽��" << id << "��ְ�����������µ�ְ���ţ�" << endl;
			cin >> newId;
			cout << "�������µ�������" << endl;
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1����ְͨ����" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ壺" << endl;

			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			}

			//�������� ��������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ���" << endl;
			//���浽�ļ���
			this->save();

		}
		else {
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "�밴�ղ��ҵķ�ʽ" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//���ձ�Ų�
			int id;
			cout << "��������ҵ�ְ�����:" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1) {
				//�ҵ�
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();

			}
			else {
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2) {
			//����������
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			//�жϲ��ұ�׼
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id << "��ְ����Ϣ���£�" << endl;

					flag = true;
					//������ʾ��Ϣ�ӿ�
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}

		}
		else {
			cout << "����ѡ������" << endl;
		}



	}

	system("pause");
	system("cls");

}

//��������
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ʽ" << endl;
		cout << "1������ְ���Ž�������" << endl;
		cout << "2������ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++) {
			int minOrMax = i;//������Сֵ
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) {
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
				else {//����
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}

				}


			}
			if (i != minOrMax) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;

			}
			
		}
		cout << "����ɹ���������Ϊ" << endl;
		this->save();//���������ļ�
		this->Show_Emp();//չʾ����ְ��
	}
}

//����ļ�
void  WorkerManager::Clean_File() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		//����ļ�
		ofstream ofs(FINENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i]=NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;

		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");

}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i] != NULL) {
				delete this->m_EmpArray[i];
			}
		}

		delete[] this->m_EmpArray;
	}

}
