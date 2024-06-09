#include "dynamicarray.h"

using namespace std;

int deg(vec<int> *mat, int a)
{
    int fin=0;
    for(int i=1; i<mat[a].size(); i++)
    {
        if(mat[a][i]==1)
        {
            fin++;
        }
    }
    return fin;
}

void innit(vec<int> *mat, int siz, int k)
{
//cout<<"hi init, k = "<<k<<endl;
    for(int i=1; i<siz; i++)
    {
        for(int j=1;j<mat[i].size() ; j++)
        {
            mat[i](j)=0;
        }
    }

    for(int i=1; i<=k; i++)
    {
        for(int j=1;j<=k ; j++)
        {
            if(i!=j)
            {
//cout<<i<<'\t'<<j<<endl;
                mat[i](j)=1;
//                mat[j](i)=1;
            }
        }
    }

}

void grw(vec<int> *mat, int siz, int lvl,int k)
{
   
    int a,b;
    int i = k;
    while(i<=lvl)
    {
        a=rand()%siz+1;
        b=rand()%siz+1;
/*
cout<<"a = "<<a<<", b = "<<b<<endl;
cout<<mat[a].size()<<'\t'<<mat[b].size()<<'\t'<<mat[a][b]<<endl;
cout<<"if condition is: "<<((mat[a].size()>=(k-1) || mat[b].size()>=(k-1)) && a!=b && mat[a][b] !=1)<<endl;
cout<<"detail of if condition is: "<<(mat[a].size()>=(k-1) || mat[b].size()>=(k-1))<<'\t'<< (a!=b) <<'\t'<< (mat[a][b] !=1)<<endl;
cout<<"detail of the first term is: "<<(mat[a].size()>=(k-1))<<'\t'<<( mat[b].size()>=(k-1))<<endl;
*/

        if((mat[a].size()>=(k-1) || mat[b].size()>=(k-1)) && a!=b && mat[a][b] !=1)
        {
//cout<<"a = "<<a<<", b = "<<b<<endl;
//cout<<"i = "<<i<<endl;
            mat[a](b)=1;
            mat[b](a)=1;
	    i++;
        }
    }

}

double p(vec<int> *mat, int siz, int k)
{
    double cnt=0;
    for(int i=1; i<=siz; i++)
    {
        if(mat[i].size()>=k)
        {
            cnt++;
        }
    }

    return cnt/siz;
}

int main(int argc, char **argv)
{

	int size, link, k;
	if(argc ==4){
		size = atoi(argv[1]);
		link = atoi(argv[2]);
		k = atoi(argv[3]);
	}else{
		cout<<"wrong number of arguments\n";
		return 0;
	}
//	cout<<"argc = "<<argc<<" size = "<<size<<" link = "<<link<<" and k = "<<k<<endl;

	vec<int> *mat;
	mat = new vec<int> [size];
	mat -=1;
	for(int i=1; i<=size; i++) mat[i].resize(0);


        innit(mat,size,k);
/*
cout<<"mat after innit\n";
	for(int i=1; i<=size; i++){
		cout<<i<<'\t';
		for(int j=1; j<=mat[i].size(); j++) cout<<"mat["<<i<<"]["<<mat[i].row(j)<<"]="<<mat[i][mat[i].row(j)]<<'\t';
		cout<<'\n';
	}
*/
        grw(mat,size,link,k);
/*
cout<<"mat after grw\n";
	for(int i=1; i<=size; i++){
		cout<<i<<'\t';
		for(int j=1; j<=mat[i].size(); j++) cout<<"mat["<<i<<"]["<<mat[i].row(j)<<"]="<<mat[i][mat[i].row(j)]<<'\t';
		cout<<'\n';
	}
*/
//cout<<"rows and columns:\n";

	for(int i=1; i<=size; i++){
		cout<<i<<'\t';//<<mat[i].size()<<'\t';
		for(int j=1; j<=mat[i].size(); j++) cout<<mat[i].row(j)<<" ";
		cout<<'\n';
	}

/*
	for(int i=1; i<=size; i++){
		cout<<i<<'\t'<<mat[i].size()<<'\n';
	}
*/
}
