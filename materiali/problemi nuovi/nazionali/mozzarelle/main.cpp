#include <stdio.h>
#include "solve.cpp"
#define MAXN 10000000

int N, i;
int M[MAXN], P[MAXN];

FILE *fin, *fout;

int main(){
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    fscanf(fin, "%d", &N);
    for(i=0; i<N; i++) 
		fscanf(fin, "%d%d", M+i, P+i);
    fprintf(fout, "%lld\n", solve(N, M, P));
    fclose(fin);
    fclose(fout);
    return 0;
}
