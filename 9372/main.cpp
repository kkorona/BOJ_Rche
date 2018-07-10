#include <iostream>
#include <vector>
using namespace std;


const int LIMIT  = 1001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();


    int T,N,M;
    int u,v;
    cin >> T;

    while(T--) {
        cin >> N >> M;
        for(int i=0; i<M; i++) {
            cin >> u >> v;
        }
        cout << N-1 << "\n";
    }

    return 0;
}
