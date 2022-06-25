#pragma once
#include <string>
#include "Person.h"

// 记住addressBook（应该叫管理类）的功能：与用户交互；  对通讯录的增删改操作；   文件交互； 

#ifndef addB_H
#define addB_H

class addressBook {
public:
	// 记录通讯录要保存的联系人人数
	int size;

	// 记录通讯录中保存的联系人的指针
	People* addressArray;

	// 构造函数
	addressBook();	

	void showMenu();

	void addPerson(addressBook *); // 可以一次完成若干条信息的输入

	void showPerson(addressBook*);  // 显示全部通讯录信息

	void findPersonByName(addressBook*);   // 通过姓名查找

	void deletePersonByName(addressBook*); // 删除某联系人

	void modifyPersonByName(addressBook*);  // 

	// 清空所有联系人
	void deleteAllPerson(addressBook*);

	void savePerson();  // 文件保存

	void exitPerson();  // 退出通讯录

	~addressBook();
};


#endif // !addB_H
