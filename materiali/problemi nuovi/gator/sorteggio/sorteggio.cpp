//Sorteggio Gator 2014

#include <fstream>
#include <algorithm>


using namespace std;

int M;
int squadre[65];

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int valore_mia_squadra;
	in >> M;
	in >> valore_mia_squadra;
	squadre[0] = valore_mia_squadra;
	for (int i = 1; i < M; i++)
	{
		int valore;
		in >> valore;
		squadre[i] = valore;
	}
	sort(squadre, squadre+M);
	reverse(squadre, squadre+M);
	int posizione_in_classifica;
	for (int i = 0; i < M; i++)
	{
		if (squadre[i] == valore_mia_squadra)
			posizione_in_classifica = i+1;
	}
	//out << posizione_in_classifica << endl;
	if (M == 16)
	{
		if (posizione_in_classifica >= 15)
			out << "G" << endl;
		else if (posizione_in_classifica >= 11)
			out << "Q" << endl;
		else if (posizione_in_classifica >= 4)
			out << "H" << endl;
		else if (posizione_in_classifica >= 2)
			out << "F" << endl;
		else
			out << "V" << endl;
	}
	if (M == 32)
	{
		if (posizione_in_classifica >= 31)
			out << "G" << endl;
		else if (posizione_in_classifica >= 27)
			out << "O" << endl;
		else if (posizione_in_classifica >= 20)
			out << "Q" << endl;
		else if (posizione_in_classifica >= 6)
			out << "H" << endl;
		else if (posizione_in_classifica >= 2)
			out << "F" << endl;
		else
			out << "V" << endl;
	}	
	if (M == 64)
	{
		if (posizione_in_classifica >= 63)
			out << "G" << endl;
		else if (posizione_in_classifica >= 59)
			out << "S" << endl;
		else if (posizione_in_classifica >= 52)
			out << "O" << endl;
		else if (posizione_in_classifica >= 38)
			out << "Q" << endl;
		else if (posizione_in_classifica >= 10)
			out << "H" << endl;
		else if (posizione_in_classifica >= 2)
			out << "F" << endl;
		else
			out << "V" << endl;
	}
	return 0;
}
