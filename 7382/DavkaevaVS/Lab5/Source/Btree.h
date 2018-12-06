#include <fstream>
namespace binSTree_modul
{
	typedef char base;

	struct node {
		base info;
		unsigned int count;
		node *lt;
		node *rt;
		// constructor
		node() { count = 0; lt = NULL; rt = NULL; }
	};

	typedef node *binSTree; // "представитель" бинарного дерева

	binSTree Create(void);
	bool isNull(binSTree);
	base RootBT(binSTree);
	unsigned int RootCountBT(binSTree); // для непустого бин.дерева
	binSTree Left(binSTree);// для непустого бин.дерева
	binSTree Right(binSTree);// для непустого бин.дерева
	binSTree ConsBT(const base &x, binSTree &lst, binSTree &rst);


	void read(base x, binSTree &b);

	void displayBT(binSTree b, int n);

	void printLKP(binSTree b);

	void printTEXTLKP(binSTree b, std::ofstream &out);

	void destroy(binSTree &b);
}

