/* Soluzione di Alessandro Bugatti 1/2/2008 */
/*Versione ricorsiva*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Missione{
	int durata;
	int fine;
};

//Ordinamento per intervallo di fine in senso crescente
bool compare_missioni(const Missione &a, const Missione &b)
{
    if (a.fine - a.durata < b.fine - b.durata)
        return true;
    return false;
}

/*bool compare_missioni(const Missione &a, const Missione &b)
{
    if (a.durata < b.durata)
        return true;
    else if (a.durata > b.durata)
        return false;
	else if (a.fine < b.fine)
		return true;
	else
		return false;
}*/

Missione missioni[100];
int N;
	
int main()
{
	fstream in,out;
	in.open("input.txt",ios::in);
	out.open("output.txt",ios::out);
	in >> N;
	for (int i=0;i < N;i++)
		in >> missioni[i].durata >> missioni[i].fine;
	sort(missioni,missioni+N,compare_missioni);
	int fine_attuale = missioni[0].durata;
    int numero_missioni = 1;
    for (int i=1; i<N; i++)
    {
        if (fine_attuale <= missioni[i].fine - missioni[i].durata)
        {
            fine_attuale = fine_attuale + missioni[i].durata;
            numero_missioni++;
        }
    }
    out << numero_missioni << endl;
	return 0;
}	
