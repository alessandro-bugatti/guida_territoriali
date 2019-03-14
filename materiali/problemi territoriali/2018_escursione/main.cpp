#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int mappa[100][100];
int soluzione;
int H, W;

void visita(int r, int c, int salto)
{
	if (salto >= soluzione)
        return;
    if (r == H - 1 && c == W - 1)
    {
        soluzione = salto;
        return;
    }
    int temp = mappa[r][c];
    mappa[r][c] = -1;
    struct {
		int i, j;
	} direzioni[] = {{1,0},{0,1},{-1,0},{0,-1}};
    //Esploro le quattro direzioni
    for (int d = 0; d < 4; d++)
    {
		int i = direzioni[d].i, j = direzioni[d].j;
		if (r+i >= 0 && c+j >= 0 && r+i < H && c+j < W &&
			mappa[r+i][c+j] != -1)
			{
				if (salto > abs(temp - mappa[r+i][c+j]))
					visita(r+i,c+j, salto);
				else
					visita(r+i,c+j, abs(temp - mappa[r+i][c+j]));
			}
	}
    mappa[r][c] = temp;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int T;
    in >> T;
    for (int test = 1; test <= T; test++)
    {
        out << "Case #" << test << ": ";
        in >> H >> W;
        for (int i = 0 ; i < H; i++)
            for (int j = 0; j < W; j++)
                in >> mappa[i][j];
        soluzione = 10000000;
        visita(0,0,0);
        out << soluzione << endl;
        cout << "Case #" << test << " finished" << endl;
    }
    return 0;
}
