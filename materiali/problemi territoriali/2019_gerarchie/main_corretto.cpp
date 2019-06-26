#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

const int MAXN = 1000;

using namespace std;

struct Nodo{
	int R;
	int C;
	bool sistemato = false;
};

Nodo nodi[MAXN];

int maggiore(Nodo nodi[], int N)
{
	int massimo = -1, indice;
	for (int i = 0; i < N; i++)
		if (nodi[i].C > massimo && nodi[i].sistemato == false){
			indice = i;
			massimo = nodi[i].C;
		} 
	return indice;
}

	
	
int solve() {
    int N;
    cin >> N;

    int risposta = 0;  // memorizza qui la risposta
    
    for (int i=0; i<N; i++) {
        cin >> nodi[i].R >> nodi[i].C;
        nodi[i].sistemato = false;
    }
	for (int i=0; i<N; i++) {
        int da_sistemare = maggiore(nodi, N);
        while (nodi[da_sistemare].R != -1 && nodi[da_sistemare].C > nodi[nodi[da_sistemare].R].C)
        {
			int temp = nodi[da_sistemare].C;
			nodi[da_sistemare].C = nodi[nodi[da_sistemare].R].C;
			nodi[nodi[da_sistemare].R].C = temp;
			da_sistemare = nodi[da_sistemare].R;
			risposta++;
		}
		nodi[da_sistemare].sistemato = true;
    }
	return risposta;
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    scanf("%d", &T);

    for (t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}
