#include <cstdio>
#include <vector>

using namespace std;

vector <int > T;
int ok[1001];

void pick(vector <int >& picked, int index,int k) {
    if(k == 0) {
        int sum=0;
        for(int i=0; i<picked.size(); sum+=picked[i],i++) ;
        if(sum <= 1000) ok[sum]=1;
        return;
    }
    for(int i=index; i<T.size(); i++) {
        picked.push_back(T[i]);
        pick(picked,i,k-1);
        picked.pop_back();
    }
}

int main()
{
    for(int i=1; i*(i+1)/2<=1000; i++)
        T.push_back(i*(i+1)/2);

    vector <int > picked;
    pick(picked,0,3);

    int n;

    scanf("%d",&n);

    while(n--) {
        int K;
        scanf("%d",&K);
        if(ok[K]) printf("1\n");
        else printf("0\n");
    }

    return 0;
}
