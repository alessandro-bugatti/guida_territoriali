//semiprimo - territoriali 2015
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

char operatori[100000];
int numeri[100000];
int N;

void inverti(int v[], int inizio, int fine)
{
	while(inizio<fine)
	{
		int temp = v[inizio];
		v[inizio] = v[fine];
		v[fine] = temp;
		inizio++;
		fine--;
	}
}

int main()
{
	int i = 0;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	in >> operatori;
	//Inizializzo il vettore con i numeri in ordine crescente
	for (i = 0; i < N; i++)
		numeri[i] = i+1;
	i = 0;
	while (i < N)
	{
		int start = i;
		while (operatori[i] == '>') i++;
		if (start != i)
			inverti(numeri,start,i);
		i++;
	}
	for ( i = 0; i < N; i++)
		out << numeri[i] << " ";
	return 0;
}
