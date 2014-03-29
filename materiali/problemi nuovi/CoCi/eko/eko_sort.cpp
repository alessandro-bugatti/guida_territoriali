//EKO Coci marzo 2012
//Soluzione con ordinamento delle altezze
//Tutti corretti, il più pesante in 0.44s

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int alberi[1000000];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> alberi[i];
	sort(alberi,alberi + N, greater<int>());
	int alberi_tagliati = 1, legno = 0, altezza, i;
	for (i = 1; i < N; i++)
	{
		while (alberi[i-1] == alberi[i]) i++;
		legno += i * (alberi[i-1] - alberi[i]);
		if (legno >= M) break;
	}
	//Tolgo la parte che si può togliere
	cout << alberi[i] + (legno - M)/i << endl;
	return 0;
}
