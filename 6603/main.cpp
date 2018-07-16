#include <cstdio>
#include <vector>
using namespace std;

int k;

void pick(vector <int >& picked, int k, int index, vector <int >& S) {
    if(k == 0) {
        for(int i=0; i<picked.size(); i++)
            printf("%d ",picked[i]);
        printf("\n");
        return;
    }
    for(int i=index+1; i<S.size(); i++) {
        picked.push_back(S[i]);
        pick(picked,k-1,i,S);
        picked.pop_back();
    }
}

int main()
{
    while(1) {
        scanf("%d",&k);
        if(k == 0) break;

        vector <int > S;
        int x;
        for(int i=0; i<k; i++) {
            scanf("%d",&x);
            S.push_back(x);
        }
        vector <int > picked;
        pick(picked,6,-1,S);

        printf("\n");
    }
    return 0;
}
