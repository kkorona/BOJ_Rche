#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> A(10);
    vector <int> B(10);

    int Awin = 0, Bwin = 0;
    const int N = 10;
    for(int i=0; i<N; i++)
        cin >> A[i];
    for(int i=0; i<N; i++) {
        cin >> B[i];
        if(A[i] > B[i]) Awin ++;
        if(A[i] < B[i]) Bwin ++;
    }

    if(Awin == Bwin) cout << "D";
    else if(Awin < Bwin) cout << "B";
    else cout << "A";

    return 0;
}
