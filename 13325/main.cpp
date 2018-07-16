#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 1024*2048+1;
int edges[MAX];
int DP[MAX];

int main()
{

    int k;

    cin >> k;

    int n=pow(2,k+1)-1;

    for(int i=2; i<=n; i++) {
        cin >> edges[i];
    }

    for(int i=(n+1)/2-1; i>=1; i--) {
        int temp=DP[i*2]+edges[i*2] - (DP[i*2+1]+edges[i*2+1]);
        if(temp > 0) {
            edges[i*2+1]+=temp;
        }
        else {
            edges[i*2]-=temp;
        }
        DP[i]=DP[i*2]+edges[i*2];

    }

    long long sum = 0;
    for(int i=2; i<=n; i++) {
        sum+=edges[i];
    }
    cout << sum;
    return 0;
}
