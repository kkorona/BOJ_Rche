#include <cstdio>
#include <vector>

using namespace std;

vector <int > Trans_Data;

int subPalinCheck(int k, int p) {
    int x=k,y=p;
    while(x>0) {
        Trans_Data.push_back(x%y);
        x/=y;
    }
    for(int i=0; i<=Trans_Data.size()/2; i++) {
        if(Trans_Data[i] != Trans_Data[Trans_Data.size()-i-1]) {
            return 0;
        }
    }
    return 1;
}

int PalinCheck(int k) {

    for(int i=2; i<=64; i++) {
        if(subPalinCheck(k,i)) {
            Trans_Data.erase(Trans_Data.begin(),Trans_Data.end());
            return 1;
        }
        Trans_Data.erase(Trans_Data.begin(),Trans_Data.end());
    }
    return 0;
}

int main()
{

    int t,k;

    scanf("%d",&t);
    for(int i=0; i<t; i++) {
        scanf("%d",&k);
        printf("%d\n",PalinCheck(k));
    }

    return 0;
}
