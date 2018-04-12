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
		int pari = 0, dispari = 0;
		for (int i = 0; i < N; i++)
		{
			int n;
			in >> n;
			if (n%2 == 0 && pari == dispari)
				esclusi.push_back(n);
			if (n%2 == 0)
				pari++;
			else
				dispari++;
		}
		out << "Case #" << k+1 << ":" << endl;
		out << esclusi.size() << endl;
		for (auto i: esclusi)
			out << i << " ";
		out << endl;
	}
	return 0;
}
