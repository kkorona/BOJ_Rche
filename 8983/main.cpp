#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair <long long,long long > Point;
vector <long long > Shoot_point;

bool calc_range(Point anim,long long shoot, long long L) {
    return L>=(abs(anim.first-shoot)+anim.second);
}

int main()
{

    int M,N,ans=0;

    long long L,k;

    scanf("%d %d %lld",&M,&N,&L);

    for(int i=0; i<M; i++) {
        scanf("%lld",&k);
        Shoot_point.push_back(k);
    }

    sort(Shoot_point.begin(),Shoot_point.end());

    for(int i=0; i<N; i++) {
        long long y,x;
        scanf("%lld %lld",&x,&y);
        int stp_now_1=lower_bound(Shoot_point.begin(),Shoot_point.end(),x)-Shoot_point.begin();
        int stp_now_2=upper_bound(Shoot_point.begin(),Shoot_point.end(),x)-Shoot_point.begin();
        if(calc_range(make_pair(x,y),Shoot_point[stp_now_1],L)) ans++;
        else if(stp_now_2 > 0 && calc_range(make_pair(x,y),Shoot_point[stp_now_2-1],L)) ans++;
    }

    printf("%d",ans);

    return 0;
}
