#include <cstdio>
#include <algorithm>

using namespace std;

int countCountry[105],prized;
struct stud {
    int country, number, score;
} Data[105];

bool cmp(const stud& A, const stud& B) {
    if(A.score != B.score) return A.score > B.score;

}

int N;

int main()
{

    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d %d %d",&Data[i].country, &Data[i].number, &Data[i].score);
    sort(Data,Data+N,cmp);

    for(int i=0; i<N, prized < 3; i++) {
        if(countCountry[Data[i].country] < 2) {
            printf("%d %d\n",Data[i].country,Data[i].number);
            countCountry[Data[i].country]++;
            prized++;
        }
    }

    return 0;
}
