#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int X,ans;

int chvec_to_int(vector <char >& temp) {
    int n=0,tp=1;
    for(int i=temp.size()-1; i>=0; i--) {
        n+=(temp[i]-'0')*tp;
        tp*=10;
    }
    return n;
}

bool ishansu(vector <char>& temp) {
    char task[4];
    sprintf(task,"%d",chvec_to_int(temp));
    int n=strlen(task);
    if(n <= 2) return true;
    if(task[0]-task[1] == task[1]-task[2]) return true;
    return false;
}

void pick(vector <char>& picked,int k) {
    if(k == 0) {
        if(chvec_to_int(picked) <= X && ishansu(picked)) {
            ans++;
        }
        return;
    }
    for(char i='0'; i<='9'; i++) {
        picked.push_back(i);
        pick(picked,k-1);
        picked.pop_back();
    }
}

int main()
{
    cin >> X;

    vector <char > picked;

    pick(picked,3);

    cout << ans-1;
    return 0;
}
