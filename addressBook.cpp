#include "addressBook.h"


addressBook::addressBook() {

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

void addressBook::addPerson() { // 可以一次完成若干条信息的输入
	
}

void addressBook::showPerson() {  // 显示全部通讯录信息

}
void addressBook::findPersonByName() {   // 通过姓名查找

}
void addressBook::deletePersonByName() {  // 删除某联系人


}
void addressBook::modifyPersonByName() {
}// 


// 删除所有联系人
void addressBook::deleteAllPerson() {

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
