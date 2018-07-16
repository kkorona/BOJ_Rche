#include <cstdio>
#include <vector>
using namespace std;

vector < pair <int,int> > School;
int main()
{
    int N;
    int left = 0;
    scanf("%d",&N);
    School.resize(N+1, make_pair(0,0));
    for(int i=0; i<N; i++) {
        scanf("%d %d",&School[i].first,&School[i].second);
        left += School[i].second % School[i].first;
    }
    printf("%d",left);
    return 0;
}
