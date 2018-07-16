#include <iostream>

using namespace std;

typedef pair < int,int > Pair;
Pair memo[41];

// memo[i].first : fibonacci(0)이 실행된 횟수
// memo[i].second : fibonacci(1)이 실행된 횟수

Pair Fibo(int n) {
    if(memo[n].first != -1) return memo[n];
    Pair& ret = memo[n];
    if(n == 0) return ret = make_pair(1,0);
    else if (n == 1) return ret = make_pair(0,1);
    else return ret = make_pair(Fibo(n-1).first + Fibo(n-2).first, Fibo(n-1).second+Fibo(n-2).second);
}

int main()
{
    for(int i=0; i<41; i++)
        memo[i]=make_pair(-1,-1);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        Pair ans = Fibo(N);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}
