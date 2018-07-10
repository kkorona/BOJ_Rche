#include <iostream>

using namespace std;

int main()
{
    int A,B,C,N;
    int ans = 0;
    cin >> A >> B >> C >> N;
    for(int i=0; N-A*i >= 0; i++) {
        int N1 = N-A*i;
        for(int j=0; N1 - B * j >= 0; j++) {
            int N2 = N1-B*j;
            for(int k=0; N2 - C*k >= 0; k++) {
                if(N2 - C*k == 0) {
                    ans = 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
