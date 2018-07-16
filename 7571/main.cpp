#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int N,M;
    cin >> N >> M;
    vector <int> xCount(N+1,0);
    vector <int> yCount(N+1,0);
    vector < pair < int,int > > Point(M);

    for(int i=0; i<M; i++) {
        cin >> Point[i].first >> Point[i].second;
        yCount[Point[i].first] ++;
        xCount[Point[i].second] ++;
    }

    int yAns, xAns;
    yAns = xAns = numeric_limits<int>::max();
    for(int i=1; i<=N; i++) {
        static int yCost;
        yCost = 0;
        for(int j=1; j<=N; j++) {
            yCost += (int)abs(j-i) * yCount[j];
        }
        yAns = min(yAns,yCost);
    }

    for(int i=1; i<=N; i++) {
        static int xCost;
        xCost = 0;
        for(int j=1; j<=N; j++) {
            xCost += (int)abs(j-i) * xCount[j];
        }
        xAns = min(xAns,xCost);
    }

    cout << yAns + xAns;

    return 0;
}
