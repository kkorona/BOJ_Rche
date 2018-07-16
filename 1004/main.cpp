#include <bits/stdc++.h>
using namespace std;

int isInCircle(int x,int y, int Cx, int Cy, int Cr){
    return (x-Cx)*(x-Cx) +(y-Cy)*(y-Cy)<Cr*Cr;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    int T;
    cin >> T;
    while(T--){
        int x1,y1,x2,y2,n,cx,cy,r,c=0;
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        for(int i=0;i<n;i++){
            cin >> cx >> cy >> r;
            c += isInCircle(x1,y1,cx,cy,r) ^ isInCircle(x2,y2,cx,cy,r);
        }
        cout << c << "\n";
    }
}
