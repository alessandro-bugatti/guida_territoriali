#include <stdlib.h>
#include <stdio.h>

struct collegamento{
	int verso;
	int costo;
};
typedef struct collegamento collegamento;

struct piazza{
	int tempo;
	collegamento collegamenti[10000];
	int quanti;
};
typedef struct piazza piazza;
piazza piazze[1001];

int N, M;

void visita (int p)
{
	int i;
	for (i = 0; i < piazze[p].quanti ; ++i)
	{
		if (piazze[piazze[p].collegamenti[i].verso].tempo > piazze[p].tempo + piazze[p].collegamenti[i].costo)
		{
			piazze[piazze[p].collegamenti[i].verso].tempo = piazze[p].tempo + piazze[p].collegamenti[i].costo;
			visita(piazze[p].collegamenti[i].verso);
		}
	}
}

int main()
{
	FILE *in = fopen("input.txt","r");
	FILE *out = fopen("output.txt","w");
	fscanf(in,"%d %d",&N, &M);
	int i;
	for (i = 2; i <= N; i++)
	{
		piazze[i].tempo = 1000000000;
		piazze[i].quanti = 0;
	}
	for (i = 0; i < M; i++)
	{
		int a, b, c;
		fscanf(in,"%d %d %d",&a, &b, &c);
		piazze[a].collegamenti[piazze[a].quanti].verso = b;
		piazze[a].collegamenti[piazze[a].quanti].costo = c;
		piazze[a].quanti++;
		piazze[b].collegamenti[piazze[b].quanti].verso = a;
		piazze[b].collegamenti[piazze[b].quanti].costo = c;
		piazze[b].quanti++;
	}
	piazze[1].tempo = 0;
	visita(1);
	int totale = 0;
	for (i = 2; i <= N; i++)
	{
		if (piazze[i].tempo <= i*10)
			totale++;
	}
	fprintf(out, "%d\n", totale+1);

	return  0;
}
	
