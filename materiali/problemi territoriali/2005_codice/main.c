#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int N;
char buffer[100];
char vocali[]="aeiouy";
char vocaliCambiate[]="eiouya";
char consonanti[]="bcdfghjklmnpqrstvwxz";
char consonantiCambiate[]="cdfghjklmnpqrstvwxzb";

int vocale(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}

char traduciVocali(char c)
{
    int i;
    for (i=0; i<6; i++)
        if (c==vocali[i]) return vocaliCambiate[i];
}

char traduciConsonanti(char c)
{
    int i;
    for (i=0; i<20; i++)
        if (c==consonanti[i]) return consonantiCambiate[i];
}

int main()
{
    FILE *in, *out;
	int i,j;
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
    fscanf(in,"%d",&N);
	fgets(buffer,81,in);
    for (j=0; j<N; j++)
    {
        fgets(buffer,81,in);
        for (i=0;buffer[i]!='\0';i++)
        {
            int flag=0;
            char temp, c=tolower(buffer[i]);
            if (c!=buffer[i]) flag=1;
            if (isalpha(c))
            {
                //se è una vocale
                if (vocale(c))
                    temp=traduciVocali(c);
                else 
                    temp=traduciConsonanti(c);
                if (flag) temp=toupper(temp);
                fprintf(out,"%c",temp);
            }
            else if (isdigit(c))
                fprintf(out,"%d",((c-'0')+1)%10);
            else
                fprintf(out,"%c",c);
        }
    }            
    return 0;
}
