#include <cstdio>
#include <vector>
using namespace std;

bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

int N,M,T,D;

int abs(int p) {
    return (p>0) ? p : (-p);
}

pair < int,int > Trans_int2pair(int num) {
    int y=num/M, x=num%M;
    return make_pair(y,x);
}

int Trans_pair2int (const pair < int,int >& P) {
    return P.first*M + P.second;
}

const int INF = 1e9;

int dy[4]={-1,1,0,0},dx[4]={0,0,-1,1};

int main()
{

    scanf("%d%d%d%d",&N,&M,&T,&D);

    vector < vector < int > > Map(N);
    vector < vector < int > > Floyd(N*M);
    char temp;
    scanf("%c",&temp);

    for(int i=0; i<N*M; i++) {
        Floyd[i].resize(N*M,INF);
        Floyd[i][i]=0;
    }

    for(int i=0; i<N; i++) {

        Map[i].resize(M,0);
        for(int j=0; j<M; j++) {
            scanf("%c",&temp);
            if('A' <= temp && temp <= 'Z') Map[i][j] = temp-'A';
            else Map[i][j]=26+temp-'a';
        }
        scanf("%c",&temp);
    }

    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            for(int i=0; i<4; i++) {
                int Y=y+dy[i], X=x+dx[i];
                if(!bchk(0,Y,N) || !bchk(0,X,M)) continue;
                if(abs(Map[Y][X]-Map[y][x]) > T) continue;
                // p2.val > p1.val
                if(Map[Y][X] > Map[y][x]) {
                    int p1=Trans_pair2int(make_pair(Y,X));
                    int p2=Trans_pair2int(make_pair(y,x));
                    Floyd[p2][p1] = (Map[Y][X]-Map[y][x])*(Map[Y][X]-Map[y][x]);
                }
                // p2.val < p1.val
                if(Map[y][x] >= Map[Y][X]) {
                    int p1=Trans_pair2int(make_pair(Y,X));
                    int p2=Trans_pair2int(make_pair(y,x));
                    Floyd[p2][p1] = 1;
                }
            }
        }
    }

    for(int k=0; k<N*M; k++) {
        for(int i=0; i<N*M; i++) {
            for(int j=0; j<N*M; j++) {
                if(Floyd[i][j] > Floyd[i][k]+Floyd[k][j]) {
                    Floyd[i][j]=Floyd[i][k]+Floyd[k][j];
                }
            }
        }
    }
    int ans=0;
    for(int i=0; i<N*M; i++) {
        pair <int,int> P = Trans_int2pair(i);
        int y=P.first, x=P.second;
        //printf("%d %d : %d\n",y,x,Floyd[0][i] + Floyd[i][0]);
        if(Map[y][x] > ans && Floyd[0][i] + Floyd[i][0] <= D) {
            ans = Map[y][x];
        }
    }
    printf("%d",ans);

    return 0;
}
