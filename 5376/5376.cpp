#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x,long long y) {
    long long a=x,b=y,c=x%y;
    while(c != 0) {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();


#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int T;
    cin >> T;
    while(T--) {
        string input;
        cin >> input;
        int _size = input.size();
        bool loopFlag = false;
        long long origin = 0, loop = 0;
        long long master = 1, slave = 1;
        for(int i=2; i<_size; i++) {
            if(input[i] == '(') {
                loopFlag = true;
            }
            else if('0' <= input[i] && input[i] <= '9') {
                if(!loopFlag) {
                    loop = loop*10;
                    loop += (input[i] - '0');
                    slave *= 10;
                }
                origin = origin*10;
                origin += (input[i] - '0');
                master *= 10;
            }
        }
        long long gcdd = 0;
        if(loopFlag && origin == loop) origin *= 11;
        if(loopFlag) {
            gcdd = gcd(origin - loop, master - slave);
            cout << (origin - loop)/gcdd << "/" << (master - slave)/gcdd << endl;
        }
        else {
            gcdd = gcd(origin, master);
            cout << (origin/gcdd) << "/" << (master/gcdd) << endl;
        }
    }

    return 0;
}