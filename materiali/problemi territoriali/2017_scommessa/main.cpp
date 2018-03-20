//scommessa - territoriali 2017
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	vector <int> esclusi;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	int pari = N/2 + 1;
	int dispari = N/2;
	int pari_prima = 0;
	int dispari_prima = 0;
	for (int i = 0; i < N; i++)
	{
        int n;
        in >> n;
        if (n%2 == 0){
            pari--;
        }
        else
            dispari--;
        if (pari == dispari && pari_prima == dispari_prima)
            esclusi.push_back(n);
        if (n%2 == 0){
            pari_prima++;
        }
        else
            dispari_prima++;
    }
    out << esclusi.size() << endl;
    for (auto i: esclusi)
        out << i << " ";
    out << endl;
	return 0;
}
