//scommessa - territoriali 2017
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T, N;

	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> T;
	for (int k = 0; k < T; k++)
	{
		vector <int> esclusi;
		in >> N;
		int pari_dx = N/2 + 1, dispari_dx = N/2;
		int pari_sx = 0, dispari_sx = 0;
		for (int i = 0; i < N; i++)
		{
			int n;
			in >> n;
			if (n%2 == 0)
				pari_dx--;
			else
				dispari_dx--;
			if (n%2 == 0 && pari_dx == dispari_dx && pari_sx == dispari_sx)
				esclusi.push_back(n);
			if (n%2 == 0)
				pari_sx++;
			else
				dispari_sx++;
		}
		out << "Case #" << k+1 << ":" << endl;
		out << esclusi.size() << endl;
		for (auto i: esclusi)
			out << i << " ";
		out << endl;
	}
	return 0;
}
