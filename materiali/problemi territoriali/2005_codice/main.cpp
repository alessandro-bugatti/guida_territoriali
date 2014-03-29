#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map <char,char> mappaVocali;
map <char,char> mappaConsonanti;
int N;
char buffer[81];

bool vocale(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}

int main(int argc, char *argv[])
{
    fstream in,out;
    in.open("input.txt",ios::in);
    if (in.fail())
    {
        cerr << "Impossibile aprire il file di input " << endl;
        exit(1);
    }
    out.open("output.txt",ios::out);
    if (out.fail())
    {
        cerr << "Impossibile aprire il file di output " << endl;
        exit(1);
    }
    //Creo la mappa delle vocali
    mappaVocali['a']='e';    
    mappaVocali['e']='i';
    mappaVocali['i']='o';
    mappaVocali['o']='u';
    mappaVocali['u']='y';
    mappaVocali['y']='a';
    //Creo la mappa delle consonanti
    mappaConsonanti['b']='c';    
    mappaConsonanti['c']='d';
    mappaConsonanti['d']='f';
    mappaConsonanti['f']='g';
    mappaConsonanti['g']='h';
    mappaConsonanti['h']='j';
    mappaConsonanti['j']='k';    
    mappaConsonanti['k']='l';
    mappaConsonanti['l']='m';
    mappaConsonanti['m']='n';
    mappaConsonanti['n']='p';
    mappaConsonanti['p']='q';
    mappaConsonanti['q']='r';    
    mappaConsonanti['r']='s';
    mappaConsonanti['s']='t';
    mappaConsonanti['t']='v';
    mappaConsonanti['v']='w';
    mappaConsonanti['w']='x';
    mappaConsonanti['x']='z';    
    mappaConsonanti['z']='b';
    in >> N;
    in.getline(buffer,80);
    for (int i=0; i<N; i++)
    {
        in.getline(buffer,80);
        for (int i=0;buffer[i]!='\0';i++)
        {
            bool flag=false;
            char temp;
            char c=tolower(buffer[i]);
            if (c!=buffer[i]) flag=true;
            if (c>='a' && c<='z')
            {
                //se è una vocale
                if (vocale(c))
                    temp=mappaVocali[c];
                else 
                    temp=mappaConsonanti[c];
                if (flag) temp=toupper(temp);
                out << temp;
            }
            else if (c>='0' && c<='9')
                out << ((c-'0')+1)%10;
            else
                out << c;
        }
        out << endl;
    }            
    return EXIT_SUCCESS;
}
