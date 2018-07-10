#include <bits/stdc++.h>
#define INF 1LL << 60

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll dist[101];
ll cost[101];
bool Gee[101];
vector<pii> adj[101];

bool visit[101];

int main()
{
    int V, E, st, ed;
    int cnt = 0;

    scanf("%d %d %d %d", &V, &st, &ed, &E);

    for (int i = 0; i < E; i++)
    {
        int from, to, val;
        scanf("%d %d %d", &from, &to, &val);

        adj[from].push_back({ to, val });
    }

    for (int i = 0; i < V; i++)
        scanf("%lld", &cost[i]);

    for (int i = 0; i < V; i++)
        dist[i] = -INF;

    dist[st] = cost[st];

    bool update = true;
    while (update && cnt != V)
    {
        update = false;

        for (int i = 0; i < V; i++)
            for(auto j : adj[i])
            {
                if (dist[i] != -INF  && dist[i] + cost[j.first] - j.second > dist[j.first])
                {
                    dist[j.first] = dist[i] + cost[j.first] - j.second;
                    update = true;

                    if (cnt == V - 1)
                        Gee[i] = true;
                }
            }
        cnt++;
    }

    // bfs
    bool getChk = false;
    queue <int> Q;

    for (int i = 0; i < V; i++)
        if (Gee[i])
            Q.push(i);

    while (!Q.empty())
    {
        int here = Q.front();
        Q.pop();

        if (visit[here])
            continue;

        visit[here] = true;

        for (int i = 0; i < adj[here].size(); i++)
        {
            if (adj[here][i].first == ed)
            {
                getChk = true;
                break;
            }
            if(!visit[adj[here][i].first])
                Q.push(adj[here][i].first);
        }

        if (getChk)
            break;
    }

    if (dist[ed] == -INF)
        cout << "gg";
    else if (getChk)
        cout << "Gee";
    else
       cout << dist[ed];


    return 0;
}
