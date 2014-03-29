/*
  Name: chimico.cpp
  Copyright: GPL
  Author: Alessandro Bugatti
  Date: 26/01/05 15.59
  Description: Soluzione del problema Chimico delle regionali
  IOI 2005
*/

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int A; //Aminozalina
int B; //Brinofulo
int N; //numero di contenitori

struct bidone
{
    int posizione;
    int capacita;
    int riempito; //0 = vuoto, 1 = Aminozalina 2 = Brinofulo
};

bidone bidoni[100];

int compare_posizione(const void *a, const void *b)
{
  bidone ba = *(const bidone *) a;
  bidone bb = *(const bidone *) b;

  return (ba.posizione > bb.posizione) - (ba.posizione < bb.posizione);
}

int compare_capacita(const void *a, const void *b)
{
  bidone ba = *(const bidone *) a;
  bidone bb = *(const bidone *) b;

  return (ba.capacita > bb.capacita) - (ba.capacita < bb.capacita);
}

int main(int argc, char *argv[])
{
    fstream in,out;
    in.open("input.txt",ios::in);
    if (in.fail()) exit(1);
    out.open("output.txt",ios::out);
    if (out.fail()) exit(1);
    in >> A >> B >> N;
    for (int i=0; i<N; i++)
    {
        bidoni[i].posizione=i;
        in >> bidoni[i].capacita;
        bidoni[i].riempito=0;
    }
    //Ordino i bidoni in base alla capacita
    qsort(bidoni,N,sizeof(bidone),compare_capacita);
    //Svuoto tutta la Aminozalina
    for (int i=0; i<N && A > 0;i++)
    {
        A-=bidoni[i].capacita;
        bidoni[i].riempito=1;
    }
    //Svuoto tutto il Brinofulo stando attento che riempia completamente
    //il contenitore. Con l'Aminozalina questo controllo potevo non farlo
    //perchè se non riusciva a riempirlo non avrebbe sicuramente riempito
    //il successivo, il chè sarebbe stato contro le ipotesi del problema
    for (int i=N-1; i>=0 && B > 0; i--)
    {
        if (B >= bidoni[i].capacita)
        {
            B-=bidoni[i].capacita;
            bidoni[i].riempito=2;
        }
    }
    //Riordino i contenitori in base alla posizione
    qsort(bidoni,N,sizeof(bidone),compare_posizione);
    //Stampo il risultato
    for (int i=0; i<N ; i++)
        if (bidoni[i].riempito == 0)
            out << "0 0" << endl;
        else if(bidoni[i].riempito == 1)
            out << bidoni[i].capacita << " 0" << endl;
        else
            out << "0 " << bidoni[i].capacita << endl;
    in.close();
    out.close();
    return EXIT_SUCCESS;
}
