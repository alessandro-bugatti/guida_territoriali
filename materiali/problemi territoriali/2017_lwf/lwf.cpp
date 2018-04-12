//lwf - territoriali 2017
#include <fstream>
#include <iostream>

using namespace std;

const int MAX = 40;

int risultato[MAX];
int numeri_fibonacci[MAX];

void inizializza_numeri()
{
	numeri_fibonacci[0] = 1;
	numeri_fibonacci[1] = 1;
	for (int i = 2; i < MAX; i++)
		numeri_fibonacci[i] = numeri_fibonacci[i-1] + numeri_fibonacci[i-2];
}

int calcola_codice(int N)
{
	int i = MAX - 1, lunghezza;
	std::fill_n(risultato, MAX, 0);
	while (numeri_fibonacci[i] > N) i--;
	lunghezza = i;
	while (N > 0)
	{
		if (numeri_fibonacci[i] <= N){
			N -= numeri_fibonacci[i];
			risultato[i] = 1;
			//cout << i << " " << numeri_fibonacci[i] << endl;
		}
		i--;
	}
	return lunghezza;
}

int main()
{
	int T, N;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> T;
	inizializza_numeri();
	for (int i = 0; i < T; i++)
	{
        in >> N;
        out << "Case #" << i+1 << ": ";
        int lunghezza = calcola_codice(N);
        for (int i = 0; i <= lunghezza; i++)
            out << risultato[i];
        out << endl;
    }
	return 0;
}
