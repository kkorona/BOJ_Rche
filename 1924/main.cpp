#include <iostream>
#include <string>

using namespace std;

int main()
{
    int month,day;
    cin >> month >> day;
    string Day[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int Month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    int temp=day;
    for(int i=1; i<month; i++)
        temp+=Month[i];
    cout << Day[temp%7];
    return 0;
}
