#pragma once
#include <string>
#include "Person.h"

// ��סaddressBook��Ӧ�ýй����ࣩ�Ĺ��ܣ����û�������  ��ͨѶ¼����ɾ�Ĳ�����   �ļ������� 

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

	void addPerson(); // ����һ�������������Ϣ������

	void showPerson();  // ��ʾȫ��ͨѶ¼��Ϣ

	void findPersonByName();   // ͨ����������

	void deletePersonByName(); // ɾ��ĳ��ϵ��

	void modifyPersonByName();  // 

	// ���������ϵ��
	void deleteAllPerson();

	void savePerson();  // �ļ�����

	void exitPerson();  // �˳�ͨѶ¼

	~addressBook();
};


#endif // !addB_H
