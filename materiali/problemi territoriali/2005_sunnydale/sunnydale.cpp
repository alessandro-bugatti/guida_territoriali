/*
 *      Problema sunny - selezioni territoriali 2005
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

using namespace std;

int N; //numero di svincoli
int M; //numero di gallerie
int H; //svincolo di Harmony
int S; //svincolo di Spike

struct svincolo{
    int svincoloCollegato;
    int luce;
	svincolo():luce(100000){}
};

//Ne metto 50001 così posso evitare di modificare gli indici degli svincoli
//che partono da 1 e non da zero
svincolo svincoli[50001];
bool visitato[50001];

int main(int argc, char *argv[])
{
    fstream in,out;
    in.open("input.txt",ios::in);
    out.open("output.txt",ios::out);
    in >> N >> M >> H >> S;
    for (int i=1;i<=N;i++)
		visitato[i] = false;
    for (int i=1;i<=M;i++)
    {
        int A, B, L;
        in >> A >> B >> L;
        if (svincoli[A].luce > L)
            {
                svincoli[A].luce = L;
                svincoli[A].svincoloCollegato = B;
            }
        if (svincoli[B].luce > L)
        {
            svincoli[B].luce = L;
            svincoli[B].svincoloCollegato = A;
        }
   }
   int corrente = H;
   int gallerie = 0;
   while(corrente != S && !visitato[corrente])
   {
	   visitato[corrente] = true;
       gallerie++;
       corrente = svincoli[corrente].svincoloCollegato;
   }
   if (corrente == S)
       out << gallerie << endl;
   else
        out << "-1" << endl;    
   return 0;
}
