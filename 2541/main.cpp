#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    pair <long long,long long > start;
    cin >> start.first >> start.second;

    long long g = abs(start.first - start.second);
    while(g && g%2 == 0) g /= 2;

    long long N = 5;
    while(N--) {
        static pair <long long,long long> target;
        static char ret;
        ret = 'N';
        cin >> target.first >> target.second;
        if(start.first == start.second) {
            if(target.first == target.second)
                ret = 'Y';
        }
        else {
            if(!((target.first == target.second) || (start.first - start.second) * (target.first - target.second) < 0))  {
                    if(abs(target.second - target.first) % g == 0)
                        ret = 'Y';
            }
        }
        cout << ret << "\n";
    }

    return 0;
}
