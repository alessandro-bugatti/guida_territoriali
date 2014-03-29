//Baht nazionali 2010

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int P, N, monete[10000];

int main()
{
	int max = 0;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> P;
	for (int i = 0; i < P; i++)
	{	
		in >> N;
		int j;
		for (j = 0; j < N; j++)
			in >> monete[j];
		sort (monete, monete + j);	
		int quante = j;
		int somma = 0;
		for (int j = 0; j < quante; j++)
		{
			if (monete[j] <= somma + 1)
				somma += monete[j];
			else
				break;
		}
		out << somma + 1 << endl;
	}
	return 0;
}

