//Mojito - territoriali 2014

#include <fstream>
#include <cstdlib>

using namespace std;

struct coordinate{
	int x,y;
};
 
struct ragazzo{
	coordinate posizione, lancio;
};

coordinate mojito;
ragazzo ragazzi[100];
int N;
int R;
bool partecipanti[100];

int distanza(coordinate a, coordinate b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int calcolaProssimo(coordinate posizione)
{
	int dmin = 2001, d, posmin=-1;
	for (int i = 0; i < N; i++)
	{
		d=distanza(ragazzi[i].posizione, posizione);
		if (d < dmin)
		{	
			dmin = d;
			posmin = i;
		}
		else if (d == dmin)
		{
			if (ragazzi[i].posizione.x < ragazzi[posmin].posizione.x)
				posmin = i;
			else if (ragazzi[i].posizione.x == ragazzi[posmin].posizione.x &&
				ragazzi[i].posizione.y < ragazzi[posmin].posizione.y)
				posmin = i;
		}
	}
	return posmin;
}

int main()
{
	int X,Y;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> X >> Y;
	in >> mojito.x >> mojito.y;
	in >> N, R = 1;
	for (int i = 0; i < N; i++)
		in >> ragazzi[i].posizione.x >> ragazzi[i].posizione.y >>
		ragazzi[i].lancio.x >> ragazzi[i].lancio.y;
	fill(partecipanti, partecipanti+N, false);
	int prossimo = calcolaProssimo(mojito);
	partecipanti[prossimo] = true;
	prossimo = calcolaProssimo(ragazzi[prossimo].lancio);
	while(partecipanti[prossimo] != true)
	{	
		partecipanti[prossimo] = true;
		R++;
		prossimo = calcolaProssimo(ragazzi[prossimo].lancio);
	}
	out << R << endl;
	return 0;
}
