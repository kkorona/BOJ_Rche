#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector <char > Q;

int main()
{

    for(int i=0; i<=9; i++)
        Q.push_back('0'+i);

    int target,cur=100;
    char target_s[10];
    scanf("%d",&target);
    sprintf(target_s,"%d",target);

    int n=strlen(target_s);

    int p;
    scanf("%d",&p);

    for(int i=0; i<p; i++) {
        int x;
        scanf("%d",&x);
        Q.erase(Q.begin()+x);
    }

    int gap_LM,gap_GM;
    vector <char > LM,GM;

    bool check1, check2;

    for(int i=0; i<n; i++) {
        for(int j=Q.size()-1; j>=0 && !check1 && !check2; j--) {
            if(Q[j] <= target_s[0]) {
                LM.push_back(Q[j]); check1=true;
                if(Q[j] < target_s[0]) check2=true;
            }
        }
        if(!check1) LM.push_back('0');
        if(check2) LM.push_back(Q.back());
    }

    for(int i=0; i<n; i++) {
        printf("%c",LM[i]);
    }

    return 0;
}
