#include <bits/stdc++.h>
using namespace std;
char label[11][30] = {"New Customer", "Promising", "About to Sleep", "Hibernating", "Lost", "Potential Loyalist", "Need Attention", "About to Leave", "Champion", "Loyal Customer", "Can't Lose Them"};
int table[5][5] = {0,1,2,4,4,5,5,2,3,4,5,5,6,7,7,9,9,9,7,7,8,9,9,7,10};

inline int Segmentate(int d1,int d2,int d3,int d4,int d) {
    if(d == 0) return -1;
    if(d <= d1) return 0;
    if(d <= d2) return 1;
    if(d <= d3) return 2;
    if(d <= d4) return 3;
    return 4;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    map < string, pair<int,int> > data;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif

    int f1,f2,f3,f4;
    int r1,r2,r3,r4;
    cin >> r1 >> r2 >> r3 >> r4;
    cin >> f1 >> f2 >> f3 >> f4;
    
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        int order;
        string info;
        cin >> order >> info;
        if(order == 1) {
            data[info].first++;
            data[info].second = i;
        }
        else {
            int row = Segmentate(f1,f2,f3,f4,data[info].first);
            int col = Segmentate(r1,r2,r3,r4,i-data[info].second);
            //cout << row << " " << col << endl;
            if(row == -1) cout << "None";
            else cout << label[table[row][col]];
            cout << "\n";
        }
    }
    return 0;
}