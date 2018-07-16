#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map <string,int> isPrime;
map <string,int> visit;

bool getPrime(int x) {
    for(int i=2; i*i <= x; i++) {
        if(!(x%i)) return false;
    }
    return true;
}
string toString(int x) {
    string temp;
    int p = x;
    while(p > 0)
    {
        temp.push_back('0' + p%10);
        p/=10;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}

int main()
{
    for(int i=1000; i<=9999; i++) {
        if(getPrime(i)) {
            isPrime[toString(i)] = 1;
        }
    }

    int T;
    cin >> T;
    while(T--) {
        string input,target;
        cin >> input >> target;
        visit[input]=1;
        queue < string > Q;
        Q.push(input);
        while(!Q.empty()) {
            string index = Q.front();
            if(index.compare(target) == 0) break;
            Q.pop();
            for(int i=0; i<4; i++) {
                for(int j= (i == 0 ? 1 : 0); j<10; j++) {
                    char temp = j+'0';
                    string next = index;
                    next[i]=temp;
                    if(isPrime[next] && visit[next] == 0) {
                        visit[next]=visit[index]+1;
                        Q.push(next);
                    }
                }
            }
        }
        while(!Q.empty()) Q.pop();
        if(visit[target]) cout << visit[target]-1;
        else cout << "Impossible";
        cout << endl;
        visit.clear();
    }

    return 0;
}
