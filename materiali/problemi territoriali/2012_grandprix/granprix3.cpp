/* Soluzione di Alessandro Bugatti 20/4/2012 */
/*Versione ancora più astuta*/

#include <fstream>
#include <iostream>
using namespace std;

int primo;
int N,M;
	
int main()
{
	fstream in,out;
	in.open("input.txt",ios::in);
	out.open("output.txt",ios::out);
	in >> N >> M;
	in >> primo;
	//Serve solo ad avanzare nella lettura
	for (int i=2;i <= N;i++)
	{	
		int temp;
		in >> temp;
	}
	for (int i=0;i < M;i++)
	{
		int A, B;
		in >> A >> B;
		if (B == primo)
			primo = A;
	}
	out << primo << endl;	
	return 0;
}	
