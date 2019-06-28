#include <iostream>
#include <cstdio>

using namespace std;

int solve() {
    int N;
    cin >> N;

    int risposta = 0;  // memorizza qui la risposta

	int in = 0, out = 0;

    for (int i=0; i<N; i++) {
        int variazione;
        cin >> variazione;
		if (variazione > 0)
		{
			if (out > 0)
				out--;
			else
				risposta++;
			in++;
		}		
		else
		{
			if (in > 0)
				in--;
			else
				risposta++;
			out++;
		}
		
        
    }

    return risposta;
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    scanf("%d", &T);

    for (t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}

