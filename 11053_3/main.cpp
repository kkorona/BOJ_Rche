/*
 * Date :2017/08/02
 * O(N log N) solution
 */

#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

set <int > S;

int main()
{
    int N;
    int Data[1000];

    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d",&Data[i]);

    for(int i=0; i<N; i++) {
        set <int >::iterator pit = S.lower_bound(Data[i]);
        if(pit != S.end()) {
            S.erase(pit);
        }
        S.insert(Data[i]);

    }

    printf("%d",S.size());

    return 0;
}
