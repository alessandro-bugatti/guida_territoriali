/*
  Copyright (C) 2010 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

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
 *  \brief Soluzione del problema sbarramento delle territoriali 2010
 *  \author Alessandro Bugatti
 *	
 *  \version 0.1
 *  \date  Creazione  18/04/2010
 *  \date  Ultima modifica 18/04/2010
 *	\attention Per risolvere il problema io ho fatto così: mi sembra un problema greedy
 *  perchè per lo spostamento in direzione nord-sud ogni armata non può fare di meglio
 *  che raggiungere la riga definitiva spostandosi dritta su quella riga, per le colonne
 *	si ordinano le armate per colonna e poi si fa arrivare quella sulla colonna più a sinistra
 *  sulla colonna 1, la seconda sulla colonna 2 e via dicendo.
 *  Non mi sembra che l'assunzione che due armate non possano essere sulla stessa casella contemporaneamente
 *  dia dei problemi, perchè a patto di scegliere opportunamente l'ordine delle mosse questo non succederà
 *  e non dovendo la soluzione indicare le mosse ma sol quante bisogna farle il problema non si pone
 *	
 */

#include <cstdio>
#include <cstdlib>

struct armata{
	int r,c;
};

int N;//numero di righe, di colonne e di armate
int R;//riga dove convergere
armata armate[500];
FILE *in,*out;

int cmp(const void *a, const void *b)
{
	armata uno = *(armata *)a;
	armata due = *(armata *)b;
	if (uno.c > due.c) return 1;
	if (uno.c < due.c) return -1;
	return 0;
}

int main()
{
	int i,j;
	int mosse = 0;
	in = fopen("input.txt","r");
	out = fopen("output.txt","w");
	fscanf(in,"%d %d",&N,&R);
	for (i=0;i<N;i++)
		fscanf(in,"%d %d",&armate[i].r,&armate[i].c);
	qsort(armate,N,sizeof(armata),cmp);
	//Sommo le distanze per ogni armata: il primo addendo è la distanza dell'armata dalla riga obbiettivo
	//il secondo è la distanza della colonna da raggiungere
	for (i=0;i<N;i++)
		mosse+=abs(armate[i].r-R) + abs(armate[i].c - (i+1));
	fprintf(out,"%d\n",mosse);
    return 0;
}

