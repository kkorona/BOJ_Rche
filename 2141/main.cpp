#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    long long sum = 0;

    scanf("%d",&N);

    vector < pair < long long,long long > > V(N);

    for(auto& v : V) {
        scanf("%lld%lld",&v.first,&v.second);
        sum += v.second;
    }

    sort(V.begin(),V.end());

    sum /= 2;

    int index = 0;
    long long cur = 0;

    do {
        cur += V[index].second;
        index++;
    }while(cur < sum);

    printf("%lld",V[index-1].first);

    return 0;
}
