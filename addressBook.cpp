#include "addressBook.h"


addressBook::addressBook() {

	// ��ʼ�������ټ򵥵ĳ�ʼ������Ҫ�����ļ��ˣ�����������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  // �Զ��ķ�ʽ�����ļ�

	// 1���ļ�������
	if (!ifs.is_open()) {  // ��is_open()�������ж��Ƿ��ܹ��򿪳ɹ�
		cout << "�ļ������ڣ�" << endl;
		this->addressArray = NULL;
		this->size = 0;
		this->isFileEmpty = true; // �ļ�����Ϊ��
		ifs.close();
		return;
	}	

	// 2�� �ļ����ڵ������ݱ��û����
	char ch;
	ifs >> ch; // ��ȡһ���ַ����ж��ļ��Ƿ�������
	if (ifs.eof()) { // �������������ȡ�����һ���ַ�˵����û���ַ�
		cout << "�ļ�Ϊ�գ�" << endl;
		this->addressArray = NULL;
		this->size = 0;
		this->isFileEmpty = true; // �ļ�����Ϊ��
		ifs.close();
		return;
	}

	// 3���ļ����������б������ݣ���Ҫ�����е������ûص�������
	/*char chch;
	ifs >> chch;
	if (ifs.is_open() && !ifs.eof()) {*/

		//cout << "�ļ���������" << this->addressFileNum() << endl;
		this->size = this->addressFileNum(); // ��ʼ���ļ��е�����
		

		// �ȿ��ٶ����ռ�: �տ�ʼ��ʱ�������������Ҫ����´�Ӧ��ע��ע�⣡������������������������������������1
		this->addressArray = new People[this->size];

		string aname, acompany, afixTel, amobTel, asort, aemail, aqq;
		// ���ļ��ж�ȡÿ�������������Ǳ��浽��ϵ�������ڵ�������
		for (int i = 0; i < this->size; ++i) {
			ifs >> aname && ifs >> acompany && ifs >> afixTel && ifs >> amobTel && ifs >> asort && ifs >> aemail && ifs >> aqq;
			this->addressArray[i].name = aname;
			this->addressArray[i].company = acompany;
			this->addressArray[i].fixTel = afixTel;
			this->addressArray[i].mobTel = amobTel;
			this->addressArray[i].sort = asort;
			this->addressArray[i].email = aemail;
			this->addressArray[i].qq = aqq;
		}

		ifs.close();
	
}

// �ļ��е������м��У����м�����ϵ��
int addressBook::addressFileNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	string aname, acompany, afixTel, amobTel, asort, aemail, aqq;
	int num = 0;

	while (ifs >> aname && ifs >> acompany && ifs >> afixTel && ifs >> amobTel && ifs >> asort && ifs >> aemail && ifs >> aqq) {
		num++;
	}

	ifs.close();
	return num;
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

void addressBook::addPerson(addressBook *pmab) { // ����һ�������������Ϣ������
	cout << "�������뼸����ϵ�ˣ�" << endl;
	int addCnt = 0;
	cin >> addCnt;

	// ��ҪΪ��Щ��ϵ�˿�������ռ�:	 
	
	if (addCnt > 0) {
		// �������ϵ������Ϊ��Чֵʱ��Ӧ�ü���������
		int newSize = this->size + addCnt;  // �¿ռ����� = ԭ������ + ��������

		// �����¿ռ����������������ռ�
		People* newSpace = new People[newSize]; // new֮�����˼�ǿ���newSize��People�Ĵ�С��ǰ�������People*������

		// �鿴ԭ��ͨѶ¼���Ƿ������ݣ��еĻ��������¿ռ�
		if (addressArray != NULL) {
			for (int i = 0; i < this->size; ++i) {
				newSpace[i] = this->addressArray[i];
			}
		}

		// Ȼ�����¿ռ��м���������ӵ�����
		for (int i = 0; i < addCnt; ++i) {
			string aname, acompany, afixTel, amobTel, asort, aemail, aqq;
			
			cout << "�������" << i + 1 << "����ϵ�˵�������" << endl;
			cin >> aname;
			newSpace[this->size + i].name = aname;

			cout << "�������" << i + 1 << "����ϵ�����ڵĹ�˾��" << endl;
			cin >> acompany;
			newSpace[this->size + i].company = acompany;

			cout << "�������" << i + 1 << "����ϵ�˵Ĺ̶��绰��" << endl;
			cin >> afixTel;
			newSpace[this->size + i].fixTel = afixTel;

			cout << "�������" << i + 1 << "����ϵ�˵��ƶ��绰��" << endl;
			cin >> amobTel;
			newSpace[this->size + i].mobTel = amobTel;

			cout << "�������" << i + 1 << "����ϵ�˵ķ��ࣺ" << endl;
			cout << "1��ͬ�£�" << endl;
			cout << "2�����ѣ�" << endl;
			cout << "3��ͬѧ��" << endl;
			cout << "4�����ˣ�" << endl;
			int sel = 0;
			while (true) {
				cin >> sel;
				if (sel == 1 || sel == 2 || sel == 3 || sel == 4) {
					switch (sel)
					{
					case 1:
						asort = "ͬ��";
						break;
					case 2:
						asort = "����";
						break;
					case 3:
						asort = "ͬѧ";
						break;
					case 4:
						asort = "����";
						break;
					default:
						break;
					}
					break;
				}
				else {
					cout << "�����������������룡" << endl;
				}
			}
			newSpace[this->size + i].sort = asort;

			cout << "�������" << i + 1 << "����ϵ�˵�Email��" << endl;
			cin >> aemail;
			newSpace[this->size + i].email = aemail;

			cout << "�������" << i + 1 << "����ϵ�˵�QQ��" << endl;
			cin >> aqq;
			newSpace[this->size + i].qq = aqq;

		}
		// ����ͨѶ¼����
		this->size = newSize;

		this->isFileEmpty = false;

		cout << "�ɹ����" << addCnt << "����ϵ�ˣ�" << endl;		

		// �ͷ�ԭ�ռ�
		delete[] this->addressArray;
		this->addressArray = newSpace;


		// �������⣺ �ú����ĵ��ñ������ͷ�ԭ�ռ��Ժ��������ִ��
		// �����ˣ� �Ϸ����д��벻ֻ���ͷ�ԭ�ռ䣬���н����б�����������ݵ�ָ��ָ��ÿ�θ����Ժ����ȷλ�òſ��ԣ����ͣ�
		// ��������� savePerson������ϵ�˵� ����
		this->savePerson();
	}
	else {
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

void addressBook::showPerson(addressBook* pmab) {  // ��ʾȫ��ͨѶ¼��Ϣ
	if (pmab->size != 0) {
		for (int i = 0; i < pmab->size; ++i) {
			cout << "������ " << pmab->addressArray[i].name << "\t"
				<< "���ڹ�˾�� " << pmab->addressArray[i].company << "\t"
				<< "�̶��绰�� " << pmab->addressArray[i].fixTel << "\t"
				<< "�ƶ��绰�� " << pmab->addressArray[i].mobTel << "\t"
				<< "���ࣺ " << pmab->addressArray[i].sort << "\t"
				<< "Email: " << pmab->addressArray[i].email << "\t"
				<< "QQ: " << pmab->addressArray[i].qq << endl;
		}
	}
	else {
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}

	system("pause");
	system("cls");
}
void addressBook::findPersonByName(addressBook* pmab) {   // ͨ����������
	cout << "������������ҵ���ϵ��������" << endl;
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
		cout << "������ " << pmab->addressArray[num].name << "\t"
			<< "���ڹ�˾�� " << pmab->addressArray[num].company << "\t"
			<< "�̶��绰�� " << pmab->addressArray[num].fixTel << "\t"
			<< "�ƶ��绰�� " << pmab->addressArray[num].mobTel << "\t"
			<< "���ࣺ " << pmab->addressArray[num].sort << "\t"
			<< "Email: " << pmab->addressArray[num].email << "\t"
			<< "QQ: " << pmab->addressArray[num].qq << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}
void addressBook::deletePersonByName(addressBook* pmab) {  // ɾ��ĳ��ϵ��
	cout << "����������ɾ������ϵ��������" << endl;
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

		cout << "��ɾ����" << endl;

		this->savePerson();
	}
	else {
		cout << "���޴��ˣ��޷�ɾ��" << endl;
	}

	system("pause");
	system("cls");
}
void addressBook::modifyPersonByName(addressBook* pmab) {
	cout << "�����������޸ĵ���ϵ��������" << endl;
	string aname;
	cin >> aname;
	bool flag = false;

	if (pmab->size != 0) {
		for (int i = 0; i < pmab->size; ++i) {
			if (pmab->addressArray[i].name == aname) {
				cout << "�������޸ĺ����ϵ�������� " << endl;
				string aname;
				cin >> aname;
				pmab->addressArray[i].name = aname;

				cout << "�������޸ĺ����ϵ�����ڹ�˾�� " << endl;
				string acompany;
				cin >> acompany;
				pmab->addressArray[i].company = acompany;

				cout << "�������޸ĺ����ϵ�˹̶��绰�� " << endl;
				string afixTel;
				cin >> afixTel;
				pmab->addressArray[i].fixTel = afixTel;

				cout << "�������޸ĺ����ϵ���ƶ��绰�� " << endl;
				string amobTel;
				cin >> amobTel;
				pmab->addressArray[i].mobTel = amobTel;

				cout << "�������޸ĺ����ϵ�����" << endl;
				cout << "1��ͬ�£�" << endl;
				cout << "2�����ѣ�" << endl;
				cout << "3��ͬѧ��" << endl;
				cout << "4�����ˣ�" << endl;
				string asort;
				int sel = 0;
				while (true) {
					cin >> sel;
					if (sel == 1 || sel == 2 || sel == 3 || sel == 4) {
						switch (sel)
						{
						case 1:
							asort = "ͬ��";
							break;
						case 2:
							asort = "����";
							break;
						case 3:
							asort = "ͬѧ";
							break;
						case 4:
							asort = "����";
							break;
						default:
							break;
						}
						break;
					}
					else {
						cout << "�����������������룡" << endl;
					}
				}
				pmab->addressArray[i].sort = asort;

				cout << "�������޸ĺ����ϵ��Email�� " << endl;
				string aemail;
				cin >> aemail;
				pmab->addressArray[i].email = aemail;

				cout << "�������޸ĺ����ϵ��QQ�� " << endl;
				string aqq;
				cin >> aqq;
				pmab->addressArray[i].qq = aqq;

				cout << "�޸ĳɹ���" << endl;
				flag = true;

				this->savePerson();
			}
		}
	}	
	if (!flag)
		cout << "���޴��ˣ� �޸�ʧ��" << endl;

	system("pause");
	system("cls");
}


// �����ϵ��
void addressBook::deleteAllPerson(addressBook* pmab) {

	char sel;
	cout << "Are you sure ?(Y/N)" << endl;
	cin >> sel;
	if (sel == 'Y' || sel == 'y') {
		// �߼���ɾ��
		//pmab->addressArray == nullptr;
		ofstream ofs(FILENAME, ios::trunc); // ����ļ����ڣ���ɾ���ļ����´���
		ofs.close();

		pmab->size = 0;
		pmab->isFileEmpty = true;

		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "ɾ��ʧ�ܣ�" << endl;
	}

	system("pause");
	system("cls");	
}

// �ļ�����
// ͬ��ҲҪ��������addressBook::����Ϊ��һ���ǳ�Ա����
void addressBook::savePerson() {  
	// �ȴ���һ���ļ����Ķ���
	ofstream ofs;

	// ��д����ʽȥ���ļ�
	ofs.open(FILENAME, ios::out);

	// Ȼ�󽫱��浽���������ݶ�д���ļ�
	for (int i = 0; i < this->size; ++i) {
		ofs << this->addressArray[i].name << " "
			<< this->addressArray[i].company << " "
			<< this->addressArray[i].fixTel << " "
			<< this->addressArray[i].mobTel << " "
			<< this->addressArray[i].sort << " "
			<< this->addressArray[i].email << " "
			<< this->addressArray[i].qq << endl;
	}

	// ���Ҫ�ǵùر��ļ�
	ofs.close();

}

// �˳�ͨѶ¼
void addressBook::exitPerson() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

addressBook::~addressBook()
{
	if (this->addressArray != NULL) {
		delete [] this->addressArray;
		this->addressArray = NULL;
	}
}
