#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N=3;
    for(int i=0; i<N; i++) {
        static string input;
        cin >> input;
        int ans=1,cnt=1;
        for(int i=1, _size = input.length(); i<_size; i++) {
            if(input[i] == input[i-1]) cnt++;
            else cnt=1;
            ans = max(ans,cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}
