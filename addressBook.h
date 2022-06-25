#pragma once
#include <string>
#include "Person.h"

// ��סaddressBook��Ӧ�ýй����ࣩ�Ĺ��ܣ����û�������  ��ͨѶ¼����ɾ�Ĳ�����   �ļ������� 

#ifndef addB_H
#define addB_H

class addressBook {
public:
	// ��¼ͨѶ¼Ҫ�������ϵ������
	int size;

	// ��¼ͨѶ¼�б������ϵ�˵�ָ��
	People* addressArray;

	// ���캯��
	addressBook();	

	void showMenu();

	void addPerson(addressBook *); // ����һ�������������Ϣ������

	void showPerson(addressBook*);  // ��ʾȫ��ͨѶ¼��Ϣ

	void findPersonByName(addressBook*);   // ͨ����������

	void deletePersonByName(addressBook*); // ɾ��ĳ��ϵ��

	void modifyPersonByName(addressBook*);  // 

	// ���������ϵ��
	void deleteAllPerson(addressBook*);

	void savePerson();  // �ļ�����

	void exitPerson();  // �˳�ͨѶ¼

	~addressBook();
};


#endif // !addB_H
