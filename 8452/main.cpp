#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;

const int INF = 1e9;
int V,E,QQ;
vector < pii > edge, query;
bool erased[100001] = {false,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();


	cin >> V >> E >> QQ;
	edge.resize(E+1);
	query.resize(QQ);
	for(int i=1; i<=E; i++){
		cin >> edge[i].first >> edge[i].second;
	}
	for(int i=0; i<QQ; i++){
		char o;
		cin >> o;
		cin >> query[i].second;
		query[i].first = (o == 'E');
		if(!query[i].first) erased[query[i].second] = true;
	}

	int dist[1001];
	fill(dist, dist+V+1, INF);
	dist[1] = 0;
	vector< vector <int> > adj(V+1);
	for(int i=1; i<=E; i++)
		if(!erased[i]) adj[edge[i].first].push_back(edge[i].second);
	queue<int> Q;
	Q.push(1);
	for(int i=1; !Q.empty(); i++){
		int qSize = Q.size();
		for(int j=0; j<qSize; j++){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(dist[next] == INF){
					dist[next] = i;
					Q.push(next);
				}
			}
		}
	}

	int result[200001], R = 0;
	while(--QQ >= 0){
		if(query[QQ].first) result[R++] = dist[query[QQ].second];
		else{
			int u = edge[query[QQ].second].first, v = edge[query[QQ].second].second;
			//cout << u << "-" << v << "\n";
			adj[u].push_back(v);
			if(dist[u]+1 < dist[v]){
				dist[v] = dist[u]+1;
				Q.push(v);
				for(int i=dist[v]+1; !Q.empty(); i++){
					int qSize = Q.size();
					for(int j=0; j<qSize; j++){
						int curr = Q.front(); Q.pop();
						for(int next: adj[curr]){
							if(dist[curr]+1 < dist[next]){
								dist[next] = i;
								Q.push(next);
							}
						}
					}
				}
			}
		}
	}
	while(--R >= 0) cout << (result[R] < INF ? result[R] : -1) << "\n";
}
