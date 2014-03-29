//Writing IOI 2006

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

char W[5000];
char S[5000000];
int g,N;

int chiaveW[256];
int chiaveCorrente[256];

void inizializza_chiavi()
{
	for (int i = 0; i < g; i++)
	{
		chiaveW[W[i]]++;
		chiaveCorrente[S[i]]++;
	}
}

bool chiavi_uguali()
{
	//minuscole
	for (int i = 'a'; i <= 'z'; i++)
		if (chiaveW[i] != chiaveCorrente[i])
			return false;
	//maiuscole
	for (int i = 'A'; i <= 'Z'; i++)
		if (chiaveW[i] != chiaveCorrente[i])
			return false;
	return true;
}

//Per il debug
void stampa_chiavi()
{
	//chiaveW
	cout << "W ";
	for (int i = 'a'; i <= 'z'; i++)
		cout << chiaveW[i] << " ";
	cout << endl; 
	//chiaveCorrente
	cout << "C ";
	for (int i = 'a'; i <= 'z'; i++)
		cout << chiaveCorrente[i] << " ";
			cout << endl; 
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> g >> N;
	in >> W >> S;
	inizializza_chiavi();
	int contatore = 0;
	for (int i = 0; i <= N - g; i++)
	{
		if (chiavi_uguali()) contatore++;
		//stampa_chiavi();
		chiaveCorrente[S[i]]--;
		chiaveCorrente[S[i+g]]++;
	}
	out << contatore << endl;
	return 0;
}

