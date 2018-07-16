#include <stdio.h>
#include <string.h>

int main()
{
    char A[10005],B[10005];
    long long answer=0;
    scanf("%s %s",A,B);
    int n=strlen(A),m=strlen(B);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            answer+=(A[i]-'0')*(B[j]-'0');
        }
    }
    printf("%lld",answer);

    return 0;
}
