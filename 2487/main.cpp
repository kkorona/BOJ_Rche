#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector <long long > Cycles;

int N;
int Perm[20005],visit[20005];

int dfs(int node) {
    if(visit[Perm[node]] == 1) return 0;
    visit[Perm[node]]=1;
    return dfs(Perm[node])+1;
}

long long gcd(long long a,long long b) {
    long long x=a,y=b,z;
    while(y != 0) {
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}

int main()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        int x;
        scanf("%d",&x);
        Perm[x]=i;
    }

    for(int i=1; i<=N; i++) {
        if(visit[i] == 0) {
            visit[i]=1;
            Cycles.push_back(dfs(i)+1);
        }

    }
    long long lcm=Cycles[0];
    for(int i=1; i<Cycles.size(); i++) {
        int GCD_temp=gcd(lcm,Cycles[i]);
        lcm=lcm*Cycles[i]/(long long)GCD_temp;
    }

    printf("%lld",lcm);
    return 0;
}
