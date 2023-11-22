#include <iostream>
#include <cstring>
using namespace std;
struct Element { int valoare; Element *urmatorul; };
struct Coada { Element *primul, *ultimul; };
void push(Coada &, int);
void pop(Coada &);
int main()
{
	int nrOperatii;
	Coada C;
	C.primul = 0;
	C.ultimul = 0;
	cin >> nrOperatii;
	while (nrOperatii > 0)
	{
		char operatie[6];
		cin >> operatie;
		if (!strcmp(operatie, "push"))
		{
			int numar;
			cin >> numar;
			push(C, numar);
		}
		else if (!strcmp(operatie, "pop"))
			pop(C);
		else if (!strcmp(operatie, "front"))
			if (C.primul)
				cout << C.primul->valoare << endl;
		nrOperatii--;
	}
	return 0;
}
void pop(Coada & C)
{
	if (C.primul)
		if (C.primul == C.ultimul)
		{
			delete C.primul;
			C.primul = 0;
			C.ultimul = 0;
		}
		else
		{
			Element * e = C.primul->urmatorul;
			delete C.primul;
			C.primul = e;
		}
}
void push(Coada & C, int numar)
{
	Element * e = new Element;
	e->valoare = numar;
	e->urmatorul = 0;
	if (!C.primul)
		C.primul = C.ultimul = e;
	else
	{
		C.ultimul->urmatorul = e;
		C.ultimul = e;
	}
}
