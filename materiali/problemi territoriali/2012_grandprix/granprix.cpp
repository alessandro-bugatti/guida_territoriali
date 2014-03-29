/* Soluzione di Alessandro Bugatti 13/4/2012 */
/*Versione ovvia*/

#include <fstream>

using namespace std;

int vetture[31];
int N,M;
	
void sorpasso(int A, int B)
{
	int i;
	for (i=0;i < N;i++)
		if (vetture[i] == A) break;
	int temp = vetture[i];
	vetture[i] = vetture [i-1];
	vetture[i-1] = temp;
}
	
int main()
{
	fstream in,out;
	in.open("input.txt",ios::in);
	out.open("output.txt",ios::out);
	in >> N >> M;
	for (int i=0;i < N;i++)
		in >> vetture[i];
    for (int i=0;i < M;i++)
	{
		int A, B;
		in >> A >> B;
		sorpasso(A,B);
	}
	out << vetture[0];	
	return 0;
}	
