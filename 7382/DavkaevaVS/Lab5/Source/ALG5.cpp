#include "Btree.h"
#include <iostream>
//#include <Windows.h>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace binSTree_modul;


//ifstream infile("inputf.txt"); //    файл для считывания
ofstream outfile("outputf.txt");  // файл вывода 
int main()
{
	char ch;
	char name[20];
	cout << "Enter the name of file" << endl;
	cin >> name;
	ifstream infile(name); //    файл для считывания
	//if (!infile) cout << "NET" << endl;
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);	// для вывода кирилицы
	binSTree  tree;
	tree = Create();
	while (infile >> ch) {		// чтение дерева
		cout << ch << " "<<endl;
		read(ch, tree);
	}
	cout << endl;
	displayBT(tree, 1);			// вывод дерева в консоль
	printLKP(tree);             // запись ЛКП в консоль
	cout << endl;
	printTEXTLKP(tree, outfile);// запись ЛКП в файл
	destroy(tree);
	//system("pause");
	return 0;
}

