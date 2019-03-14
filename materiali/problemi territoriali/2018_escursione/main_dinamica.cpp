#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int mappa[100][100];
int soluzione[100][100];
int H, W;

void visita(int r, int c, int salto)
{
	if (r == H - 1 && c == W - 1)
        return;
    struct {
		int i, j;
	} direzioni[] = {{1,0},{0,1},{-1,0},{0,-1}};
    //Esploro le quattro direzioni
    for (int d = 0; d < 4; d++)
    {
		int i = direzioni[d].i, j = direzioni[d].j;
		
		if (r+i >= 0 && c+j >= 0 && r+i < H && c+j < W)
			{
				if (salto < abs(mappa[r][c] - mappa[r+i][c+j]))
					salto = abs(mappa[r][c] - mappa[r+i][c+j]);
				if (salto < soluzione[r+i][c+j])
				{
					soluzione[r+i][c+j] = salto;
					visita(r+i,c+j, salto);
				}
			}
	}
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
            for (int j = 0; j < W; j++){
                in >> mappa[i][j];
				soluzione[i][j] = 10000000;
			}
        visita(0,0,0);
        out << soluzione[H-1][W-1] << endl;
        cout << "Case #" << test << " finished" << endl;
    }
    return 0;
}
