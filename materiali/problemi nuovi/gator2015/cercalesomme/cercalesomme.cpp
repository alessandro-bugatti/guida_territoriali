#include <fstream>
#include <iostream>

using namespace std;

int operatori[10];
int quanti;
int cifre[9];
int N, totale;
ofstream out;

int componi(int inizio, int fine)
{
	int totale = 0;
	for (int i = inizio; i <= fine; i++)
		totale = totale*10 + cifre[i];
	return totale;
}

void cercasomme(int start, int parziale)
{
	if (start == N)
		if (parziale == totale)
		{
			for (int i = 0; i < N; i++)
			{
				if (operatori[i] == 1)
					out << i << " ";
			}
			out << endl;
			return;
		}
	for (int i = start; i < N ; i++)
	{
		operatori[i+1] = 1;
		cercasomme(i+1,parziale + componi(start,i));
		operatori[i+1] = 0;
	}
}

int main()
{
	ifstream in("input.txt");
	out.open("output.txt");
	in >> N;
	for (int i = 0; i < N; i++)
		in >> cifre[i];
	in >> totale;
	cercasomme(0,0);
	return 0;
}
