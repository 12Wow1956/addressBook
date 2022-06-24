#pragma once
#include <string>
#include "Person.h"

// 记住addressBook（应该叫管理类）的功能：与用户交互；  对通讯录的增删改操作；   文件交互； 

#define MAX 1000
#ifndef addB_H
#define addB_H

class addressBook {
public:
	People PersonArray[MAX];
	int size;

	addressBook();
	addressBook(People* p, int size = 0) {		
		
	}

	void showMenu();

	void addPerson(); // 可以一次完成若干条信息的输入

	void showPerson();  // 显示全部通讯录信息

	void findPersonByName();   // 通过姓名查找

	void deletePersonByName(); // 删除某联系人

	void modifyPersonByName();  // 

	// 清空所有联系人
	void deleteAllPerson();

	void savePerson();  // 文件保存

	void exitPerson();  // 退出通讯录

	~addressBook();
};


#endif // !addB_H
