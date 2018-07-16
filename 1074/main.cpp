#include <cstdio>

using namespace std;

int N;

class Point {
public :
    int y,x;

    Point(int py=0,int px=0) {
        y=py; x=px;
    }
    Point(const Point& p) {
        y=p.y;
        x=p.x;
    }

    bool operator == (const Point& p) const {
        return (p.y == y) && (p.x == x);
    }
    bool operator <= (const Point& p) const {
        return (y <= p.y && x <= p.x);
    }
};

class Flat {
public :
    Point st,ed;

    Flat(const Point& pst=Point(0,0),const Point& ped=Point(0,0)) {
        st=pst; ed=ped;
    }

    bool isInRange(const Point& p) {
        return (st <= p) && (p <= ed);
    }
};

inline int pow(int x,int p) {
    int ret=1, t=p;
    while(t--) ret*=x;
    return ret;
}

int Z(const Flat& F,const Point& tar) {
    Point st=F.st, ed=F.ed;
    if(st == ed) return 1;

    int ymid = (st.y + ed.y) /2;
    int xmid = (st.x + ed.x) /2;

    bool check[4];

    Flat* f= new Flat[4];
    f[0] = Flat(st,Point(ymid,xmid));
    f[1] = Flat(Point(st.y, xmid+1), Point(ymid, ed.x));
    f[2] = Flat(Point(ymid+1, st.x), Point(ed.y, xmid));
    f[3] = Flat(Point(ymid+1,xmid+1),ed);

    check[0]=f[0].isInRange(tar);
    check[1]=f[1].isInRange(tar);
    check[2]=f[2].isInRange(tar);
    check[3]=f[3].isInRange(tar);

    int div=0;
    while(!check[div]) div++;

    int ans=((xmid-st.x)+1)*((xmid-st.x)+1)*div;

    //printf("%d\n",ans);

    return ans + Z(f[div],tar);


}

int main()
{
    int fy,fx;
    scanf("%d %d %d",&N,&fy,&fx);
    Point target(fy,fx);
    int answer = Z(Flat(Point(0,0),Point(pow(2,N)-1,pow(2,N)-1)),target);

    printf("%d",answer-1);

    return 0;
}
