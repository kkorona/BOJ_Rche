#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <string > Memo(100,string(""));

string Multiply(const string& a,const string& b) {
    string::iterator point_a=a.find(string(".")),point_b=b.find(string("."));

    string fa=a; fa.erase(point_a);
    string fb=b; fb.erase(point_b);

    string ans(fa.size()+fb.size()-1, 0);

    reverse(fa.begin(),fa.end());
    reverse(fb.begin(),fb.end());
    int la=fa.size(),lb=fb.size();
    for(int i=0; i<la; i++) {
        for(int j=0; j<lb; j++) {
            ans[i+j]=fa[i]-'0'+fb[j]-'0';
            ans[i+j+1]+=(ans[i+j])/10;
            ans[i+j]%=10;
        }
    }

    int lc=ans.size();
    for(int i=0; i<lc; i++) ans[i]+='0';

    reverse(ans.begin(),ans.end());

    ans.insert(point_a+point_b,'.');

    return ans;

}

string Adv_multi(const string& p, int x) {
    if(Memo[x].size() != 0) return Memo[x];

    if(x%2 == 1)
        Memo[x]=Multiply(Adv_multi(p,x-1),p);
    else
        Memo[x]=Multiply(Adv_multi(p,x/2),Adv_multi(p,x/2));

    return Memo[x];
}

int main()
{
    string input;
    int n;
    Memo.push_back(string(""));
    cin >> input >> n;
    Memo.push_back(input);

    cout << Adv_multi(input,n);


    return 0;
}
