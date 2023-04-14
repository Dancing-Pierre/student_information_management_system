#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
class Student
{
public:
	string stuNum;         //ѧ��
	string stuName;        //����
	string gender;         //�Ա�
	string  age;              //����
	string department;     //רҵ
	string classNum;          //�༶
	string xi;                      //ϵ��        
	Student()
	{
	}
	Student(string stuNum, string stuName, string gender, int age, string department, int classNum, string xi)
	{
		this->stuNum = stuNum;
		this->stuName = stuName;
		this->gender = gender;
		this->age = age;
		this->department = department;
		this->classNum = classNum;
		this->xi = xi;
	}
	~Student()
	{
	}
	void showStuInfo()
	{
		cout << left << setw(12) << stuNum;
		cout << left << setw(10) << stuName;
		cout << left << setw(6) << gender;
		cout << left << setw(8) << age;
		cout << left << setw(23) << department;
		cout << left << setw(6) << classNum;
		cout << left << setw(12) << xi << endl;
	}
	static void showHeader()
	{
		cout << left << setw(12) << "ѧ��";
		cout << left << setw(10) << "����";
		cout << left << setw(6) << "�Ա�";
		cout << left << setw(8) << "�꼶";
		cout << left << setw(23) << "רҵ";
		cout << left << setw(6) << "�༶";
		cout << left << setw(12) << "ϵ��" << endl;
	}
};
//ѧ���б���
class StudentList
{
private:
	vector<Student> stuList;
public:
	StudentList()
	{
	}
	StudentList(vector<Student> stuList)
	{
		this->stuList = stuList;
	}
	~StudentList()
	{
	}
	//��ʼ��
	void init()
	{
		readFile(); //��ȡ�ļ�
	}
	//���˵�
	void menu()
	{
		string sel = "0";
		system("cls");
		cout << "\t\t\t**********��ӭ����ѧ��ѧ������ϵͳ**********" << endl;
		cout << "\t\t\t����Խ������²���:" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             1   ���ѧ����Ϣ             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             2   ɾ��ѧ����Ϣ             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             3   �޸�ѧ����Ϣ             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             4   ��ѯѧ����Ϣ             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             5   ��ʾ��Ϣ�б�             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             6   ͳ��ѧ������             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             0   �˳�                     |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t��ѡ��0-6����";
		cin >> sel;
		while (sel != "0" && sel != "1" && sel != "2" && sel != "3" && sel != "4" && sel != "5" && sel != "6")
		{
			cout << "\t\t\t���벻�Ϸ�,������ѡ��0-6����";
			cin >> sel;
		}
		if (sel == "1")
		{
			this->insertList();
			this->menu();
		}
		else if (sel == "2")
		{
			this->deleteList();
			this->menu();
		}
		else if (sel == "3")
		{
			this->updateList();
			this->menu();
		}
		else if (sel == "4")
		{
			this->selectList();
			this->menu();
		}
		else if (sel == "5")
		{
			this->displayList();
			this->menu();
		}
		else if (sel == "6")
		{
			this->statisticList();
			this->menu();
		}
		else if (sel == "0")
		{
			exit(0);
		}
	}
	//��ȡ�ļ�
	void readFile()
	{
		ifstream ifs;
		ifs.open("stuList.txt", ios::in);
		int n = 0; //��������ѧ��������ֵ
		ifs >> n;
		for (int i = 0; i < n; i++)
		{
			Student s;
			ifs >> s.stuNum >> s.stuName >> s.gender >> s.age >> s.department >> s.classNum >> s.xi;
		}
		ifs.close();
	}
	//д���ļ�
	void writeFile()
	{
		ofstream ofs;
		ofs.open("stuList.txt", ios::out);
		ofs << stuList.size() << endl; //��д��ѧ������
		for (int i = 0; i < stuList.size(); i++)
		{
			ofs << stuList[i].stuNum << " " << stuList[i].stuName << " " << stuList[i].gender
				<< " " << stuList[i].age << " " << stuList[i].department << " " << stuList[i].classNum
				<< " " << stuList[i].xi << endl;
		}
		ofs.close();
	}
	//���ѧ����Ϣ
	void insertList()
	{
		while (true)
		{
			system("cls");
			cout << "\t\t**********************��ӭ�������ѧ����Ϣ����*************************" << endl;
			cout << "\t\tѧ��������Ϣһ����" << endl;
			displayStu();
			cout << endl;
			cout << "\t\t------------------" << endl;
			cout << "\t\t1 ���ѧ����Ϣ" << endl;
			cout << "\t\t2 �������˵�" << endl;
			cout << "\t\t------------------" << endl;
			cout << "\t\t��ѡ��1-2����";
			string sel;
			cin >> sel;
			while (sel != "1" && sel != "2")
			{
				cout << "\t\t���벻�Ϸ�,���������롾1-2����";
				cin >> sel;
			}
			if (sel == "1")
			{
				string flag = "1";
				while (flag == "1")
				{
					cout << "\t\t����ѧ����Ϣ��" << endl;
					cout << "\t\tѧ�ţ�";
					Student s;
					bool check = false;
					do
					{
						check = false;
						cin >> s.stuNum;
						for (int i = 0; i < stuList.size(); ++i)
						{
							if (s.stuNum == stuList[i].stuNum)
							{
								cout << "\t\t��ѧ���Ѵ��ڣ����������룺";
								check = true;
								break;
							}
						}
					} while (check);
					cout << "\t\t������";
					cin >> s.stuName;
					cout << "\t\t�Ա�";
					cin >> s.gender;
					cout << "\t\t�꼶��";
					cin >> s.age;
					cout << "\t\tרҵ��";
					cin >> s.department;
					cout << "\t\t�༶��";
					cin >> s.classNum;
					cout << "\t\tϵ��";
					cin >> s.xi;
					stuList.push_back(s);
					cout << "\n\t\t����ѧ����Ϣ��ӳɹ����Ƿ������ӣ���1 �� 0 ��" << endl;
					cout << "\t\t�����ѡ��0-1����";
					cin >> flag;
					while (flag != "0" && flag != "1")
					{
						cout << "\t\t���벻�Ϸ�,������ѡ��0-1����";
						cin >> flag;
					}
				}
				writeFile();
				cout << "\t\t";
				system("pause");
			}
			else
			{
				break;
			}
		}
	}
	//ɾ��ѧ����Ϣ
	void deleteList()
	{
		while (true)
		{
			system("cls");
			cout << "\t\t***********************��ӭ����ɾ��ѧ����Ϣ����***********************" << endl;
			string sel = "0";
			cout << "\t\t-----------------" << endl;
			cout << "\t\t1 ��ѧ��ɾ��" << endl;
			cout << "\t\t2 ������ɾ��" << endl;
			cout << "\t\t3 �������˵�" << endl;
			cout << "\t\t-----------------" << endl;
			cout << "\t\t�����ѡ��1-3����";
			cin >> sel;
			while (sel != "1" && sel != "2" && sel != "3")
			{
				cout << "\t\t���벻�Ϸ�,������ѡ��1-3����";
				cin >> sel;
			}
			if (sel == "1")
			{
				string keyNum;
				bool flag = false;
				cout << "\t\t�������ɾ��ѧ����ѧ�ţ�";
				cin >> keyNum;
				for (vector<Student>::iterator it = stuList.begin(); it != stuList.end(); ++it)
				{
					if (it->stuNum == keyNum)
					{
						flag = true;
						cout << "\t\t��ɾ��ѧ������Ϣ���£�" << endl;
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t";
						Student::showHeader();
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t";
						it->showStuInfo();
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\tȷ��ɾ������1 �� 0 ��" << endl;
						cout << "\t\t�����ѡ��0-1����";
						string ch = "0";
						cin >> ch;
						while (ch != "0" && ch != "1")
						{
							cout << "\t\t���벻�Ϸ�,������ѡ��0-1����";
							cin >> ch;
						}
						if (ch == "0") break;
						else
						{
							stuList.erase(it);
							writeFile();
							cout << "\t\tɾ���ɹ���" << endl;
							break;
						}
					}
				}
				if (!flag) cout << "\t\t���޴��ˣ��޷�ɾ����\n" << endl;
				cout << "\t\t";
				system("pause");
			}
			else if (sel == "2")
			{
				string keyName;
				bool flag = false;
				cout << "\t\t�������ɾ��ѧ����������";
				cin >> keyName;
				for (vector<Student>::iterator it = stuList.begin(); it != stuList.end(); ++it)
				{
					if (it->stuName == keyName)
					{
						flag = true;
						cout << "\t\t��ɾ��ѧ������Ϣ���£�" << endl;
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t\t";
						Student::showHeader();
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t";
						it->showStuInfo();
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\tȷ��ɾ������1 �� 0 ��" << endl;
						cout << "\t\t�����ѡ��0-1����";
						string ch = "0";
						cin >> ch;
						while (ch != "0" && ch != "1")
						{
							cout << "\t\t���벻�Ϸ�,������ѡ��0-1����";
							cin >> ch;
						}
						if (ch == "0") break;
						else
						{
							stuList.erase(it);
							writeFile();
							cout << "\t\tɾ���ɹ���" << endl;
							break;
						}
					}
				}
				if (!flag) cout << "\t\t���޴��ˣ��޷�ɾ����\n" << endl;
				cout << "\t\t";
				system("pause");
			}
			else
			{
				break;
			}
		}
	}
	//�޸�ѧ����Ϣ
	void updateList()
	{
		while (true)
		{
			system("cls");
			cout << "\t\t***********************��ӭ�����޸�ѧ����Ϣ����***********************" << endl;
			string sel = "0";
			cout << "\t\t-----------------" << endl;
			cout << "\t\t1 �޸�ѧ��������Ϣ" << endl;
			cout << "\t\t2 �������˵�" << endl;
			cout << "\t\t-----------------" << endl;
			cout << "\t\t�����ѡ��1-2����";
			cin >> sel;
			while (sel != "1" && sel != "2")
			{
				cout << "\t\t���벻�Ϸ�,������ѡ��1-2����";
				cin >> sel;
			}

			if (sel == "1")
			{
				bool flag = false;
				string keyNum;
				cout << "\t\t��������޸�ѧ����ѧ�ţ�";
				cin >> keyNum;
				for (int i = 0; i < stuList.size(); i++)
				{
					if (stuList[i].stuNum == keyNum)
					{
						flag = true;
						cout << "\t\t���޸�ѧ��������Ϣ���£�" << endl;
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t";
						Student::showHeader();
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t";
						stuList[i].showStuInfo();
						cout << "\t\t-----------------------------------------------------------------------" << endl;

						Student s = stuList[i];
						cout << "\t\t�������޸ĺ��ѧ�ţ�";
						bool check = false;
						do
						{
							check = false;
							cin >> s.stuNum;
							for (int j = 0; j < stuList.size(); ++j)
							{
								if (s.stuNum == stuList[j].stuNum && i != j)
								{
									cout << "\t\t��ѧ���ѱ�¼�룬����������ѧ�ţ�";
									check = true;
									break;
								}
							}
						} while (check);
						cout << "\t\t�������޸ĺ��������";
						cin >> s.stuName;
						cout << "\t\t�������޸ĺ���Ա�";
						cin >> s.gender;
						cout << "\t\t�������޸ĺ���꼶��";
						cin >> s.age;
						cout << "\t\t�������޸ĺ��רҵ��";
						cin >> s.department;
						cout << "\t\t�������޸ĺ�İ༶��";
						cin >> s.classNum;
						cout << "\t\t�������޸ĺ��ϵ��";
						cin >> s.xi;
						cout << "\t\t�Ƿ�ȷ���޸ģ���1 �� 0 ��" << endl;
						cout << "\t\t�����ѡ��0-1����";
						string ch = "0";
						cin >> ch;
						while (ch != "0" && ch != "1")
						{
							cout << "\t\t���벻�Ϸ�,������ѡ��0-1����";
							cin >> ch;
						}

						if (ch == "0") break;
						else
						{
							stuList[i] = s;
							cout << "\t\t�޸ĳɹ���" << endl;
							writeFile();
							break;
						}
					}
				}
				if (!flag) cout << "\t\t���޴��ˣ��޷��޸ģ�\n" << endl;
			}
			else
			{
				break;
			}
			cout << "\t\t";
			system("pause");
		}
	}
	//��ѯѧ����Ϣ
	void selectList()
	{
		while (true)
		{
			system("cls");
			cout << "\t\t***********************��ӭ������ѯѧ����Ϣ����************************" << endl;
			cout << "\t\t-----------------" << endl;
			cout << "\t\t1 ��ѧ�Ų�ѯ" << endl;
			cout << "\t\t2 ��������ѯ" << endl;
			cout << "\t\t3 ���Ա��ѯ" << endl;
			cout << "\t\t4 ����Ų�ѯ" << endl;
			cout << "\t\t5 �������˵�" << endl;
			cout << "\t\t-----------------" << endl;
			cout << "\t\t�����ѡ��1-5����";
			string sel = "0";
			cin >> sel;
			while (sel != "1" && sel != "2" && sel != "3" && sel != "4" && sel != "5")
			{
				cout << "\t\t���벻�Ϸ�,������ѡ��1-5����";
				cin >> sel;
			}
			bool flag = false;
			string key;
			if (sel != "5")
			{
				cout << "\t\t���������ѯѧ����";
				if (sel == "1")
					cout << "ѧ�ţ�";
				else if (sel == "2")
					cout << "������";
				else if (sel == "3")
					cout << "�Ա�";
				else if (sel == "4")
					cout << "��ţ�";
				cin >> key;
			}
			for (size_t i = 0; i < stuList.size(); i++)
			{
				Student s = stuList[i];
				if ((sel == "1" && s.stuNum == key) || (sel == "2" && s.stuName == key) || (sel == "3" && s.gender == key) || (sel == "4" && s.classNum == key))
				{
					flag = true;
					cout << "\t\t��ѯ������£�" << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					Student::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					s.showStuInfo();
				}
			}
			if (!flag && sel != "5") cout << "\t\t���޴��ˣ�\n" << endl;
			if (sel == "5") break;
			cout << "\t\t";
			system("pause");
		}
	}

	//����ѧ���б�
	void displayStu()
	{
		cout << "\t\t-----------------------------------------------------------------------" << endl;
		cout << "\t\t";
		Student::showHeader();
		cout << "\t\t-----------------------------------------------------------------------" << endl;
		for (int i = 0; i < stuList.size(); i++)
		{
			cout << "\t\t";
			stuList[i].showStuInfo();
		}
		cout << "\t\t-----------------------------------------------------------------------" << endl;
	}
	//��ʾ��Ϣ�б�
	void displayList()
	{
		system("cls");
		cout << "\t\t***********************��ӭ������ʾ��Ϣ�б���************************" << endl;
		cout << "\t\t��1��ѧ��������Ϣһ����" << endl;
		this->displayStu();
		cout << "\t\t";
		system("pause");
	}
	//ͳ��ѧ������
	void statisticList()
	{
		while (true)
		{
			system("cls");
			cout << "\t\t***********************��ӭ����ͳ��ѧ�����ݹ���************************" << endl;
			string sel = "0";
			cout << "\t\t-----------------" << endl;
			cout << "\t\t1 ���Ա�ͳ��" << endl;
			cout << "\t\t2 �����ͳ��" << endl;
			cout << "\t\t3 ������ͳ��" << endl;
			cout << "\t\t4 ��ϵ��ͳ��" << endl;
			cout << "\t\t5 �������˵�" << endl;
			cout << "\t\t-----------------" << endl;
			cout << "\t\t�����ѡ��1-5����";
			cin >> sel;
			while (sel != "1" && sel != "2" && sel != "3" && sel != "4" && sel != "5")
			{
				cout << "\t\t���벻�Ϸ�,������ѡ��1-5����";
				cin >> sel;
			}
			if (sel == "1")
			{
				string keygender;
				int count = 0;
				cout << "\t\t������ͳ��ѧ�����Ա�";
				cin >> keygender;
				for (size_t i = 0; i < stuList.size(); i++)
				{
					Student s = stuList[i];
					if (s.gender == keygender)
					{
						count++;
					}
				}
				cout << "\t\t�Ա�Ϊ " << keygender << " ��ѧ������ " << count << " ��" << endl;
				cout << "\t\t";
				system("pause");
			}
			else if (sel == "2")
			{
				string keyclass;
				int count = 0;
				cout << "\t\t������ͳ��ѧ���İ�ţ�";
				cin >> keyclass;
				for (size_t i = 0; i < stuList.size(); i++)
				{
					Student s = stuList[i];
					if (s.classNum == keyclass)
					{
						count++;
					}
				}
				cout << "\t\t���Ϊ " << keyclass << " ��ѧ������ " << count << " ��" << endl;
				cout << "\t\t";
				system("pause");
			}
			else if (sel == "3")
			{
				string keyage;
				int count = 0;
				cout << "\t\t���������ѯѧ�������䣺";
				cin >> keyage;
				for (size_t i = 0; i < stuList.size(); i++)
				{
					Student s = stuList[i];
					if (s.age == keyage)
					{
						count++;
					}
				}
				cout << "\t\t����Ϊ " << keyage << " ��ѧ������ " << count << " ��" << endl;
				cout << "\t\t";
				system("pause");
			}
			else if (sel == "4")
			{
				string keyxi;
				int count = 0;
				cout << "\t\t���������ѯѧ����ϵ��";
				cin >> keyxi;
				for (size_t i = 0; i < stuList.size(); i++)
				{
					Student s = stuList[i];
					if (s.xi == keyxi)
					{
						count++;
					}
				}
				cout << "\t\tϵ��Ϊ " << keyxi << " ��ѧ������ " << count << " ��" << endl;
				cout << "\t\t";
				system("pause");
			}
			else if (sel == "5")
			{
				return;
			}
		}
	}
};

int main()
{
	StudentList stuList;
	stuList.init(); //�����ļ����ݳ�ʼ��
	stuList.menu(); //�����˵�
	return 0;
}