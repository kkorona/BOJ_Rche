#include <cstdio>

using namespace std;

int main()
{
    int year;
    char shipiji[13]="ABCDEFGHIJKL";
    scanf("%d",&year);
    int ji=8,gan=6;
    ji=(ji+year%12)%12;
    gan=(gan+year%10)%10;
    printf("%c%d",shipiji[ji],gan);
    return 0;
}
/*
0000 6 I
2013 9 F
2014 0 G
*/
