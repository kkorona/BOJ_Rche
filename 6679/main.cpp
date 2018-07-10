#include <cstdio>

using namespace std;

int getval(int k,int bi) {
    int x=k,y=bi,res=0;
    while(x>0) {
        res+=x%y;
        x/=y;
    }
    return res;
}

bool check(int k) {
    int val10=getval(k,10);
    int val12=getval(k,12);
    int val16=getval(k,16);
    if(val10 == val12 && val12 == val16) return true;
    return false;
}

int main()
{

    for(int i=1000; i<=9999; i++) {
        if(check(i)) printf("%d\n",i);
    }

    return 0;
}
