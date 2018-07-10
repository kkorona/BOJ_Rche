#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Point {
public :
    int x,y;

    Point(int py,int px) {
        y=py;
        x=px;
    }

    bool operator == (const Point& p) const {
        return (x == p.x) && (y == p.y);
    }
};

char image[64][64];
string answer;

string divide(const Point& st, const Point& ed) {
    if(st == ed)
        return string(1, image[st.y][st.x]);

    int ymid = (st.y + ed.y) /2;
    int xmid = (st.x + ed.x) /2;


    string p1 = divide(st,Point(ymid,xmid));
    string p2 = divide(Point(st.y, xmid+1), Point(ymid, ed.x));
    string p3 = divide(Point(ymid+1, st.x), Point(ed.y, xmid));
    string p4 = divide(Point(ymid+1,xmid+1),ed);
    if(p1 == p2 && p2 == p3 && p3 == p4 && p1.length() == 1) {
        return p1;
    }
    else {
        return string("(") + p1 + p2 + p3 + p4 + string(")");
    }

}

int main()
{
    int n;
    scanf("%d\n",&n);

    for(int i=0; i<n; i++)
        scanf("%s",image[i]);

    answer = divide(Point(0,0),Point(n-1,n-1));

    int ans_size=answer.length();
    for(int i=0;i < ans_size; i++)
        cout << answer[i];

    return 0;
}
