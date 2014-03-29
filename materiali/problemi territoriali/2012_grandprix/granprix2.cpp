/* Soluzione di Alessandro Bugatti 13/4/2012 */
/*Versione astuta*/

#include <fstream>
#include <iostream>
using namespace std;

int vetture[31];
int N,M;
	
	
int main()
{
	fstream in,out;
	in.open("input.txt",ios::in);
	out.open("output.txt",ios::out);
	in >> N >> M;
	for (int i=1;i <= N;i++)
	{	
		int temp;
		in >> temp;
		vetture[temp] = i;
	}
	for (int i=0;i < M;i++)
	{
		int A, B;
		in >> A >> B;
		vetture[A]--;
		vetture[B]++;
	}
	for (int i=1;i <=N;i++)
	{
		if (vetture[i] == 1)	
			out << i << endl;	
	}
	return 0;
}	
