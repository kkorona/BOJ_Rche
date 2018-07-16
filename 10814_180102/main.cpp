#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef pair < int, string > Info;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector < Info > Data;
    cin >> N;
    Data.resize(N,{0,string("")});
    for(int i=0; i<N; i++)
        cin >> Data[i].first >> Data[i].second;
    stable_sort(Data.begin(),Data.end(),[&](Info a,Info b){return a.first < b.first; });
    for(auto i : Data) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
