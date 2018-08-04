#include <bits/stdc++.h>

#define INF 1e9
#define MAX_SIZE 100

using namespace std;

int R,C;
int m[MAX_SIZE][MAX_SIZE]; // la tabella
int sol[MAX_SIZE][MAX_SIZE]; // qui dentro mi salvo il minimo valore con cui sono entrato in una certa cella (per valore si intende il massimo dislivello incontrato fino ad ora)

bool isValid(int r, int c)
{
	if (r < 0 || r >= R || c < 0 || c >= C)
		return false;
	return true;
}

void walk(int r, int c, int cur_diff)
{
	if (r == R-1 && c == C-1) // sono arrivato alla fine
		return;

	int ar[4] = {-1, 0, 1, 0}; // le 4 direzioni per le righe (N, W, S, E)
	int ac[4] = {0, -1, 0, 1}; // le 4 direzioni per le colonne (N, W, S, E)

	for(int i=0; i < 4; i++) // per ognuna delle direzioni
	{
		int nr = r + ar[i];
		int nc = c + ac[i];

		if (isValid(nr, nc)) // se non vado fuori dalla mappa
		{
			int next_diff = max(cur_diff, abs(m[r][c] - m[nr][nc])); // calcolo quale sarebbe il dislivello nell'entrarci
			if (next_diff < sol[nr][nc]) // se entrandoci miglioro il dato che c'era dentro (inizialmente impostato a 1 miliardo)
			{
				sol[nr][nc] = next_diff; // aggiorno e ci vado dentro
				walk(nr, nc, next_diff);
			}
		}
	}
}

int main()
{
	int TC;

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> TC;
	for(int tc=1; tc <= TC; tc++)
	{
		out << "Case #" << tc << ": ";

		in >> R >> C;
		for(int i=0; i < R; i++)
		{
			for(int j=0; j < C; j++)
			{
				in >> m[i][j];
				sol[i][j] = INF;
			}
		}

		sol[0][0] = 0;
		walk(0,0,0);
		out << sol[R-1][C-1] << "\n";
	}

	in.close();
	out.close();
	return 0;
}
