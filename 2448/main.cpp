#include <iostream>

using namespace std;

char out[3072][6144];

void fillin(int n,int x,int y) {
    if(n == 3){
        out[y][x]='*';
        out[y+1][x-1]='*';
        out[y+1][x+1]='*';
        out[y+2][x-2]='*';
        out[y+2][x-1]='*';
        out[y+2][x]='*';
        out[y+2][x+1]='*';
        out[y+2][x+2]='*';
        return;
    }
    fillin(n/2, x,y);
    fillin(n/2,x-(n/2),y+(n/2));
    fillin(n/2,x+(n/2),y+(n/2));
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<2*n; j++)
            out[i][j]=' ';
        out[i][2*n-1]='\0';
    }

    fillin(n,n-1,0);

    for(int i=0; i<n; i++) {
        for(int j=0; j<2*n-1; j++) {
            cout << out[i][j];
        }
        cout << "\n";
    }
    return 0;
}
