#include <cstdio>
#include <algorithm>

using namespace std;

char Map[51][51];

class Square_4p {
    private : int sy,sx,fy,fx;
    public :
        Square_4p(int width, int ssy,int ssx) {
            sy=ssy;
            sx=ssx;
            fy=ssy+width-1;
            fx=ssx+width-1;
            //printf("%d %d %d %d\n",sy,sx,fy,fx);
        }
        bool isNumericSquare() {
            return (Map[sy][sx] == Map[sy][fx] && Map[sy][sx] == Map[fy][sx] && Map[sy][sx] == Map[fy][fx]) ;
        }
};

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int limit=min(N,M);

    for(int i=0; i<N; i++)
        scanf("%s",Map[i]);

    bool escape=false;
    for(int i=limit; i>=2 && !escape; i--) { // 3 2 1
        for(int j=0; j<N-i+1 && !escape; j++) { //
            for(int k=0; k<M-i+1 && !escape; k++) {
                Square_4p temp=Square_4p(i,j,k);
                if(temp.isNumericSquare()) {
                    printf("%d",i*i);
                    escape=true;
                }
            }
        }
    }
    if(!escape) printf("1");

    return 0;
}
