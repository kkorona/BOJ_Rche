#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


int main()
{

    int T;
    cin >> T;

    while(T--) {
        map <int,string> Data;
        int N;
        cin >> N;

        while(N--) {
            int price;
            string name;
            cin >> price >> name;
            Data[price]=name;
        }
        map <int,string>::reverse_iterator it = Data.rbegin();
        cout << (it->second) << endl;
    }

    return 0;
}
