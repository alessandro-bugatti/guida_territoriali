#include <algorithm>
#include <iostream>

using namespace std;

struct differenza{
	int posizione;
	int diff;
	bool operator<(const differenza& a) const
	{
		return diff > a.diff;
	}
};

differenza monica[10000000];
int mozzarelle_monica[10000000];

long long solve(int N, int* M, int* P) {
    for (int i= 0; i < N; i++)
    {
		monica[i].posizione = i;
		monica[i].diff = M[i] - P[i];
	}
	sort(monica, monica+N);
	fill(mozzarelle_monica, mozzarelle_monica+N, false);
	int totale = 0;
	for (int i= 0; i < N/2; i++)
    {
		totale += M[monica[i].posizione];
		mozzarelle_monica[monica[i].posizione] = true;
	}
	for (int i= 0; i < N; i++)
		if (mozzarelle_monica[i] == false)
			totale += P[i];
	return totale;
}
