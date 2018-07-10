#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a[5];
    int maxlen = 0;
    for(int i=0; i<5; i++) {
        cin >> a[i];
        maxlen = max((int)a[i].length(), maxlen);
    }
    for(int i=0; i<5; i++) {
        for(int j=maxlen - a[i].length(); j>0; j--)
            a[i].push_back(NULL);
    }
    for(int i=0; i<maxlen; i++) {
        for(int j=0; j<5; j++) {
            if(a[j][i] == NULL) continue;
            cout << a[j][i];
        }
    }
    return 0;
}
