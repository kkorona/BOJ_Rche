#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  int n;
  ofstream out;
  out.open("poutput.txt");
  for(int pN=0; pN<=2000; pN++) {
    n=pN;
  int s=0;
  char a[102]={0};
  int i,j,k=100,len=1,bol,t;
  a[k]='0';
  for(s=0;s<n;s++)
  {
    bol=0;
    for(i=k;i>k-len;i--)
    {
      if(a[i-1]==0||a[i-1]>a[i]+1)
      {
        if(a[i]+1>'9')
        {
          bol=1;
          break;
        }
        else
        {
          j='0';
          for(t=k;t>i;t--)a[t]=j++;
          a[i]+=1;
          break;
        }
      }
    }
    if(bol)
    {
      len++;
      j='0';
      for(i=k;i>k-len;i--)a[i]=j++;
      if(j>'9'+1){out<<-1<<endl; break;}
    }
  }
  out << a+k-len+1 << endl;
  }
  return 0;
}
