/*Barbablù - regionali  2012 */

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

#define INFINITO 1000000

struct corridoio{
	int porta_a, lunghezza;
	corridoio(int p, int l):porta_a(p), lunghezza(l){}
};

struct cabina{
	bool aria;
	list <corridoio> corridoi;
	int distanza;
	int ossigeno_rimasto;
	cabina():aria(false), distanza(INFINITO),ossigeno_rimasto(20){}
	void stampa(){ cout << "A: " << aria << " D: " << distanza <<
		" O: " << ossigeno_rimasto << endl;
		list <corridoio> :: iterator i;
		for (i = corridoi.begin() ; i != corridoi.end(); i++)
			cout << "\t\t-> " << i->porta_a << " L: " << i->lunghezza << endl;
	}
};

cabina cabine[31];
	
int N,M,C,K;

queue <int> coda;

void visita()
{	
	while (!coda.empty())
	{
		int c = coda.front();
		coda.pop();
		list <corridoio>::iterator i;
		for (i = cabine[c].corridoi.begin() ; i != cabine[c].corridoi.end(); i++)
		{
			if (i->lunghezza < cabine[c].ossigeno_rimasto)
			{
				if (cabine[c].distanza + i->lunghezza < cabine[i->porta_a].distanza)
				{
					cabine[i->porta_a].distanza = cabine[c].distanza + i->lunghezza;
					if (cabine[i->porta_a].aria == false)
						cabine[i->porta_a].ossigeno_rimasto =
							cabine[c].ossigeno_rimasto - i->lunghezza;
					coda.push(i->porta_a);
				}
			}
		}
	}
}
	
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> M >> C >> K;
	for (int i = 0; i < K; i++)
	{
		int temp;
		in >> temp;
		cabine[temp].aria = true;
	}
	for (int i = 0; i < M; i++)
	{
		int r,s,t;
		in >> r >> s >> t;
		corridoio c(s,t);
		cabine[r].corridoi.push_back(c);
		corridoio d(r,t);
		cabine[s].corridoi.push_back(d);
	}
	//for (int i = 1; i <= N; i++)
	//	cout << i , cabine[i].stampa();
	coda.push(1);
	cabine[1].distanza = 0;
	visita();
	if (cabine[C].distanza == INFINITO)
		out << "-1" << endl;
	else
		out << cabine[C].distanza << endl;
	return 0;
}
