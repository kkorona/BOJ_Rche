#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int n,m;
const int MAXX = 2e7;
int p[MAXX];

int main()
{
    int Z;

    scanf("%d",&Z);

    while(Z--) {

        scanf("%d%d",&n,&m);

        queue <int> emptyCount;
        vector <int> Filled(n+1,1);
        vector <int> Drink;
        bool ans=true;

        for(int i=0; i<=n; i++)
            p[i]=i;
        for(int i=0; i<m; i++) {
            int target;
            scanf("%d",&target);
            //비가 안오는 날
            if(target == 0) {
                emptyCount.push(i);
            }
            else {
                if(emptyCount.empty())  {
                    ans=false;
                    break;
                }
                Drink.push_back(target);
                emptyCount.pop();
            }
        }
        if(!ans) printf("NO");
        else {
            printf("YES\n");
            int _size = Drink.size();
            for(int i=0; i<_size; i++) {
                printf("%d ",Drink[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
