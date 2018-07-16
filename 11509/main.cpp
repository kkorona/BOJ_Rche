#include <cstdio>

using namespace std;

int dart[1000001],Data[1000001];

int main()
{

    int ans=0,n;

    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&Data[i]);

    for(int i=0; i<n; i++) {
        int k=Data[i];
        if(dart[k] == 0) {
            ans++;
            dart[k-1]++;
        }
        else {
            dart[k]--;
            if(k-1 >= 0)
                dart[k-1]++;
        }
    }

    printf("%d",ans);

    return 0;
}
