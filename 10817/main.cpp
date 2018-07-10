#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int data[3];
    for(int i=0; i<3; i++)
        cin >> data[i];
    sort(data,data+3);
    cout << data[1];
    return 0;
}
