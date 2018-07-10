#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int MAXX = 200001;

int p[200001];
void init() {
    for(int i=1; i<MAXX; i++) p[i]=i;
}

int Find(int u) {
    return (p[u] == u) ? u:p[u]=Find(p[u]);
}

void Union(int u,int v) {
    int pu=Find(u);
    int pv=Find(v);
    p[pu]=pv;
}
map < string, int > List;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        int N;
        scanf("%d",&N);
        int cnt=1;

        vector < int > Count;
        Count.push_back(0);
        init();

        for(int i=0; i<N; i++) {
            char input[50];
            scanf("%s",input);
            string s1(input);
            scanf("%s",input);
            string s2(input);
            if(!List[s1]) {
                Count.push_back(1);
                List[s1]=cnt++;
            }
            if(!List[s2]) {
                Count.push_back(1);
                List[s2]=cnt++;
            }
            int q1=Find(List[s1]),q2=Find(List[s2]);
            if(q1 != q2) {
                Count[q2]+=Count[q1];
                Count[q1]=1;
                p[q1]=q2;
            }
            printf("%d\n",Count[q2]);
        }
        List.clear();
    }
    return 0;
}
