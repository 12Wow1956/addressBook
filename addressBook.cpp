#include "addressBook.h"


addressBook::addressBook() {

}

void addressBook::showMenu() {
	cout << "*****************************" << endl;
	cout << "**		1.���ͨѶ¼		**" << endl;
	cout << "**		2.��ʾͨѶ¼		**" << endl;
	cout << "**		3.ɾ��ͨѶ¼		**" << endl;
	cout << "**		4.����ͨѶ¼		**" << endl;
	cout << "**		5.�޸�ͨѶ¼		**" << endl;
	cout << "**		6.���ͨѶ¼		**" << endl;
	cout << "**		0.�˳�ͨѶ¼		**" << endl;
	cout << "*****************************" << endl;
}

void addressBook::addPerson() { // ����һ�������������Ϣ������
	
}

void addressBook::showPerson() {  // ��ʾȫ��ͨѶ¼��Ϣ

}
void addressBook::findPersonByName() {   // ͨ����������

}
void addressBook::deletePersonByName() {  // ɾ��ĳ��ϵ��


}
void addressBook::modifyPersonByName() {
}// 


// ɾ��������ϵ��
void addressBook::deleteAllPerson() {

}

void addressBook::savePerson() {  // �ļ�����

}

// �˳�ͨѶ¼
void addressBook::exitPerson() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

addressBook::~addressBook()
{

}
