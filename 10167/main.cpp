#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>
using namespace std;

class mine {
public:
    int y,x,v;
    mine(int y=0,int x=0,int v=0) : y(y), x(x), v(v) {}
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie();

    int N;
    cin >> N;
    vector < mine > mines(N);
    for(int i=0; i<N; i++){
        static int y,x,v;
        cin >> y >> x >> v;
        mines[i] = mine(y,x,v);
    }

    auto horizental = [&](const mine& A,const mine& B) {
        return A.y < B.y;
    };
    auto vertical = [&](const mine& A,const mine& B) {
        return A.x < B.x;
    };

    sort(mines.begin(),mines.end(),vertical);

    map < int,int > valuesOf;
    valuesOf[-1] = 0;
    long long int sum = 0;
    for(int i=0; i<N; i++) {
        sum += mines[i].v;
        valuesOf[mines[i].x] = sum;
    }
    int lx,mx;
    long long int minVal;
    minVal = numeric_limits<long long int>::max();
    for(auto startLine : valuesOf) {
        for(auto endLine :valuesOf) {
            if(startLine.first >= endLine.first) continue;
            if(minVal > startLine.second + sum - endLine.second) {
                minVal = startLine.second + sum - endLine.second;
                lx=startLine.first;
                mx=endLine.first;
            }
        }
    }

    sort(mines.begin(),mines.end(),horizental);
    valuesOf.clear();
    valuesOf[-1] = 0;
    sum = 0;
    for(int i=0; i<N; i++) {
        sum += mines[i].v;
        valuesOf[mines[i].y] = sum;
    }
    int ly,my;
    minVal = numeric_limits<long long int>::max();
    for(auto startLine : valuesOf) {
        for(auto endLine :valuesOf) {
            if(startLine.first >= endLine.first) continue;
            if(minVal > startLine.second + sum - endLine.second) {
                minVal = startLine.second + sum - endLine.second;
                ly=startLine.first;
                my=endLine.first;
            }
        }
    }

    cout << lx << " " << mx << " "<< ly << " "<< my << endl;

    long long int ans=0;
    for(mine m : mines) {
        if(lx < m.x && m.x <= mx && ly < m.y && m.y <= my) {
            ans += m.v;
        }
    }
    cout << ans;

    return 0;
}
