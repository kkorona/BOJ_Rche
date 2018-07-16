#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector < pair <int,int> > arr(N);
    vector < int > curs;
    vector < int > track(500001,0);
    vector < int > check(500001,0);
    for(int i=0; i<N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(),arr.end());
    int _size = 0;
    for(int i=0; i<N; i++) {
        int it = lower_bound(curs.begin(),curs.end(),arr[i].second) - curs.begin();
        if(it == _size) {
            curs.push_back(arr[i].second);
            _size++;
        }
        else
            curs[it] = arr[i].second;
        if(it != 0) track[curs[it]] = curs[it-1];
    }
    cout << N - _size << "\n";
    for(int i=curs[_size-1]; i > 0; i = track[i]) check[i] = 1;
    for(int i=0; i<N; i++) if(!check[arr[i].second]) cout << arr[i].first << "\n";
    return 0;
}
