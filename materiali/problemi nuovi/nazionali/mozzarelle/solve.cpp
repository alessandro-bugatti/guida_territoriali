#include <algorithm>
#include <iostream>

using namespace std;

struct differenza{
	int diff;
	int primo;
	int secondo;
	bool operator<(const differenza& a) const
	{
		return diff > a.diff;
	}
};

differenza monica[10000001];

long long solve(int N, int* M, int* P) {
    for (int i= 0; i < N; i++)
		monica[i].diff = (monica[i].primo = M[i]) - (monica[i].secondo = P[i]);
	sort(monica, monica+N);
	long long int totale = 0;
	for (int i= 0; i < N/2; i++)
		totale += monica[i].primo;
	for (int i= N/2; i < N; i++)
		totale += monica[i].secondo;
	return totale;
}
