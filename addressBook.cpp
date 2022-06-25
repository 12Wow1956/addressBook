#include "addressBook.h"


addressBook::addressBook() {
	this->addressArray = NULL;
	this->size = 0;
}

void addressBook::showMenu() {
	cout << "*****************************" << endl;
	cout << "**		1.添加通讯录		**" << endl;
	cout << "**		2.显示通讯录		**" << endl;
	cout << "**		3.删除通讯录		**" << endl;
	cout << "**		4.查找通讯录		**" << endl;
	cout << "**		5.修改通讯录		**" << endl;
	cout << "**		6.清空通讯录		**" << endl;
	cout << "**		0.退出通讯录		**" << endl;
	cout << "*****************************" << endl;
}

void addressBook::addPerson(addressBook *pmab) { // 可以一次完成若干条信息的输入
	cout << "你想输入几个联系人？" << endl;
	int addCnt = 0;
	cin >> addCnt;

	// 需要为这些联系人开辟数组空间:	 
	
	if (addCnt > 0) {
		// 输入的联系人人数为有效值时再应该继续操作：
		int newSize = this->size + addCnt;  // 新空间人数 = 原来人数 + 新增人数

		// 开辟新空间人数这样大的数组空间
		People* newSpace = new People[newSize]; // new之后的意思是开辟newSize个People的大小，前面代表用People*来保存

		// 查看原来通讯录中是否有内容，有的话拷贝到新空间
		if (addressArray != NULL) {
			for (int i = 0; i < this->size; ++i) {
				newSpace[i] = this->addressArray[i];
			}
		}

		// 然后在新空间中加入批量添加的数据
		for (int i = 0; i < addCnt; ++i) {
			string aname, acompany, afixTel, amobTel, asort, aemail, aqq;
			
			cout << "请输入第" << i + 1 << "个联系人的姓名：" << endl;
			cin >> aname;
			newSpace[this->size + i].name = aname;

			cout << "请输入第" << i + 1 << "个联系人所在的公司：" << endl;
			cin >> acompany;
			newSpace[this->size + i].company = acompany;

			cout << "请输入第" << i + 1 << "个联系人的固定电话：" << endl;
			cin >> afixTel;
			newSpace[this->size + i].fixTel = afixTel;

			cout << "请输入第" << i + 1 << "个联系人的移动电话：" << endl;
			cin >> amobTel;
			newSpace[this->size + i].mobTel = amobTel;

			cout << "请输入第" << i + 1 << "个联系人的分类：" << endl;
			cout << "1、同事；" << endl;
			cout << "2、朋友；" << endl;
			cout << "3、同学；" << endl;
			cout << "4、家人；" << endl;
			int sel = 0;
			while (true) {
				cin >> sel;
				if (sel == 1 || sel == 2 || sel == 3 || sel == 4) {
					switch (sel)
					{
					case 1:
						asort = "同事";
						break;
					case 2:
						asort = "朋友";
						break;
					case 3:
						asort = "同学";
						break;
					case 4:
						asort = "家人";
						break;
					default:
						break;
					}
					break;
				}
				else {
					cout << "输入有误，请重新输入！" << endl;
				}
			}
			newSpace[this->size + i].sort = asort;

			cout << "请输入第" << i + 1 << "个联系人的Email：" << endl;
			cin >> aemail;
			newSpace[this->size + i].email = aemail;

			cout << "请输入第" << i + 1 << "个联系人的QQ：" << endl;
			cin >> aqq;
			newSpace[this->size + i].qq = aqq;

		}
		// 更新通讯录人数
		this->size = newSize;
		cout << "成功添加" << addCnt << "名联系人！" << endl;

		// 释放原空间
		delete[] this->addressArray;
		this->addressArray = newSpace;
	}
	else {
		cout << "输入有误！" << endl;
	}

	system("pause");
	system("cls");
}

void addressBook::showPerson(addressBook* pmab) {  // 显示全部通讯录信息
	if (pmab->size != 0) {
		for (int i = 0; i < pmab->size; ++i) {
			cout << "姓名： " << pmab->addressArray[i].name << "\t"
				<< "所在公司： " << pmab->addressArray[i].company << "\t"
				<< "固定电话： " << pmab->addressArray[i].fixTel << "\t"
				<< "移动电话： " << pmab->addressArray[i].mobTel << "\t"
				<< "分类： " << pmab->addressArray[i].sort << "\t"
				<< "Email: " << pmab->addressArray[i].email << "\t"
				<< "QQ: " << pmab->addressArray[i].qq << endl;
		}
	}
	else {
		cout << "通讯录为空！" << endl;
	}

	system("pause");
	system("cls");
}
void addressBook::findPersonByName(addressBook* pmab) {   // 通过姓名查找
	cout << "请输入你想查找的联系人姓名：" << endl;
	string aname;
	cin >> aname;
	
	bool flag = false;
	int num = 0;
	if (pmab->size != 0) {
		for (int i = 0; i < pmab->size; ++i) {
			if (pmab->addressArray[i].name == aname) {
				flag = true;
				num = i;
			}
		}		
	}

	if (flag) {
		cout << "姓名： " << pmab->addressArray[num].name << "\t"
			<< "所在公司： " << pmab->addressArray[num].company << "\t"
			<< "固定电话： " << pmab->addressArray[num].fixTel << "\t"
			<< "移动电话： " << pmab->addressArray[num].mobTel << "\t"
			<< "分类： " << pmab->addressArray[num].sort << "\t"
			<< "Email: " << pmab->addressArray[num].email << "\t"
			<< "QQ: " << pmab->addressArray[num].qq << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}
void addressBook::deletePersonByName(addressBook* pmab) {  // 删除某联系人
	cout << "请输入你想删除的联系人姓名：" << endl;
	string aname;
	cin >> aname;

	bool flag = false;
	int num = 0;
	if (pmab->size != 0) {
		for (int i = 0; i < pmab->size; ++i) {
			if (pmab->addressArray[i].name == aname) {
				flag = true;
				num = i;
			}
		}
	}

	if (flag) {
		for (int i = num + 1; i < pmab->size; ++i) {
			pmab->addressArray[i - 1] = pmab->addressArray[i];
		}

		cout << "已删除！" << endl;
	}
	else {
		cout << "查无此人！无法删除" << endl;
	}

	system("pause");
	system("cls");
}
void addressBook::modifyPersonByName(addressBook* pmab) {
	cout << "请输入你想修改的联系人姓名：" << endl;
	string aname;
	cin >> aname;
	bool flag = false;

	if (pmab->size != 0) {
		for (int i = 0; i < pmab->size; ++i) {
			if (pmab->addressArray[i].name == aname) {
				cout << "请输入修改后的联系人姓名： " << endl;
				string aname;
				cin >> aname;
				pmab->addressArray[i].name = aname;

				cout << "请输入修改后的联系人所在公司： " << endl;
				string acompany;
				cin >> acompany;
				pmab->addressArray[i].company = acompany;

				cout << "请输入修改后的联系人固定电话： " << endl;
				string afixTel;
				cin >> afixTel;
				pmab->addressArray[i].fixTel = afixTel;

				cout << "请输入修改后的联系人移动电话： " << endl;
				string amobTel;
				cin >> amobTel;
				pmab->addressArray[i].mobTel = amobTel;

				cout << "请输入修改后的联系人类别" << endl;
				cout << "1、同事；" << endl;
				cout << "2、朋友；" << endl;
				cout << "3、同学；" << endl;
				cout << "4、家人；" << endl;
				string asort;
				int sel = 0;
				while (true) {
					cin >> sel;
					if (sel == 1 || sel == 2 || sel == 3 || sel == 4) {
						switch (sel)
						{
						case 1:
							asort = "同事";
							break;
						case 2:
							asort = "朋友";
							break;
						case 3:
							asort = "同学";
							break;
						case 4:
							asort = "家人";
							break;
						default:
							break;
						}
						break;
					}
					else {
						cout << "输入有误，请重新输入！" << endl;
					}
				}
				pmab->addressArray[i].sort = asort;

				cout << "请输入修改后的联系人Email： " << endl;
				string aemail;
				cin >> aemail;
				pmab->addressArray[i].email = aemail;

				cout << "请输入修改后的联系人QQ： " << endl;
				string aqq;
				cin >> aqq;
				pmab->addressArray[i].qq = aqq;

				cout << "修改成功！" << endl;
				flag = true;
			}
		}
	}	
	if (!flag)
		cout << "查无此人！ 修改失败" << endl;

	system("pause");
	system("cls");
}


// 删除所有联系人
void addressBook::deleteAllPerson(addressBook* pmab) {

	char sel;
	cout << "Are you sure ?(Y/N)" << endl;
	cin >> sel;
	if (sel == 'Y' || sel == 'y') {
		// 逻辑上删除
		//pmab->addressArray == nullptr;
		pmab->size = 0;

		cout << "删除成功！" << endl;
	}
	else {
		cout << "删除失败！" << endl;
	}

	system("pause");
	system("cls");	
}

void addressBook::savePerson() {  // 文件保存

}

// 退出通讯录
void addressBook::exitPerson() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

addressBook::~addressBook()
{

}
