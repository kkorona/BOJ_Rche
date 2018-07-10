#include <cstdio>

using namespace std;

int getGCD(int x,int y) {
    int a=x,b=y,c;
    while(b != 0) {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int a,b,gcd,lcm;

    scanf("%d%d",&a,&b);
    gcd=getGCD(a,b);
    lcm=a*b/gcd;

    printf("%d\n%d",gcd,lcm);

    return 0;
}
