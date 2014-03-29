/*Treno, soluzione di Alessandro Bugatti */
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

int K,N;
char vettore[2003];

struct spostamento{
    int i,j;
    spostamento (int n, int m):i(n),j(m){}
};

queue <spostamento> coda;

void sposta(int i, int j)
{
    vettore[j] = vettore[i];
    vettore[j+1] = vettore[i+1];
    vettore[i]='*';
    vettore[i+1]='*';
}

void calcola(int i, int j)
{
    if (j-i==7){
        sposta(i -1 + 2,i -1 + 7);
        coda.push(spostamento(i -1 + 2,i -1 + 7));
        sposta(i -1 + 6,i -1 + 2);
        coda.push(spostamento(i - 1 + 6,i - 1 + 2));
        sposta(i -1 + 4,i -1 + 6);
        coda.push(spostamento(i - 1 + 4,i - 1 + 6));
        sposta(i -1 + 7,i -1 + 4);
        coda.push(spostamento(i - 1 + 7,i - 1 + 4));
        return;
    }
    int n = (j - i -1)/2 +i -1;
    sposta(n,j-1);
    coda.push(spostamento(n,j-1));
    sposta(i,n);
    coda.push(spostamento(i,n));
    sposta(j-1,i);
    coda.push(spostamento(j-1,i));
    calcola(i+2,j);
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	for (int i=1; i<=N; i++)
		vettore[i]='A';
	for (int i=N+1; i<=2*N; i++)
		vettore[i]='B';
	vettore[2*N+1]= '*';
	vettore[2*N+2]= '*';
	calcola(1,2*N+2);
	out << coda.size() << " " << N << endl;
	while(!coda.empty())
	{
	    out << coda.front().i << " " << coda.front().j << endl;
	    coda.pop();
	}
    return 0;
}
