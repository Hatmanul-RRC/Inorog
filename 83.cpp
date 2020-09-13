#include<iostream>
#include<fstream>
using namespace std;
int m,n,v[100][100],k,nr_vecini,x[100][100];
char s;
int main ()
{
    fstream f("83input.in");
    ofstream g("83output.out");
///
f>>m;
f>>n;
f>>k;
for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    {
      f>>s;
      if(s=='*')
      v[i][j]=3;
      else v[i][j]=0;
    }
  ///

for(int i=1;i<=k;i++)
{   ///
    for(int f=1;f<=m;f++)
    for(int j=1;j<=n;j++)
      x[f][j]=v[f][j];

    for(int l=1;l<=m;l++)
    for(int d=1;d<=n;d++)
    {
     nr_vecini=0;
     if(x[l][d+1]) nr_vecini++;
     if(x[l][d-1]) nr_vecini++;
     if(x[l+1][d]) nr_vecini++;
     if(x[l-1][d]) nr_vecini++;
  /*   if(x[l-1][d-1]) nr_vecini++;
     if(x[l+1][d+1]) nr_vecini++;
     if(x[l-1][d+1]) nr_vecini++;
     if(x[l+1][d-1]) nr_vecini++; */
    if(nr_vecini<2 || nr_vecini>3)
        v[l][d]=1;
    else if(nr_vecini==2 && v[l][d]==0)
            v[l][d]=4;
    else  if(nr_vecini==3 && v[l][d]==0)
            v[l][d]=4;
    }
    ///
    for(int h=1;h<=m;h++)
     for(int b=1;b<=n;b++)
      if(v[h][b])
       v[h][b]--;
 /*   for(int h=1;h<=m;h++)
    {
     for(int b=1;b<=n;b++)
     {
         g<<v[h][b]<<" ";
     }
     g<<endl;
    }
    g<<endl; */
}
///
for(int i=1;i<=m;i++)
{
    for(int j=1;j<=n;j++)
        if(v[i][j]!=0)
         g<<" * ";
    else g<<" _ ";

 g<<endl;
}

}
