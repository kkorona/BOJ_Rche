#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int N=20, K=10;
    vector <int> data(N,0);
    for(int i=1; i<=N; i++) data[i-1]=i;
    for(int i=0; i<K; i++) {
        int st,ed;
        cin >> st >> ed;
        for(int j=st-1, k=ed-1; j<k; j++, k--) {
            int temp = data[j];
            data[j]=data[k];
            data[k]=temp;
        }
    }

    for(int v : data) cout << v << " ";

    return 0;
}
