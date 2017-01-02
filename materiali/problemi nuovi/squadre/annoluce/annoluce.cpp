#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long int distanza[100000];
int pianeti;

void mappatura(int N, int X[], int Y[], int Z[]) {
	pianeti = N;
    for (int i = 0; i < N; i++)
		distanza[i] = (long long int)X[i]*X[i] + (long long int)Y[i]*Y[i] + (long long int)Z[i]*Z[i];
	sort(distanza, distanza + N);
}

int query(int D) {
    return upper_bound(distanza, distanza + pianeti, (long long int)D*D) - distanza;
}


#define MAXN 100000
int X[MAXN], Y[MAXN], Z[MAXN];

int main() {
    FILE *fr, *fw;
    int N, Q, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(3 == fscanf(fr, "%d%d%d", &X[i], &Y[i], &Z[i]));

    mappatura(N, X, Y, Z);

    assert(1 == fscanf(fr, "%d", &Q));
    for(i=0; i<Q; i++) {
        int D;
        assert(1 == fscanf(fr, "%d", &D));
        fprintf(fw, "%d\n", query(D));
    }
	fclose(fr);
    fclose(fw);
    return 0;
}
