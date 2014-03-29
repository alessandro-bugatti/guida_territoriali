//Cannoniere GATOR 2014

#include <iostream>
#include <fstream>

using namespace std;

int N;
int calciatori[101];

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	for (int i = 0; i < N; i++)
	{
		int g, r;
		in >> g >> r;
		calciatori[g] += r;
	}
	int cannoniere = 0;
	for (int i = 0; i <= 100; i++)
		if (calciatori[i] > calciatori[cannoniere])
			cannoniere = i;
	out << cannoniere  << " " << calciatori[cannoniere] << endl;
}

