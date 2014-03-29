/* Soluzione di Alessandro Bugatti 1/2/2008 */
/*Versione ricorsiva*/

#include <fstream>

using namespace std;

struct Missione{
	int durata;
	int fine;
};

Missione missioni[100];
int N;
	
int calcola(int missione, int giorno)
{
	if (missione == N) return 0;
	int fatta = 0, nonfatta;
	//Faccio la missione
	if ( giorno + missioni[missione].durata <= missioni[missione].fine)
	  fatta = 1 + calcola(missione + 1, giorno + missioni[missione].durata);
	//non la faccio
	nonfatta = calcola(missione + 1, giorno);	
	if (fatta > nonfatta)
		return fatta;
	else 
		return nonfatta;
}
	

int main()
{
	fstream in,out;
	in.open("input.txt",ios::in);
	out.open("output.txt",ios::out);
	in >> N;
	for (int i=0;i < N;i++)
		in >> missioni[i].durata >> missioni[i].fine;
    out << calcola(0,0);	
	return 0;
}	
