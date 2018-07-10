#include <iostream>

using namespace std;

int main()
{
    int N,temp;
    cin >> N;
    temp=N;
    int cnt=0;
    do {
        int k=temp/10+temp%10;
        temp=(temp%10)*10+(k%10);
        cnt++;
    }while(temp != N);
    cout << cnt;
    return 0;
}
