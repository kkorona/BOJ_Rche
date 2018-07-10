#include <cstdio>

using namespace std;

int main()
{
    char c;
    int ans=0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            scanf("%c",&c);
            if(c == 'F' && (i+j)%2 == 0)
                ans++;
        }
        scanf("%c",&c);
    }
    printf("%d",ans);
    return 0;
}
