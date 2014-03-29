#include <fstream>
#include <iostream>

using namespace std;

struct resti{
	int valore;
	int quanti;
	resti():valore(0),quanti(0){}
};

resti monete[100];
resti temp[100];
int massimo;
int N,R,possibilita=0;

int calcolaSomma()
{
	int somma = 0;
	for (int i=0;i<=massimo;i++) if (temp[i].quanti == -1) return -1;
	for (int i=0;i<=massimo;i++) somma += temp[i].valore * temp[i].quanti;
	return somma;
}

void stampaMonete()
{
	for (int i=0;i<=massimo;i++) if (temp[i].quanti == -1) return ;
	for (int i=massimo;i>=0;i--)
		cout << temp[i].quanti << "*" << temp[i].valore << " ";
	if (calcolaSomma() == R) cout << "trovato";
	cout << endl;
}

void calcolaResti(int livello)
{
	if (livello == -1) return;
	//cout << "livello " << livello << endl;
	int i = monete[livello].quanti;
	while (i >= 0)
	{
		temp[livello].quanti = i;
		calcolaResti(livello - 1);	
		//stampaMonete();
		if (calcolaSomma() == R) possibilita++;
		i--;
	}	
	temp[livello].quanti=-1;
}

int main()
{
	
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> R;
	for (int i=0;i<N;i++){
		in >> monete[i].valore;	
		temp[i]=monete[i];
	}
	//Calcolo il numero massimo di monete che potrebbero comparire nel reseto per ogni taglio
	for (int i=0;i<N;i++)
		monete[i].quanti = R/monete[i].valore;
	//Trovo la massima moneta che può essere data di resto
	int l=0;
	while (l<N && monete[l].quanti != 0) l++;
	massimo = --l;
	calcolaResti(l);
  	out << possibilita;
	return 0;
}
