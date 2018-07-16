#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int start = 1,i=1;
    for(i=1; start<N;start+=6*i, i++);
    cout << i;
    return 0;
}
