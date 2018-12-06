#include "Btree.h"
#include <iostream>
//#include <Windows.h>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace binSTree_modul;


//ifstream infile("inputf.txt"); //    ���� ��� ����������
ofstream outfile("outputf.txt");  // ���� ������ 
int main()
{
	char ch;
	char name[20];
	cout << "Enter the name of file" << endl;
	cin >> name;
	ifstream infile(name); //    ���� ��� ����������
	//if (!infile) cout << "NET" << endl;
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);	// ��� ������ ��������
	binSTree  tree;
	tree = Create();
	while (infile >> ch) {		// ������ ������
		cout << ch << " "<<endl;
		read(ch, tree);
	}
	cout << endl;
	displayBT(tree, 1);			// ����� ������ � �������
	printLKP(tree);             // ������ ��� � �������
	cout << endl;
	printTEXTLKP(tree, outfile);// ������ ��� � ����
	destroy(tree);
	//system("pause");
	return 0;
}

