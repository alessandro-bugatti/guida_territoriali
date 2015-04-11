#include <fstream>
#include <iostream>
#include <list>

using namespace std;

struct collegamento{
	int verso;
	int costo;
	collegamento(int a, int b):verso(a), costo(b){}
};

struct piazza{
	int tempo;
	list <collegamento> collegamenti;
	piazza(){tempo = 1000000000;}
};

piazza piazze[1001];

int N, M;

void visita (int p)
{
	list<collegamento>::iterator i;
	for ( i = piazze[p].collegamenti.begin(); i != piazze[p].collegamenti.end() ; ++i)
	{
		if (piazze[i->verso].tempo > piazze[p].tempo + i->costo)
		{
			piazze[i->verso].tempo = piazze[p].tempo + i->costo;
			visita(i->verso);
		}
	}
}
	

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		in >> a >> b >> c;
		piazze[a].collegamenti.push_front(collegamento(b,c));
		piazze[b].collegamenti.push_front(collegamento(a,c));
	}
	piazze[1].tempo = 0;
	visita(1);
	int totale = 0;
	for (int i = 2; i <= N; i++)
	{
		if (piazze[i].tempo <= i*10)
			totale++;
	}
	out << totale + 1<< endl;
	
	return  0;
}
	
