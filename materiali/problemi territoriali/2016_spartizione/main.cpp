//spartizioni - territoriali 2016
#include <fstream>
#include <iostream>

using namespace std;


int main()
{
	int N, P, toto_corrente, complici, totale=0;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> P;
	toto_corrente = 1;
	complici = P-1;
	while (N >= toto_corrente + complici)
	{
		N -= toto_corrente + complici;
		totale += toto_corrente;
		toto_corrente++;
	}
	totale += N;
	out << totale << endl;
	return 0;
}
