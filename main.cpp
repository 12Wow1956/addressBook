#include <iostream>
#include "addressBook.h"
using namespace std;


int main() {
	addressBook mab;	
	unsigned opt = 0;	

	while (opt < 7) {
		mab.showMenu();
		cout << "��ѡ��";
		cin >> opt;
		switch (opt) {
			case 1:
				// ����ĺ�������ʹ�ÿ�ʵ�֣�����ǿ�ʵ��ֻ�ǻ���ִ�д���ʱ�����޷�ʶ���main.obj
				 mab.addPerson(&mab);
				break;
			case 2:
				 mab.showPerson(&mab);
				break;
			case 3:
				 mab.deletePersonByName(&mab);
				break;
			case 4:
				 mab.findPersonByName(&mab);
				break;
			case 5:
				 mab.modifyPersonByName(&mab);
				break;
			case 6:
				 mab.deleteAllPerson(&mab);
				break;
			case 0:
				 mab.exitPerson();
				 break;
			default:
				system("cls");
				break;
		}
	}

	system("pause");
	return 0;
}