#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


vector < vector < int > > cell;
vector < vector < int > > grow;
int N,M;
vector < int > day;

int main()
{
    cin >> M >> N;
    cell.resize(M,vector<int>(M,1));
    grow.resize(M,vector<int>(M,0));
    day.resize(M*2, 0);

    for(int i=1; i<=N; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        day[a]++;
        day[a+b]++;
    }

    cell[M-1][0]+=day[0];
    int y=M-2,x=0;
    for(int i=1; i<2*M-1; i++) {
        day[i]+=day[i-1];
        cell[y][x]+=day[i];
        grow[y][x]=day[i];
        (y != 0) ? y--:x++;
    }

    for(int i=1; i<M; i++) {
        for(int j=1; j<M; j++) {
            int growth = max({grow[i-1][j-1],grow[i-1][j],grow[i][j-1]});
            cell[i][j] += growth;
            grow[i][j] = growth;
        }
    }

    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            cout << cell[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
