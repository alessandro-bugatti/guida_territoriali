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
 *  \brief Soluzione del problema tamburello delle territoriali 2010
 *  \author Alessandro Bugatti
 *	
 *  \version 0.1
 *  \date  Creazione  18/04/2010
 *  \date  Ultima modifica 18/04/2010
 *	\attention Per risolvere il problema io ho fatto così: provo a vedere se c'è un periodo
 *  partendo dal periodo 1 e provando tutti quelli che sono sottomultipli della sequenza, fino a lunghezza/2.
 *  Appena lo trovo mi fermo.
 */

#include <cstdio>
#include <cstdlib>


int sequenza[100000];
FILE *in,*out;
int N;

//Controlla se un certo tratto iniziale di lunghezza periodo della sequenza si trova
//a partire dal punto inizio
bool corrispondenza(int inizio, int periodo)
{
	int i;
	for(i=0;i<periodo;i++)
		if (sequenza[i]!=sequenza[i+inizio])
			return false;
	return true;
}

//Verifica se la sequenza ha periodo di lunghezza periodo
bool trova_periodo(int periodo)
{
	int i;
	for (i=periodo;i<N;i+=periodo)
		if (!corrispondenza(i,periodo))
			return false;
	return true;
}

int main()
{
	int i,j;
	in = fopen("input.txt","r");
	out = fopen("output.txt","w");
	fscanf(in,"%d",&N);
	for (i=0;i<N;i++)
		fscanf(in,"%d",&sequenza[i]);
	for (i=1;i<=N/2;i++)
		if(N%i == 0) //Controllo solo le sottosequenze in rapporto intero con la lunghezza della sequenza
			if (trova_periodo(i))//Il primo che trovo è il più corto e quindi lo stampo
			{
				for (j=0;j<i;j++)
					fprintf(out,"%d ",sequenza[j]);
				exit(0);
			}	
	//Se non è periodica
	fprintf(out,"2");
    return 0;
}

