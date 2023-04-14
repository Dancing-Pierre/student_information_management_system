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
	string stuNum;         //学号
	string stuName;        //姓名
	string gender;         //性别
	string  age;              //年龄
	string department;     //专业
	string classNum;          //班级
	string xi;                      //系别        
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
		cout << left << setw(12) << "学号";
		cout << left << setw(10) << "姓名";
		cout << left << setw(6) << "性别";
		cout << left << setw(8) << "年级";
		cout << left << setw(23) << "专业";
		cout << left << setw(6) << "班级";
		cout << left << setw(12) << "系别" << endl;
	}
};
//学生列表类
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
	//初始化
	void init()
	{
		readFile(); //读取文件
	}
	//主菜单
	void menu()
	{
		string sel = "0";
		system("cls");
		cout << "\t\t\t**********欢迎来到学生学籍管理系统**********" << endl;
		cout << "\t\t\t你可以进行以下操作:" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             1   添加学生信息             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             2   删除学生信息             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             3   修改学生信息             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             4   查询学生信息             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             5   显示信息列表             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             6   统计学生数据             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             0   退出                     |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t请选择【0-6】：";
		cin >> sel;
		while (sel != "0" && sel != "1" && sel != "2" && sel != "3" && sel != "4" && sel != "5" && sel != "6")
		{
			cout << "\t\t\t输入不合法,请重新选择【0-6】：";
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
	//读取文件
	void readFile()
	{
		ifstream ifs;
		ifs.open("stuList.txt", ios::in);
		int n = 0; //用来接收学生数量的值
		ifs >> n;
		for (int i = 0; i < n; i++)
		{
			Student s;
			ifs >> s.stuNum >> s.stuName >> s.gender >> s.age >> s.department >> s.classNum >> s.xi;
		}
		ifs.close();
	}
	//写入文件
	void writeFile()
	{
		ofstream ofs;
		ofs.open("stuList.txt", ios::out);
		ofs << stuList.size() << endl; //先写入学生数量
		for (int i = 0; i < stuList.size(); i++)
		{
			ofs << stuList[i].stuNum << " " << stuList[i].stuName << " " << stuList[i].gender
				<< " " << stuList[i].age << " " << stuList[i].department << " " << stuList[i].classNum
				<< " " << stuList[i].xi << endl;
		}
		ofs.close();
	}
	//添加学生信息
	void insertList()
	{
		while (true)
		{
			system("cls");
			cout << "\t\t**********************欢迎来到添加学生信息功能*************************" << endl;
			cout << "\t\t学生基本信息一览表：" << endl;
			displayStu();
			cout << endl;
			cout << "\t\t------------------" << endl;
			cout << "\t\t1 添加学生信息" << endl;
			cout << "\t\t2 返回主菜单" << endl;
			cout << "\t\t------------------" << endl;
			cout << "\t\t请选择【1-2】：";
			string sel;
			cin >> sel;
			while (sel != "1" && sel != "2")
			{
				cout << "\t\t输入不合法,请重新输入【1-2】：";
				cin >> sel;
			}
			if (sel == "1")
			{
				string flag = "1";
				while (flag == "1")
				{
					cout << "\t\t输入学生信息：" << endl;
					cout << "\t\t学号：";
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
								cout << "\t\t该学号已存在，请重新输入：";
								check = true;
								break;
							}
						}
					} while (check);
					cout << "\t\t姓名：";
					cin >> s.stuName;
					cout << "\t\t性别：";
					cin >> s.gender;
					cout << "\t\t年级：";
					cin >> s.age;
					cout << "\t\t专业：";
					cin >> s.department;
					cout << "\t\t班级：";
					cin >> s.classNum;
					cout << "\t\t系别：";
					cin >> s.xi;
					stuList.push_back(s);
					cout << "\n\t\t该名学生信息添加成功！是否继续添加？（1 是 0 否）" << endl;
					cout << "\t\t请进行选择【0-1】：";
					cin >> flag;
					while (flag != "0" && flag != "1")
					{
						cout << "\t\t输入不合法,请重新选择【0-1】：";
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
	//删除学生信息
	void deleteList()
	{
		while (true)
		{
			system("cls");
			cout << "\t\t***********************欢迎来到删除学生信息功能***********************" << endl;
			string sel = "0";
			cout << "\t\t-----------------" << endl;
			cout << "\t\t1 按学号删除" << endl;
			cout << "\t\t2 按姓名删除" << endl;
			cout << "\t\t3 返回主菜单" << endl;
			cout << "\t\t-----------------" << endl;
			cout << "\t\t请进行选择【1-3】：";
			cin >> sel;
			while (sel != "1" && sel != "2" && sel != "3")
			{
				cout << "\t\t输入不合法,请重新选择【1-3】：";
				cin >> sel;
			}
			if (sel == "1")
			{
				string keyNum;
				bool flag = false;
				cout << "\t\t请输入待删除学生的学号：";
				cin >> keyNum;
				for (vector<Student>::iterator it = stuList.begin(); it != stuList.end(); ++it)
				{
					if (it->stuNum == keyNum)
					{
						flag = true;
						cout << "\t\t待删除学生的信息如下：" << endl;
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t";
						Student::showHeader();
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t";
						it->showStuInfo();
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t确认删除？（1 是 0 否）" << endl;
						cout << "\t\t请进行选择【0-1】：";
						string ch = "0";
						cin >> ch;
						while (ch != "0" && ch != "1")
						{
							cout << "\t\t输入不合法,请重新选择【0-1】：";
							cin >> ch;
						}
						if (ch == "0") break;
						else
						{
							stuList.erase(it);
							writeFile();
							cout << "\t\t删除成功！" << endl;
							break;
						}
					}
				}
				if (!flag) cout << "\t\t查无此人，无法删除！\n" << endl;
				cout << "\t\t";
				system("pause");
			}
			else if (sel == "2")
			{
				string keyName;
				bool flag = false;
				cout << "\t\t请输入待删除学生的姓名：";
				cin >> keyName;
				for (vector<Student>::iterator it = stuList.begin(); it != stuList.end(); ++it)
				{
					if (it->stuName == keyName)
					{
						flag = true;
						cout << "\t\t待删除学生的信息如下：" << endl;
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t\t";
						Student::showHeader();
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t";
						it->showStuInfo();
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t确认删除？（1 是 0 否）" << endl;
						cout << "\t\t请进行选择【0-1】：";
						string ch = "0";
						cin >> ch;
						while (ch != "0" && ch != "1")
						{
							cout << "\t\t输入不合法,请重新选择【0-1】：";
							cin >> ch;
						}
						if (ch == "0") break;
						else
						{
							stuList.erase(it);
							writeFile();
							cout << "\t\t删除成功！" << endl;
							break;
						}
					}
				}
				if (!flag) cout << "\t\t查无此人，无法删除！\n" << endl;
				cout << "\t\t";
				system("pause");
			}
			else
			{
				break;
			}
		}
	}
	//修改学生信息
	void updateList()
	{
		while (true)
		{
			system("cls");
			cout << "\t\t***********************欢迎来到修改学生信息功能***********************" << endl;
			string sel = "0";
			cout << "\t\t-----------------" << endl;
			cout << "\t\t1 修改学生基本信息" << endl;
			cout << "\t\t2 返回主菜单" << endl;
			cout << "\t\t-----------------" << endl;
			cout << "\t\t请进行选择【1-2】：";
			cin >> sel;
			while (sel != "1" && sel != "2")
			{
				cout << "\t\t输入不合法,请重新选择【1-2】：";
				cin >> sel;
			}

			if (sel == "1")
			{
				bool flag = false;
				string keyNum;
				cout << "\t\t请输入待修改学生的学号：";
				cin >> keyNum;
				for (int i = 0; i < stuList.size(); i++)
				{
					if (stuList[i].stuNum == keyNum)
					{
						flag = true;
						cout << "\t\t待修改学生基本信息如下：" << endl;
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t";
						Student::showHeader();
						cout << "\t\t-----------------------------------------------------------------------" << endl;
						cout << "\t\t";
						stuList[i].showStuInfo();
						cout << "\t\t-----------------------------------------------------------------------" << endl;

						Student s = stuList[i];
						cout << "\t\t请输入修改后的学号：";
						bool check = false;
						do
						{
							check = false;
							cin >> s.stuNum;
							for (int j = 0; j < stuList.size(); ++j)
							{
								if (s.stuNum == stuList[j].stuNum && i != j)
								{
									cout << "\t\t该学号已被录入，请重新输入学号：";
									check = true;
									break;
								}
							}
						} while (check);
						cout << "\t\t请输入修改后的姓名：";
						cin >> s.stuName;
						cout << "\t\t请输入修改后的性别：";
						cin >> s.gender;
						cout << "\t\t请输入修改后的年级：";
						cin >> s.age;
						cout << "\t\t请输入修改后的专业：";
						cin >> s.department;
						cout << "\t\t请输入修改后的班级：";
						cin >> s.classNum;
						cout << "\t\t请输入修改后的系别：";
						cin >> s.xi;
						cout << "\t\t是否确认修改？（1 是 0 否）" << endl;
						cout << "\t\t请进行选择【0-1】：";
						string ch = "0";
						cin >> ch;
						while (ch != "0" && ch != "1")
						{
							cout << "\t\t输入不合法,请重新选择【0-1】：";
							cin >> ch;
						}

						if (ch == "0") break;
						else
						{
							stuList[i] = s;
							cout << "\t\t修改成功！" << endl;
							writeFile();
							break;
						}
					}
				}
				if (!flag) cout << "\t\t查无此人，无法修改！\n" << endl;
			}
			else
			{
				break;
			}
			cout << "\t\t";
			system("pause");
		}
	}
	//查询学生信息
	void selectList()
	{
		while (true)
		{
			system("cls");
			cout << "\t\t***********************欢迎来到查询学生信息功能************************" << endl;
			cout << "\t\t-----------------" << endl;
			cout << "\t\t1 按学号查询" << endl;
			cout << "\t\t2 按姓名查询" << endl;
			cout << "\t\t3 按性别查询" << endl;
			cout << "\t\t4 按班号查询" << endl;
			cout << "\t\t5 返回主菜单" << endl;
			cout << "\t\t-----------------" << endl;
			cout << "\t\t请进行选择【1-5】：";
			string sel = "0";
			cin >> sel;
			while (sel != "1" && sel != "2" && sel != "3" && sel != "4" && sel != "5")
			{
				cout << "\t\t输入不合法,请重新选择【1-5】：";
				cin >> sel;
			}
			bool flag = false;
			string key;
			if (sel != "5")
			{
				cout << "\t\t请输入待查询学生的";
				if (sel == "1")
					cout << "学号：";
				else if (sel == "2")
					cout << "姓名：";
				else if (sel == "3")
					cout << "性别：";
				else if (sel == "4")
					cout << "班号：";
				cin >> key;
			}
			for (size_t i = 0; i < stuList.size(); i++)
			{
				Student s = stuList[i];
				if ((sel == "1" && s.stuNum == key) || (sel == "2" && s.stuName == key) || (sel == "3" && s.gender == key) || (sel == "4" && s.classNum == key))
				{
					flag = true;
					cout << "\t\t查询结果如下：" << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					Student::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					s.showStuInfo();
				}
			}
			if (!flag && sel != "5") cout << "\t\t查无此人！\n" << endl;
			if (sel == "5") break;
			cout << "\t\t";
			system("pause");
		}
	}

	//遍历学生列表
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
	//显示信息列表
	void displayList()
	{
		system("cls");
		cout << "\t\t***********************欢迎来到显示信息列表功能************************" << endl;
		cout << "\t\t表1：学生基本信息一览表" << endl;
		this->displayStu();
		cout << "\t\t";
		system("pause");
	}
	//统计学生数据
	void statisticList()
	{
		while (true)
		{
			system("cls");
			cout << "\t\t***********************欢迎来到统计学生数据功能************************" << endl;
			string sel = "0";
			cout << "\t\t-----------------" << endl;
			cout << "\t\t1 按性别统计" << endl;
			cout << "\t\t2 按班号统计" << endl;
			cout << "\t\t3 按年龄统计" << endl;
			cout << "\t\t4 按系别统计" << endl;
			cout << "\t\t5 返回主菜单" << endl;
			cout << "\t\t-----------------" << endl;
			cout << "\t\t请进行选择【1-5】：";
			cin >> sel;
			while (sel != "1" && sel != "2" && sel != "3" && sel != "4" && sel != "5")
			{
				cout << "\t\t输入不合法,请重新选择【1-5】：";
				cin >> sel;
			}
			if (sel == "1")
			{
				string keygender;
				int count = 0;
				cout << "\t\t请输入统计学生的性别：";
				cin >> keygender;
				for (size_t i = 0; i < stuList.size(); i++)
				{
					Student s = stuList[i];
					if (s.gender == keygender)
					{
						count++;
					}
				}
				cout << "\t\t性别为 " << keygender << " 的学生共有 " << count << " 人" << endl;
				cout << "\t\t";
				system("pause");
			}
			else if (sel == "2")
			{
				string keyclass;
				int count = 0;
				cout << "\t\t请输入统计学生的班号：";
				cin >> keyclass;
				for (size_t i = 0; i < stuList.size(); i++)
				{
					Student s = stuList[i];
					if (s.classNum == keyclass)
					{
						count++;
					}
				}
				cout << "\t\t班号为 " << keyclass << " 的学生共有 " << count << " 人" << endl;
				cout << "\t\t";
				system("pause");
			}
			else if (sel == "3")
			{
				string keyage;
				int count = 0;
				cout << "\t\t请输入待查询学生的年龄：";
				cin >> keyage;
				for (size_t i = 0; i < stuList.size(); i++)
				{
					Student s = stuList[i];
					if (s.age == keyage)
					{
						count++;
					}
				}
				cout << "\t\t年龄为 " << keyage << " 的学生共有 " << count << " 人" << endl;
				cout << "\t\t";
				system("pause");
			}
			else if (sel == "4")
			{
				string keyxi;
				int count = 0;
				cout << "\t\t请输入待查询学生的系别：";
				cin >> keyxi;
				for (size_t i = 0; i < stuList.size(); i++)
				{
					Student s = stuList[i];
					if (s.xi == keyxi)
					{
						count++;
					}
				}
				cout << "\t\t系别为 " << keyxi << " 的学生共有 " << count << " 人" << endl;
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
	stuList.init(); //读入文件数据初始化
	stuList.menu(); //打开主菜单
	return 0;
}