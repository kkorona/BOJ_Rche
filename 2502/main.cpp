#include <iostream>
#include <algorithm>

using namespace std;

pair <int,int > get_pair(int p1,int p2,int des) {
    bool escape=false;
    pair <int,int > res;
    for(int t1=1; t1 <= des/p1 && !escape; t1++) {
        int t2=(des-t1*p1)/p2, left=(des-t1*p1)%p2;
        if( left == 0)  {
            escape=true;
            res.first=t1;
            res.second=t2;
        }
    }
    return res;
}

int main()
{
    int D,cake;

    cin >> D >> cake;

    int T1,T2;
    D--;

    for(T1=1, T2=0; D--; T2+=T1, T1=T2-T1);

    cout << T1 << " "<< T2 << endl;


    pair <int,int > temp = get_pair(T1,T2,cake);

    cout << temp.first << endl << temp.second << endl;

    return 0;
}
