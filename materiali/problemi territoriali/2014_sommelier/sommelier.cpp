//Sommelier - territoriali 2014

#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int vini[100];
int sottoproblemi[100];
int N;

int soluzione(int n)
{
	if (sottoproblemi[n] != -1)
		return sottoproblemi[n];
	int max = 1;
	for (int i = n + 1; i < N; i++)
			if (soluzione(i) + 1 > max && vini[n] <= vini[i])
				max = soluzione(i) + 1;
	sottoproblemi[n] = max;
	return max;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	for (int i = 0; i < N; i++)
		in >> vini[i];
	fill(sottoproblemi, sottoproblemi + N, -1);
	sottoproblemi[N-1] = sottoproblemi[N-2] = 1;
	soluzione(0);
	out << *max_element(sottoproblemi,sottoproblemi + N) << endl;
	return 0;
}
