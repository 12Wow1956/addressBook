#pragma once
#include <string>
#include "Person.h"
#include <fstream>
#define FILENAME "addressBookFile.txt"

// ��סaddressBook��Ӧ�ýй����ࣩ�Ĺ��ܣ����û�������  ��ͨѶ¼����ɾ�Ĳ�����   �ļ������� 

#ifndef addB_H
#define addB_H

class addressBook {
public:
	// ��¼ͨѶ¼Ҫ�������ϵ������
	int size;

	// �ļ��е������м��У����м�����ϵ��
	int addressFileNum();

	// ��¼ͨѶ¼�б������ϵ�˵�ָ��
	People* addressArray;


	// ��һ���������ж��ļ����Ƿ�Ϊ��
	bool isFileEmpty;

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

	// �ļ�����
	void savePerson();  

	void exitPerson();  // �˳�ͨѶ¼

	~addressBook();
};


#endif // !addB_H
