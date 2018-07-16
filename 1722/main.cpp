#include <cstdio>
#include <vector>

using namespace std;

long long factorial(int N) {
    long long p=1;
    for(int i=2; i<=N; i++)
        p*=i;
    return p;
}

long long type_2(vector <int >& perm, int N){
    long long answer=0;
    vector <int > cnt;
    for(int i=1; i<=N; i++)
        cnt.push_back(i);
    for(int i=0; i<N; i++) {
        vector <int >::iterator p = lower_bound(cnt.begin(),cnt.end(),perm[i]);
        answer+=(p-cnt.begin()) * factorial(N-i-1);
        cnt.erase(p);
    }
    return answer;
}

void type_1(long long lar,int N) {
    long long tmp = lar;
    vector <int > cnt;
    for(int i=1; i<=N; i++)
        cnt.push_back(i);
    for(int i=N-1; i>=0; i--) {
        int j;
        long long tar = factorial(i);
        for(j=0; tmp > j * tar; j++);
        j--;
        tmp -= j * tar;
        printf("%d ",cnt[j]);
        cnt.erase(cnt.begin()+j);
    }
}

int main()
{
    int N;
    scanf("%d",&N);

    int type;
    scanf("%d",&type);

    if(type == 1) {
        long long input;
        scanf("%lld",&input);
        type_1(input, N);
    }
    else {
        int* temp = new int[N];
        for(int i=0; i<N; i++)
            scanf("%d",&temp[i]);
        vector <int > perm(temp,temp+N);
        printf("%lld",type_2(perm, N)+1);
    }

    return 0;
}
