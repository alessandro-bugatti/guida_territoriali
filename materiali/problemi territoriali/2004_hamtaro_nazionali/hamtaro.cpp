/*
 *      Problema hamtaro - selezioni nazionali 2004
 *      
 *      Copyright 2011 Alessandro Bugatti <alessandro.bugatti@istruzione.it>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//Struttura che rappresenta la macchina
struct macchina{
    int costo; //costo a criceto
    int quanti; //numero di criceti trasportabili
};
//Vettore che contiene le macchine
macchina macchine[100000];
//N=numero di Hamtaro M=numero di macchine
int N,M;

//Funzione per il confronto tra macchine, per ordinare dalla più economica 
int compare_cost(const void *a, const void *b)
{
    const macchina *c=(const macchina *)a;
    const macchina *d=(const macchina *)b;
    if (c->costo > d->costo) return 1;
    if (c->costo < d->costo) return -1;
    return 0;
}

int main(int argc, char *argv[])
{
  fstream in("input.txt",ios::in);
  fstream out("output.txt",ios::out);
  int finito=0;
  int spesa=0;
  int i;
  in >> N;
  in >> M;
  for (i=0; i<M; i++)
    in >> macchine[i].costo >> macchine[i].quanti;
  //Ordino con la funzione di libreria
  qsort(macchine,M,sizeof(macchina),compare_cost); 
  //Continuo a utilizzare macchine finchè tutti 
  //gli Hamtaro non sono in pizzeria
  for (i=0; finito<N; i++)
  {
    finito+=macchine[i].quanti;
    spesa+=macchine[i].costo*macchine[i].quanti;
  }
  //Tolgo il valore degli eventuali posti vuoti
  //dell'ultimo viaggio
  if (finito>N) spesa-= (finito-N)*macchine[i-1].costo;
  out << spesa;
  return 0;
}
