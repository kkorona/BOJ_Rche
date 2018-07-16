#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Book {
    char name[52];
    int freq;
};

vector <Book > Data;

bool cmp(const Book& A, const Book& B) {
    if(A.freq != B.freq) return A.freq > B.freq;
    return (strcmp(A.name,B.name) < 0);
}

int main() {

    int N;
    char input[52];

    scanf("%d",&N);

    for(int i=0; i<N; i++) {
        int chk=1;
        scanf("%s",input);
        for(int j=0; j<Data.size(); j++) {
            if(strcmp(Data[j].name,input) == 0) {
                Data[j].freq++; chk=0; break;
            }
        }
        if(chk) {
            Book temp;
            strcpy(temp.name,input);
            temp.freq=1;
            Data.push_back(temp);
        }
    }

    sort(Data.begin(),Data.end(),cmp);
    printf("%s",Data[0].name);

    return 0;
}
