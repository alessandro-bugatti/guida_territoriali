#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int mappa[100][100];
int soluzione;
int H, W;

int inizializza(int h, int w)
{
    int massimo = 0;
    for (int i = 1 ; i < w; i++)
        if (abs(mappa[0][i] - mappa[0][i-1]) > massimo)
            massimo =  abs(mappa[0][i] - mappa[0][i-1]);
    for (int i = 1 ; i < h; i++)
        if (abs(mappa[i][w - 1] - mappa[i-1][w-1]) > massimo)
            massimo =  abs(mappa[i][w-1] - mappa[i-1][w-1]);
    return massimo;
}

void visita(int r, int c, int salto)
{

    /*int salto_corrente = abs(mappa[ri][ci] - mappa[r][c]);
    cout << ri << "  " << ci  << " " << r << "  " << c  << " "
    << salto_corrente << endl;
    if (salto_corrente > salto)
        salto = salto_corrente;*/
    //cout << "->" << r << " " << c << " " <<
    //    salto << " " << soluzione << endl;
    if (salto >= soluzione)
    {
        //cout << "return ->" << r << " " << c << " "
        //    << salto << " " << soluzione << endl;
        return;
    }

    if (r == H - 1 && c == W - 1)
    {
        //cout << "Trovato " << salto << "->" << r << " " << c << endl;
        soluzione = salto;
        return;
    }
    int temp = mappa[r][c];
    mappa[r][c] = -1;
    int i = 1, j = 0;
    if (r+i >= 0 && c+j >= 0 && r+i < H && c+j < W &&
        mappa[r+i][c+j] != -1)
                {
                    if (salto > abs(temp - mappa[r+i][c+j]))
                        visita(r+i,c+j, salto);
                    else
                        visita(r+i,c+j, abs(temp - mappa[r+i][c+j]));
                }
    i = 0, j = 1;
    if (r+i >= 0 && c+j >= 0 && r+i < H && c+j < W &&
        mappa[r+i][c+j] != -1)
                {
                    if (salto > abs(temp - mappa[r+i][c+j]))
                        visita(r+i,c+j, salto);
                    else
                        visita(r+i,c+j, abs(temp - mappa[r+i][c+j]));
                }
    i = -1, j = 0;
    if (r+i >= 0 && c+j >= 0 && r+i < H && c+j < W &&
        mappa[r+i][c+j] != -1)
                {
                    if (salto > abs(temp - mappa[r+i][c+j]))
                        visita(r+i,c+j, salto);
                    else
                        visita(r+i,c+j, abs(temp - mappa[r+i][c+j]));
                }
    i = 0, j = -1;
    if (r+i >= 0 && c+j >= 0 && r+i < H && c+j < W &&
        mappa[r+i][c+j] != -1)
                {
                    if (salto > abs(temp - mappa[r+i][c+j]))
                        visita(r+i,c+j, salto);
                    else
                        visita(r+i,c+j, abs(temp - mappa[r+i][c+j]));
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
        soluzione = inizializza(H,W);
        visita(0,0,0);
        out << soluzione << endl;
        cout << "Case #" << test << " finished" << endl;
    }
    return 0;
}
