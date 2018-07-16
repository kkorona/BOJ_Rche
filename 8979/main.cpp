#include <cstdio>

using namespace std;

struct Country {
    int Gold, Silver, Bronze, number;
} Data[1005];

bool cmp(const Country& A, const Country& B) {

    if(A.Gold != B.Gold) return A.Gold > B.Gold;
    if(A.Silver != B.Silver) return A.Silver > B.Silver;
    if(A.Bronze != B.Bronze) return A.Bronze > B.Bronze;
    return false;
}

int N,K,Find,Rank=1;

int main()
{

    scanf("%d %d",&N,&K);

    for(int i=0; i<N; i++) {
        scanf("%d %d %d %d",&Data[i].number,&Data[i].Gold,&Data[i].Silver,&Data[i].Bronze);
        if(Data[i].number == K) Find=i;
    }
    for(int i=0; i<N; i++)
        if(cmp(Data[i],Data[Find])) {
            Rank++;
        }

    printf("%d",Rank);

    return 0;
}
