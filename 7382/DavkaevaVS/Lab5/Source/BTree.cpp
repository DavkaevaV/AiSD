#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include "Btree.h"
using namespace std;

namespace binSTree_modul
{

	//-------------------------------------
	binSTree Create()
	{
		return NULL;
	}
	//-------------------------------------
	bool isNull(binSTree b)
	{
		return (b == NULL);
	}
	//-------------------------------------
	base RootBT(binSTree b)			// для непустого бин.дерева
	{
		if (b == NULL) { cerr << "Error: RootBT(null) \n"; exit(1); }
		else return b->info;
	}
	//-------------------------------------	
	unsigned int RootCountBT(binSTree b) // для непустого бин.дерева
	{
		if (b == NULL) { cerr << "Error: RootBT(null) \n"; exit(1); }
		else return b->count;
	}
	//-------------------------------------	
	binSTree Left(binSTree b)		// для непустого бин.дерева
	{
		if (b == NULL) { cerr << "Error: Left(null) \n"; exit(1); }
		else return b->lt;
	}
	//-------------------------------------	
	binSTree Right(binSTree b)		// для непустого бин.дерева
	{
		if (b == NULL) { cerr << "Error: Right(null) \n"; exit(1); }
		else return b->rt;
	}
	//-------------------------------------		
	binSTree ConsBT(const base &x, binSTree &lst, binSTree &rst)
	{
		binSTree p;
		p = new node;
		if (p != NULL) {
			p->info = x;
			p->count = 1;
			p->lt = lst;
			p->rt = rst;
			return p;
		}
		else { cerr << "Memory not enough\n"; exit(1); }
	}
	//-------------------------------------			

	void read(base x, binSTree &b)
	{
		binSTree p;
		if (b == NULL) {
			p = new node;
			if (p != NULL) {
				p->info = x;
				p->count = 1;
				p->lt = NULL;
				p->rt = NULL;
				//cout << " its root"<<endl;
				b = p;
			}
			else { cerr << "Memory not enough\n"; exit(1); }
		}
		else if (x < b->info) {  cout << "new element less then "<< b->info << " -> " << x << " left tree" << endl; read(x, b->lt);}//{cout << x << "<-" << endl; SearchAndInsert (x, b->lt);}
		else if (x > b->info){ cout << "new element more then " << b->info << " -> " << x << " right tree" << endl; read(x, b->rt);}//{cout << x << "->" << endl; SearchAndInsert (x, b->rt);}
		else b->count++;
	}
	///////////////////////////////////////////////////
	void displayBT(binSTree b, int n)
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
	//---------------------------------------
	void printLKP(binSTree b)
	{
		if (!isNull(b)) {
			printLKP(Left(b));
			cout << RootBT(b);
			printLKP(Right(b));
		}
	}
	//---------------------------------------

	void printTEXTLKP(binSTree b, std::ofstream &out)
	{
		if (!isNull(b)) {
			printTEXTLKP(Left(b), out);
			out << RootBT(b);
			printTEXTLKP(Right(b), out);
		}
	}
	void destroy(binSTree &b)
	{
		if (b != NULL) {
			destroy(b->lt);
			destroy(b->rt);
			delete b;
			b = NULL;
		}
	}
}




