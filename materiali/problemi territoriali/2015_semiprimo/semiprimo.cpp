//semiprimo - territoriali 2015
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

bool primo(int n)
{
	int N = sqrt(n);
	for (int i = 2; i <= N; i++)
		if (n%i == 0)
			return false;
	return true;
}


int main()
{
	int N;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	for (int i = 2; i < N; i++)
		if (primo(i) && N%i == 0 && primo(N/i))
		{
			out << i << " " << N/i << endl;
			return 0;
		}
		else if (primo(i) && N%i == 0)
		{
			out << -1 << endl;
			return 0;
		}
	return 0;
}
