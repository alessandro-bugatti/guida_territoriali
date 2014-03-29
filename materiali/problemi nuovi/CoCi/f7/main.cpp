#include <iostream>
#include <algorithm>

using namespace std;

int punteggi[300000];

int main()
{
    int N;
    int quanti=0;
    cin >> N;
    for (int i=0; i<N ; i++)
        cin >> punteggi[i];
    sort(punteggi, punteggi + N);
    reverse(punteggi, punteggi+N); //solo per rendere il codice più "naturale"
    int minimo = 0;
    for (int i = 0; i < N; i++)
        if (punteggi[i] + i + 1 > minimo) minimo = punteggi[i] + i + 1;
    for (int i = 0; i < N; i++)
        if (punteggi[i]+N >= minimo) quanti++;
    cout << quanti << endl;
    return 0;
}
