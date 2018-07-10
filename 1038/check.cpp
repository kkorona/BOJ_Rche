#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream i1;
    i1.open("output.txt");
    ifstream i2;
    i2.open("poutput.txt");
    cout << 1;
    for(int i=0; i<=2000; i++) {
        string s1,s2;
        i1 >> s1;
        i2 >> s2;
        if(s1.compare(s2) != 0) {
            cout << i << " / "<< s1 << " vs " << s2 << endl;
        }
    }
    return 0;
}
