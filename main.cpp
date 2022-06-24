#include <iostream>
#include "addressBook.h"
using namespace std;


int main() {
	addressBook mab;
	mab.showMenu();
	unsigned opt = 0;

	cout << "ÇëÑ¡Ôñ£º" << endl;
	cin >> opt;

	while (opt < 7) {
		switch (opt) {
			case 1:
				// mab.addPerson();
				break;
			case 2:
				// mab.showPerson();
				break;
			case 3:
				// mab.deletePersonByName();
				break;
			case 4:
				// mab.findPersonByName();
				break;
			case 5:
				// mab.modifyPersonByName();
				break;
			case 6:
				// mab.deleteAllPerson();
				break;
			case 0:
				 mab.exitPerson();
			default:
				system("cls");
				break;
		}
	}

	system("pause");
	return 0;
}