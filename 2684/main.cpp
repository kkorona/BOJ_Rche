#include <stdio.h>
#include <string.h>
#include <memory.h>

#define N 40

int main()
{
    char Data[45];
    int PAT_T[8]={0,2,4,6,0,2,4,6},PAT_H[8]={1,3,5,7,1,3,5,7},Check[8]={0,};
    char PATTERN_FR[8][4]={"TTT","TTH","THT","THH","HTT","HTH","HHT","HHH"};

    int n,pat_now;

    scanf("%d",&n);
    for(; 0<n; n--) {
        scanf("%s",Data);
        for(int i=0; i<8; i++) {
            if(strncmp(PATTERN_FR[i],Data,3) == 0) pat_now=i;
        }
        Check[pat_now]++;
        for(int i=3; i<N; i++) {
            if(Data[i] == 'T') {
                pat_now=PAT_T[pat_now];
                Check[pat_now]++;
            }
            else {
                pat_now=PAT_H[pat_now];
                Check[pat_now]++;
            }
        }
        for(int i=0; i<8; i++) {
            printf("%d ",Check[i]);
        }
        memset(Check,0,sizeof(Check));
        printf("\n");
    }

    return 0;
}
