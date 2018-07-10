#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int > Data_Properties;

vector <Data_Properties > Data;

bool cmp(const Data_Properties& A, const Data_Properties& B) {
    if(A.second != B.second) return A.second > B.second;
    return false;
}

int main()
{

    int N,C,check,k;
    scanf("%d %d",&N,&C);
    for(int i=0; i<N; i++) {
        check=1;
        scanf("%d",&k);
        for(int j=0; j<Data.size(); j++) {
            if(Data[j].first == k) { Data[j].second++;  check=0; break;}
        }
        if(check)
            Data.push_back(make_pair(k,1));
    }

    stable_sort(Data.begin(),Data.end(),cmp);

    for(int i=0; i<Data.size(); i++) {
        for(int j=0; j<Data[i].second; j++) printf("%d ",Data[i].first);
    }

    return 0;
}
