#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const char line_w[9]="WBWBWBWB", line_b[9]="BWBWBWBW";
char Chess_W[8][9],Chess_B[8][9];
char Board[51][51];

int compare(int sy,int sx) {
    int c_black=0,c_white=0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(Chess_W[i][j] != Board[sy+i][sx+j]) c_white++;
            if(Chess_B[i][j] != Board[sy+i][sx+j]) c_black++;
        }
    }
    return min(c_black,c_white);
}

int main()
{

    for(int i=0; i<8; i++) {
        if(i%2 == 0) {
            strcpy(Chess_W[i],line_w);
            strcpy(Chess_B[i],line_b);
        }
        else {
            strcpy(Chess_W[i],line_b);
            strcpy(Chess_B[i],line_w);
        }
    }
    int N, M, ans=999;
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++)
        scanf("%s",Board[i]);

    for(int i=0; i<=N-8; i++)
        for(int j=0; j<=M-8; j++)
            ans=min(ans,compare(i,j));

    printf("%d",ans);

    return 0;
}
