/* Olimpiadi di Informatica - Regionali 2008
 Soluzione per problema: MISSIONI
proposta da:  Carlo Salvagno 2008 - Referente Regionale VEN1 - ITIS  "C. Zuccante"- Mestre (VE)

IDEA RISOLUTIVA (versione con programmazione dinamica)

  Si tiene traccia, per ogni giorno dell'anno, del numero massimo di missioni che
  possono essere portate a termine fino a quel giorno.
  A tal fine utilizziamo il vettore maxMissioni di 366 elementi e maxMissioni[p]
  rappresenta il numero massimo di missioni che si possono portare a termine
  avendo a disposizione i primi p giorni dell'anno. E' evidente che se per portare
  a termine k missioni servono j giorni, con j <=365, e nell'ipotesi che non ci
  siano altre missioni, k è anche il numero massimo di missioni effettuabili in
  un anno.
  Il numero di missioni portate a termine, prima del primo gennaio, è 0.
  Per evitare di analizzare inutilmente elementi di maxMissioni non coinvolti,
  tutti gli altri elementi vengono inizializzati ad un valore negativo.
  Pertanto, dato un appuntamento che deve terminare entro termineg e che richiede
  d giorni per lo svolgimento, per rispettare il termine questo deve iniziare
  almeno il giorno j=termineg-d. Quindi a partire dal giorno j e retrocedendo fino
  all'inizio dell'anno si considerano tutti i giorni g in cui sono state
  portate a termine delle missioni assegnando a maxMissioni[j+d] il
  massimo tra  maxMissioni[j+d] e  1 + maxMissioni[j].
  Il risultato è il massimo dei valori presenti in maxMissioni.

*/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
/* ------------------------------------------------------------ */
int massimo(int n, int m) {
  return (n > m) ? n : m;
}
/* ------------------------------------------------------------ */
int main(int argc, char *argv[]) {
  const int NON_USATO = -1;
  ifstream in("input.txt");
  ofstream out("output.txt");
  int ultimo, i;
  int *durata, *termine;
  int n, max=0, j, fine;
  int  maxMissioni[366];

  /* -- Lettura input -- */

  in >> n;

  durata = new int[n];
  termine = new int[n];

  // lettura durate e scadenze
  for (int  i = 0 ; i < n ; i++ )  {
    in >> durata[i] >> termine[i];
  }
  //inizializzazioni
  maxMissioni[0] = 0;
  for (int  i = 1 ; i < 366 ; i++ )  {
    maxMissioni[i] = NON_USATO;
  }
  //ciclo di calcolo
  for (int  i = 0 ; i < n ; i++ )  {
    for (int j= termine[i] - durata[i]; j >= 0; j--)
       if (maxMissioni[j]>=0) { // j è giorno usato
         fine = j + durata[i]; // fine viene usato
         maxMissioni[fine] = massimo( maxMissioni[fine], maxMissioni[j]+1);
         max = massimo(max,  maxMissioni[fine]);
       }
  }
  //cout <<max <<"\n";
  out <<max <<"\n";
  out.close();
  in.close();
 // system("PAUSE");
  return 0;
}
