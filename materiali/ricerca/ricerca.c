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
 *  \brief Esempio di ricerca in un vettore di interi
 *  utilizzando la funzione di libreria bsearch
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione  05/09/2011
 *  \date  Ultima modifica 05/09/2011
 *
 */

#include <stdlib.h>
#include <stdio.h>

int vettore[10];

//Funzione di comparazione
int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int i,n;
    //inserisco dieci numeri casuali
    for (i=0; i<10; i++)
        vettore[i] = rand()%100;
    //ordino il vettore
    qsort(vettore, 10, sizeof(int), cmp);
    //mostro a video gli elementi per facilitare le prove
    for (i=0; i<10; i++)
        printf("%d\n",vettore[i]);
    printf("Inserisci il numero da cercare (-1 per terminare): \n");
    scanf("%d",&n);
    while (n!= -1)
    {
        int *cercato;
        cercato = (int*) bsearch (&n, vettore, 10, sizeof (int), cmp);
        if (cercato!=NULL)
            printf ("Trovato %d.\n",*cercato);
        else
            printf ("Non trovato.\n");
        printf("Inserisci il numero da cercare (-1 per terminare): \n");
        scanf("%d",&n);
    }
    return 0;
}
