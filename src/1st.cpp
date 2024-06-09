#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int deg(int** mat, int siz, int a)
{
    int fin=0;
    for(int i=0; i<siz; i++)
    {
        if(mat[a][i]==1)
        {
            fin++;
        }
    }
    return fin;
}

int** innit(int** mat, int siz, int k)
{
    int** fin=mat;
    for(int i=0; i<siz; i++)
    {
        for(int j=0;j<siz ; j++)
        {
            fin[i][j]=0;
        }
    }

    for(int i=0; i<=k; i++)
    {
        for(int j=0;j<=k ; j++)
        {
            if(i!=j)
            {
                fin[i][j]=1;
                fin[j][i]=1;
            }
        }
    }
    return fin;
}

int** grw(int **mat, int siz, int lvl,int k)
{
    int** fin=mat;
    int a,b;
    for(int i=0; i<lvl ; lvl++)
    {
        a=rand()%siz;
        b=rand()%siz;
        if((deg(fin,siz,a)>=k || deg(fin,siz,b)>=k) && a!=b && (deg(fin,siz,a)!=1 && deg(fin,siz,b)!=1))
        {
            fin[a][b]=1;
            fin[b][a]=1;

        }
        else
        {
            lvl--;
        }
    }
    return fin;
}

double p(int** mat, int siz, int k)
{
    int cnt=0;
    for(int i=0; i<siz; i++)
    {
        if(deg(mat,siz ,i)==k)
        {
            cnt++;
        }
    }

    double fin=cnt/siz;
    return fin;
}

main()
{
    ofstream fout("./result.txt");
    int** mat=new int* [100];
    for(int i = 0; i< 100; i++)  mat[i]=new int [100];
    for(int k=1; k<10 ; k++)
    {

        mat=innit(mat,100,k);
        mat=grw(mat,100,100,k);
        fout<<p(mat,100,k)<<endl;
    }
    fout.close();
}
