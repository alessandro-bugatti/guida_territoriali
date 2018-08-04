#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <cmath>

using namespace std;

struct Arco{
    int nodo;
    int peso;
    Arco(int p, int n):peso(p), nodo(n){}
};

list <Arco> nodi[10000];
int costo[10000];
priority_queue <pair<int,int> > coda;
int mappa[100][100];
int soluzione;
int H, W;

void dijkstra()
{
    coda.push(make_pair(0,0));
    costo[0] = 0;
    while(!coda.empty())
    {
        int nodo = coda.top().second;
        int peso = coda.top().first;
        coda.pop();
        for (auto i: nodi[nodo])
        {
            int massimo = peso > i.peso?peso:i.peso;
            if (costo[i.nodo] > massimo)
            {
                costo[i.nodo] = massimo;
                coda.push(make_pair(massimo,i.nodo));
            }
        }
    }
}
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int T;
    in >> T;
    for (int test = 1; test <= T; test++)
    {
        out << "Case #" << test << ": ";
        in >> H >> W;
        for (int i = 0 ; i < H*W; i++)
            costo[i] = 10000000;
        while(!coda.empty())
            coda.pop();
        for (int i = 0 ; i < H*W; i++)
            nodi[i].clear();

        for (int i = 0 ; i < H; i++)
            for (int j = 0; j < W; j++)
                in >> mappa[i][j];
        for (int i = 0 ; i < H; i++)
            for (int j = 0; j < W; j++)
            {
                if (i - 1 >= 0)
                    nodi[i*W+j].push_back(Arco(abs(mappa[i][j] - mappa[i-1][j]),(i-1)*W + j));
                if (i + 1 < H)
                    nodi[i*W+j].push_back(Arco(abs(mappa[i][j] - mappa[i+1][j]),(i+1)*W + j));
                if (j - 1 >= 0)
                    nodi[i*W+j].push_back(Arco(abs(mappa[i][j] - mappa[i][j-1]),i*W + j-1));
                if (j + 1 < W)
                    nodi[i*W+j].push_back(Arco(abs(mappa[i][j] - mappa[i][j+1]),i*W + j+1));
            }
        dijkstra();
        /*for (int i = 0 ; i < H*W; i++)
            cout << costo[i] << endl;
        for (int i = 0 ; i < H*W; i++){
            cout << "Nodo" << i << " : ";
            for (auto arco: nodi[i])
                cout << "(" << arco.peso << "," << arco.nodo << ") ";
            cout << endl;
        }*/
        out << costo[H*W - 1] << endl;
        cout << "Case #" << test << " finished" << endl;
    }
    return 0;
}

