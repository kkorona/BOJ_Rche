#include <cstdio>
#include <queue>

using namespace std;

inline bool bchk(int lo,int tar,int hi) {
    return lo<= tar && tar < hi;
}

class triplet {
public:
    int x,y,z;
    triplet(int _x,int _y,int _z) : x(_x), y(_y), z(_z) {}
};

int dz[6]={-1,1,0,0,0,0}, dy[6]={0,0,-1,1,0,0},dx[6]={0,0,0,0,-1,1};
int nZ,nY,nX;
int main()
{

    scanf("%d%d%d",&nZ,&nY,&nX);

    //층별 정보 입력

    while(nZ!=0 && nY != 0 && nX != 0) {
        char floor[30][30][30];
        int visit[30][30][30]={0,};

        for(int i=0; i<nZ; i++) {
            for(int j=0; j<nY; j++) {
                scanf("%s",floor[i][j]);
            }
            char temp;
            scanf("%c",&temp);
        }

        //triplet : X,Y,Z 순으로 저장

        triplet st(0,0,0),ed(0,0,0);

        for(int i=0; i<nZ; i++) {
            for(int j=0; j<nY; j++) {
                for(int k=0; k<nX; k++) {
                    if(floor[i][j][k] == 'S')
                        st=triplet(k,j,i);
                    if(floor[i][j][k] == 'E')
                        ed=triplet(k,j,i);
                }
            }
        }

        //BFS

        queue < triplet > Q;
        Q.push(st);
        visit[st.z][st.y][st.x]=1;
        while(!Q.empty()) {
            triplet index = Q.front();
            Q.pop();
            int z=index.z,y=index.y,x=index.x;
            for(int i=0; i<6; i++) {
                int Z=z+dz[i],Y=y+dy[i],X=x+dx[i];
                if(bchk(0,Z,nZ) && bchk(0,Y,nY) && bchk(0,X,nX) && visit[Z][Y][X] == 0 && floor[Z][Y][X] != '#') {
                    Q.push(triplet(X,Y,Z));
                    visit[Z][Y][X]=visit[z][y][x]+1;
                }
            }
        }

        //printf("start : %d %d %d\n end : %d %d %d \n",st.z,st.y,st.x,ed.z,ed.y,ed.x);

        //탈출구를 방문했을 경우

        if(visit[ed.z][ed.y][ed.x] > 0) printf("Escaped in %d minute(s).\n",visit[ed.z][ed.y][ed.x]-1);
        else printf("Trapped!\n");

        /*
        for(int i=0; i<nZ; i++) {
            for(int j=0; j<nY; j++) {
                for(int k=0; k<nX; k++) {
                    printf("%d ",visit[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }
        */

        scanf("%d%d%d",&nZ,&nY,&nX);

    }

    return 0;
}
