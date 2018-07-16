#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int input[3],N,ret = 0;
    cin >> N;
    while(N--) {
        for(int i=0; i<3; i++)
            cin >> input[i];
        sort(input,input+3);
        static int ans;
        if(input[0] == input[1] && input[1] == input[2]) {
            ans = 10000 + 1000 * input[0];
        }
        else if(input[0] == input[1] || input[1] == input[2]) {
            ans = 1000 + 100 * input[1];
        }
        else {
            ans = 100 * input[2];
        }
        ret=max(ret,ans);
    }
    cout << ret;
    return 0;
}
