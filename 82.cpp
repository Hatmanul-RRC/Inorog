#include<iostream>
#include<fstream>
using namespace std;
int m,n,v[100][100],x[100],u,d;
int main ()
{
ifstream f("82input.in");
ofstream g("82output.out");
f>>m;
f>>n;
for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
      f>>v[i][j];
f.close();

for(int i=1;i<=n;i++)
{
 for(int j=1;j<=m;j++)
 {
    if(v[j][i]==0 && u==0)
    {
     u=j;
     d=j;
    }
    else if(v[j][i]==0 && u!=0)
              d=j;

    if(v[j][i]==1 && u!=0)
    {
        x[d-u+1]++;
        u=0;
    }

  if(v[m][i]==0 && u!=0 && j==m)
    {
     x[m-u+1]++;
     u=0;
    }
 }
}
for(int i=1;i<=m;i++)
    if(x[i]!=0)
    g<<x[i]<<" blocuri de inaltimea "<<i<<endl;

g.close();
}
