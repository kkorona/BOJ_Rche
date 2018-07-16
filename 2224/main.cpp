#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

vector < vector < int > > adjList;
map <char,int> encode;
map <int,char> decode;
vector < pair < char,char > > ans;
int N=1,M;

int main()
{
    cin >> M;
    char st,ed;
    string temp;

    adjList.resize(10001);

    while(M--) {
        cin >> st >> temp >> ed;
        if(!encode[st]) {
            encode[st] = N;
            decode[N] = st;
            N++;
        }
        if(!encode[ed]) {
            encode[ed] = N;
            decode[N] = ed;
            N++;
        }
        adjList[encode[st]].push_back(encode[ed]);
    }

    for(int i = 1; i<=N; i++) {
        sort(adjList[i].begin(),adjList[i].end());
        vector <int>::iterator it = unique(adjList[i].begin(),adjList[i].end());
        adjList[i].resize(distance(adjList[i].begin(),it));
    }
    vector <int> visit;
    for(int i = 1; i<=N; i++) {
        int start = i;
        queue <int> Q;
        visit.resize(N+1,0);
        Q.push(start);
        visit[start] = 1;
        while(!Q.empty()) {
            int index = Q.front();
            Q.pop();
            for(int v : adjList[index]) {
                if(visit[v] == 0) {
                    visit[v] = 1;
                    ans.push_back(make_pair(decode[start],decode[v]));
                    Q.push(v);
                }
            }
        }
        visit.clear();
    }

    sort(ans.begin(),ans.end());

    cout << ans.size() << endl;
    for(auto p : ans) {
        cout << p.first << " => " << p.second << endl;
    }

    return 0;
}
