#include<iostream>
#include<fstream>
using namespace std;
int m,n,v[100][100],i=1,j=1,x=1;
bool c=true;
int main()
{
    ifstream f("85input.in");
    ofstream g("85output.out");
f>>m;
f>>n;
f.close();
while(i<=m && j<=n)
{
    v[i][j]=x++;
    i++;
    j++;
}


while( (i<m+1 && j>0) || (i<m+1 && j<n+1) || (i>0 && j<n+1))
{   c=true;
    //loveste marginea de jos
  if(i==(m+1) && c)
  {
    if(v[i-1][j-1]==(x-1))
    {
    i--;
    j--;
     while(i>=1 && j<=n)
  {
    i--;
    j++;
    if(v[i][j]==0)
   v[i][j]=x++;
 else x++;
  }
    v[i][j]=0;
    x--;
    }
    else if(v[i-1][j+1]==(x-1))
     {
        i--;
        j++;
     while(i>=1 && j>=1)
   {
    i--;
    j--;
   if(v[i][j]==0)
   v[i][j]=x++;
 else x++;
   }
    v[i][j]=0;
    x--;
    }
    c=false;
  }

//lovestea marginea de sus
   if(i==0 && c)
   {
    if(v[i+1][j-1]==(x-1))
    {
     i++;
     j--;
     while(i<=m && j<=n)
   {
     i++;
     j++;
    if(v[i][j]==0)
   v[i][j]=x++;
 else x++;
   }
   v[i][j]=0;
   x--;
   }
   else if(v[i+1][j+1]==(x-1))
    {
     i++;
     j++;
        while(i<=m && j>=1)
    {
     i++;
     j--;
    if(v[i][j]==0)
   v[i][j]=x++;
 else x++;
    }
    v[i][j]=0;
    x--;
    }
    c=false;
   }
   // loveste marginea din dreapta
  if(j==(n+1) && c)
  {
    if(v[i+1][j-1]==(x-1))
    {
    i++;
    j--;
     while(i>=1 && j>=1)
     {
    i--;
    j--;
  if(v[i][j]==0)
   v[i][j]=x++;
 else x++;
     }
     v[i][j]=0;
     x--;

    }else if(v[i-1][j-1]==(x-1))
    {
        i--;
        j--;
     while(i<=m && j>=1)
  {
      i++;
      j--;
 if(v[i][j]==0)
   v[i][j]=x++;
 else x++;
  }
  v[i][j]=0;
  x--;
    }
  c=false;
  }
//loveste marginea din stanga
   if(j==0 && c)
   {
    if(v[i+1][j+1]==(x-1))
    {
     i++;
     j++;
     while(i>=1 && j<=n)
     {
         i--;
         j++;
        if(v[i][j]==0)
   v[i][j]=x++;
 else x++;
     }
     v[i][j]=0;
     x--;

   }else if(v[i-1][j+1]==(x-1))
   {
       i--;
       j++;
     while(i<=m && j<=n)
   {
    i++;
    j++;
    if(v[i][j]==0)
   v[i][j]=x++;
 else x++;
   }
   v[i][j]=0;
   x--;

   }
       c=false;
}
}

for(i=1;i<=m;i++)
{
    for(j=1;j<=n;j++)
        if(v[i][j]==0)
         g<<" . ";
    else
     g<<v[i][j]<<" ";
    g<<endl;

}

g.close();
}

