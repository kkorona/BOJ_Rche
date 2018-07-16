#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(int n, vector <long long >& h,int left,int right) {
    if(left == right) return h[left];
    int mid=(left+right)/2;
    int l=mid, r=mid+1;
    long long ret=max(solve(n,h,left,l),solve(n,h,r,right));
    long long height=min(h[l],h[r]);
    ret=max(ret,height*2);

    while(left < l || r < right) {
        if(left < l) {
            if(r < right && h[l-1] < h[r+1]) {
                ++r;
                height = min(height,h[r]);
            }
            else {
                --l;
                height = min(height,h[l]);
            }
        }
        else {
            ++r;
            height=min(height,h[r]);
        }
        ret = max(ret,height*(r-l+1));
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d",&T);
    long long Data[100000];
    for(int i=0; i<T; i++)
    scanf("%lld",&Data[i]);

    vector <long long > h(Data,Data+T);

    printf("%lld\n",solve(T,h,0,T-1));
    return 0;
}
