#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N--) {
        int loop;
        string input;
        cin >> loop;
        cin >> input;
        for(char c : input) {
            for(int i=0; i<loop; i++)
                cout << c;
        }
        cout << "\n";
    }
    return 0;
}
