//Primo tentativo, partendo da un'assunzione sbagliata mi sono trovato
//a scrivere un mucchio di codice complesso che prendeva solo 9/19
//Morale: pensare bene prima di scrivere

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

const int MAXN = 1000;

using namespace std;

struct Nodo{
	int R;
	int C;
	bool operator< (const Nodo &i) { return C < i.C; };
};

Nodo nodi[MAXN];
vector<Nodo*> livelli[MAXN];

Nodo* maggiore(const vector<Nodo*>& nodi)
{
	Nodo *massimo = nodi[0];
	for (auto i: nodi)
		if (i->C > massimo->C)
			massimo = i;
	return massimo;
}

int livello(int tutor)
{
	int l = 0;
	while (nodi[tutor].R != -1)
	{
		l++; 
		tutor = nodi[tutor].R;
	}
	return l;
}
	
	
int solve() {
    int N;
    cin >> N;

    int risposta = 0;  // memorizza qui la risposta
    
    for (int i=0; i<N; i++) {
        cin >> nodi[i].R >> nodi[i].C;
    }
    /*for (int i=0; i<N; i++) {
        cout << nodi[i].R << " " << nodi[i].C << endl;
    }*/
    int altezza = -1;
	for (int i=0; i < N; i++) {
		//cout << i << " -> " << livello(i) << endl;
		int temp = livello(i);
		if (temp > altezza)
			altezza = temp;
		livelli[temp].push_back(&nodi[i]);
	}
	altezza++;
	//cout << endl << altezza << endl;
	
	/*for (int i=0; i<altezza; i++){
		cout << i + 1 << " ";
		for(auto n: livelli[i])
			cout << n->R << " " << n->C << " ";
		cout << endl;
		
	}*/
	bool swap = true;
	int contatore = 0;
	while (swap == true)
	{
		swap = false;
		for (int i = altezza - 1; i > 0; i--)
		{
			auto n = maggiore(livelli[i]);//max_element(livelli[i].begin(), livelli[i].end());
			//cout << "Nodo maggiore" << n->R << " " << n->C << endl;
			if (n->C > nodi[n->R].C)
			{
				int temp = nodi[n->R].C;
				nodi[n->R].C = n->C;
				n->C = temp;
				swap = true;
				contatore++;
			}
			/*
			cout << "Nodo maggiore" << (*n)->R << " " << (*n)->C << endl;
			if ((*n)->C > nodi[(*n)->R].C)
			{
				int temp = nodi[(*n)->R].C;
				nodi[(*n)->R].C = (*n)->C;
				(*n)->C = temp;
				swap = true;
			}*/
		}
	}
	
	//cout << contatore << endl;
	for (int i=0; i<altezza; i++){
		//cout << i + 1 << " ";
		//for(auto n: livelli[i])
			//cout << n->R << " " << n->C << " ";
		//cout << endl;
		livelli[i].clear();
	}
	
	return contatore;
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
