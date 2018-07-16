#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
    int N;
    locale loc;
    string input;
    cin >> N;
    while(N--) {
        cin >> input;
        for(char c : input)
            cout << tolower(c,loc);
        cout << "\n";
    }
    return 0;
}
