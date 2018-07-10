#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int abs(int p) {
    if(p>0) return p;
    return -p;
}

class Point {
public:
    int x,y;
    Point(int _y,int _x) : y(_y), x(_x) {}
};
bool isConnected(const Point& A,const Point& B) {
    return (abs(A.y-B.y)+abs(A.x-B.x)) <= 1000;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {

        int N;
        scanf("%d",&N);

        int y,x;

        vector < Point > Conv;

        scanf("%d%d",&y,&x);
        Point st(y,x);

        Conv.push_back(st);

        for(int i=0; i<N; i++) {
            scanf("%d%d",&y,&x);
            Conv.push_back(Point(y,x));
        }

        scanf("%d%d",&y,&x);
        Point ed(y,x);

        Conv.push_back(ed);

        int p=Conv.size();

        vector < vector < int > > Graph(p);
        vector < int > visit(p,0);

        for(int i=0; i<p; i++) {
            Graph[i].resize(p,0);
            for(int j=0; j<p; j++) {
                if(isConnected(Conv[i],Conv[j])) {
                    Graph[i][j]=1;
                }
            }
        }

        queue < int > Q;

        Q.push(0);
        visit[0]=1;

        while(!Q.empty()) {
           int index=Q.front();
            Q.pop();
            for(int i=0; i<p; i++) {
                if(!visit[i] && Graph[index][i]) {
                    visit[i]=1;
                    Q.push(i);
                }
            }
        }

        if(visit[p-1]) printf("happy\n");
        else printf("sad\n");

    }
    return 0;
}
