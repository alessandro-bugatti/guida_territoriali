/*
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/*! \file
 *  \brief Esempio di ordinamento di un vettore di strutture in C
 *  utilizzando la funzione di libreria qsort
 *  \author Alessandro Bugatti
 *
 *  \version 0.2
 *  \date  Creazione  19/03/2009
 *  \date  Ultima modifica 19/03/2009
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct persona{
    int peso;
    int altezza;
};

//Ordina per peso, in caso di pesi uguali ordina per altezza
int cmp(const void *a, const void *b)
{
    persona primo = *(persona *)a;
    persona secondo = *(persona *)b;
    if (primo.peso > secondo.peso) return 1;
    if (primo.peso < secondo.peso) return -1;
    if (primo.altezza > secondo.altezza) return 1;
    if (primo.altezza < secondo.altezza) return -1;
    return 0;
}

persona vettore[10];

int main()
{
    //inserisco dieci pesi e altezze casuali, i pesi sono
    //uguali a due a due per mostrare il funzionamento
    //della funzione di comparazione
    for (int i=0; i<10; i+=2)
    {
        vettore[i].peso = vettore[i+1].peso = rand()%60 + 40;
        vettore[i].altezza = rand()%50 + 140;
        vettore[i+1].altezza = rand()%50 + 140;
    }
    printf("Prima dell'ordinamento\n");
    for (int i=0; i<10; i++)
        printf("%d %d\n",vettore[i].peso,vettore[i].altezza);
    qsort(vettore,10,sizeof(persona),cmp);
    printf("Dopo l'ordinamento\n");
    for (int i=0; i<10; i++)
        printf("%d %d\n",vettore[i].peso,vettore[i].altezza);
    return 0;
}
