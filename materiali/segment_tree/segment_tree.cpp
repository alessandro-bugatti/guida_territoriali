#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

//Struttura che contiene le informazioni sulla somma e l'intervallo su cui è calcolata
struct somma{
	int s;
	pair <int,int> intervallo;
	somma():s(0){}
	friend ostream& operator<<(ostream &o, const somma& a);
	
};

ostream& operator<<(ostream &o, const somma& a)
{
	o << "S: " << a.s << " int: " << a.intervallo.first << " - "
	<< a.intervallo.second << endl;
	return o;
}

//Vettore che contiene il segment tree
somma tree[100];

//Vettore dei dati 
int dati[10];

int tree_inizialization(int n)
{
	int dim = 0, pow = 1;
	for (int i = n; i > 0; i/=2){
		dim += pow;
		pow *= 2;
	}
	for (int i = dim; i < dim + n; i++)q
	{
		tree[i].s = dati[i-dim];
		tree[i].intervallo = make_pair (i-dim,i-dim);
	}
	for (int i = 0; i < dim*2+1; i++)
		cout << tree[i] << endl;
}

int main()
{
	int n;
	ifstream in("input.txt");
	in >> n;
	for (int i = 0; i < n; i++)
		in >> dati[i];
	tree_inizialization(6);
	return 0;
}
