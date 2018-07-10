#include <cstdio>

using namespace std;

int ans[3],Paper[3000][3000];

void add(int type) {
    if(type == -1) ans[0]++;
    else if(type == 0) ans[1]++;
    else if(type == 1) ans[2]++;
}

class Point {
public:
    int x,y;

    Point(int py=0, int px=0) {
        y=py; x=px;
    }

    bool operator == (const Point& p) const {
        return (x == p.x) && (y == p.y);
    }
};

int div(const Point& st,const Point& ed) {
    if(st == ed) return Paper[st.y][st.x];

    int ydiv1 = st.y + (ed.y - st.y)/3;
    int ydiv2 = st.y + (ed.y - st.y)*2/3;
    int xdiv1 = st.x + (ed.x - st.x)/3;
    int xdiv2 = st.x + (ed.x - st.x)*2/3;

    int divs[9], cntdiv[3]={0,};
    divs[0] = div(st,Point(ydiv1,xdiv1));
    divs[1] = div(Point(st.y,xdiv1+1),Point(ydiv1,xdiv2));
    divs[2] = div(Point(st.y,xdiv2+1),Point(ydiv1,ed.x));
    divs[3] = div(Point(ydiv1+1,st.x),Point(ydiv2,xdiv1));
    divs[4] = div(Point(ydiv1+1,xdiv1+1),Point(ydiv2,xdiv2));
    divs[5] = div(Point(ydiv1+1,xdiv2+1),Point(ydiv2,ed.x));
    divs[6] = div(Point(ydiv2+1,st.x),Point(ed.y,xdiv1));
    divs[7] = div(Point(ydiv2+1,xdiv1+1),Point(ed.y,xdiv2));
    divs[8] = div(Point(ydiv2+1,xdiv2+1),ed);

    for(int i=0; i<9; i++) {
        if(divs[i] == -1) cntdiv[0]++;
        else if(divs[i] == 0) cntdiv[1]++;
        else if(divs[i] == 1) cntdiv[2]++;
    }

    if(cntdiv[0] == 9) return -1;
    else if(cntdiv[1] == 9) return 0;
    else if(cntdiv[2] == 9) return 1;

    for(int i=0; i<9; i++) {
        add(divs[i]);
    }
    return 2;

}

int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++)
            scanf("%d",&Paper[i][j]);
    }
    add(div(Point(0,0),Point(k-1,k-1)));

    for(int i=0; i<3; i++) printf("%d\n",ans[i]);

    return 0;
}
