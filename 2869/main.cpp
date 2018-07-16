#include <iostream>

using namespace std;

int main()
{
    long long B,A,V;
    cin >> A >> B >> V;
    int check = (V-A)%(A-B);
    if(check != 0) check = 1;
    cout << (V-A)/(A-B) + check + 1;
    return 0;
}
