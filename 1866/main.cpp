#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector <int> dist(N+1,0);
    vector <int> T(N+1,0);
    int c1,c2;
    for(int i=1; i<=N; i++)
        cin >> dist[i];
    sort(dist.begin()+1,dist.end());
    cin >> c1 >> c2;

    for(int i=1; i<=N; i++) {
        T[i] = dist[i] * c1 + T[i-1];
        for(int j=i, cost = c2; j > 0; j--) {
            cost += (dist[(i+j+1)/2] - dist[j]) * c1;
            T[i] = min(T[i],T[j-1] + cost);
        }
    }
    cout << T[N];
    return 0;
}
