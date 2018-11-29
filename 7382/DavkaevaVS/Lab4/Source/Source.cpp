#include <iostream>
#include <fstream>
#include <fstream>
#include <cstdlib>
#include "Btree.h"
#include <stdio.h>
//#include <windows.h>
//#include <conio.h>
#include <algorithm>

using namespace std;
using namespace binTree_modul;

typedef unsigned int unInt;

binTree enterBT();
void displayBT(binTree b, int n);
unInt sizeBT(binTree b);
unInt lenBT(binTree b);
unInt NumOfLvl(binTree b, int a, int c = 1);
int getMaxDepth(binTree b, int depth = 1);
void levelBT(binTree b);
ifstream infile("KLP.txt");

//---------------------------------------
binTree enterBT()
{
	char ch;
	binTree p, q;
	infile >> ch;
	while (ch == '(' || ch == ')') infile >> ch;
	if (ch == '/') { return NULL; }
	else {
		p = enterBT(); q = enterBT();
		return ConsBT(ch, p, q);
	}
}

int getMaxDepth(binTree q, int depth)
{

	if (q != NULL)cout << "Узел " << q->info << " Текущая глубина=" << depth << endl;
	if (q == NULL) { return depth; }
	else return max(getMaxDepth(q->rt, depth + 1), getMaxDepth(q->lt, depth + 1));
}


//---------------------------------------
void displayBT(binTree b, int n)
{	// n - уровень узла
	if (b != NULL) {
		cout << ' ' << RootBT(b);
		if (!isNull(Right(b))) { displayBT(Right(b), n + 1); }
		else cout << endl; // вниз
		if (!isNull(Left(b))) {
			for (int i = 1; i <= n; i++) cout << "  "; // вправо
			displayBT(Left(b), n + 1);
		}
	}
	else {};
}

void levelBT(binTree b)
{
	if (!isNull(b))
	{
		if (!(isNull(b->lt) && isNull(b->rt)))
			cout << "Узел:" << b->info << endl;
		levelBT(b->lt);
		if (isNull(b->lt) && isNull(b->rt))
			cout << "Лист:" << b->info << endl;

		levelBT(b->rt);

	}
}

unInt NumOfLvl(binTree b, int lvl, int lvl_now)
{
	if (b != NULL && lvl >= lvl_now){ 
		cout << lvl << "vs" << lvl_now << " Узел " << b->info;
		if (lvl == lvl_now) cout << " Узел на заданном уровне существует!\n";
		else cout << "\n";
	}
	if (lvl == lvl_now) return 1;
	else if (lvl >= lvl_now)return(((b->lt) ? NumOfLvl(b->lt, lvl, lvl_now + 1) : 0) + ((b->rt) ? NumOfLvl(b->rt, lvl, lvl_now + 1) : 0));
}

int len = 0;
unInt lenBT(binTree b)
{
	if (!isNull(b))cout << "Узел " << b->info << " " << " Левый " << lenBT(Left(b)) << " Правый " << lenBT(Right(b)) << " Количество узлов " << sizeBT(b) - 1 << endl;
	if (isNull(b)) { return 0; }
	else
	{
		return lenBT(Left(b)) + lenBT(Right(b)) + sizeBT(b) - 1;
	}
}
//---------------------------------------
unInt sizeBT(binTree b)
{
	if (isNull(b)) return 0;
	else return sizeBT(Left(b)) + sizeBT(Right(b)) + 1;
}


int main()
{
	binTree b;
//	SetConsoleCP(1251);			// для вывода кирилицы
//	SetConsoleOutputCP(1251);
	char name[80];
	cout << "enter the string" << endl;
	cin >> name;	// для вывода кирилицы
	ofstream out;          // поток для записи
	out.open("KLP.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		out << name << endl;
	}
	b = enterBT();
	int depth = 1;
	if (isNull(b)) cout << "Пустое БД" << endl;
	else
	{
		cout << "Бинарное дерево (повернутое): " << endl;
		displayBT(b, 1);
		cout << "\nВычисление высоты дерева: " << endl;
		int a = getMaxDepth(b) - 1;
		cout << "Высота дерева = " << a << "\n\n";
		cout << "Длина внутреннего пути дерева = " << lenBT(b) << endl;
		cout << "\nПоиск листьев дерева:" << endl; levelBT(b);
		cout << "\nНахождение количества узлов на N-ом уровне. Введите N:" << endl;
		int num;
		cin >> num;
		cout << "Количество узлов на заданном уровне = " << NumOfLvl(b, num);

		destroy(b);

	}
	getchar();
}



