#include <iostream>
#include <vector>
using namespace std;

inline void max_renew(int &Max, const int& renew) {
    if(Max < renew) Max=renew;
}

int main()
{
    int N,prev,inc_max,inc_now,dec_max,dec_now;

    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        if(i == 0) {
            dec_max=dec_now=inc_max=inc_now=1;
            prev=temp; continue;
        }
        if(prev == temp) {
           inc_now++; dec_now++;
        }
        else if(prev < temp) {
            inc_now++; dec_now=1;
        }
        else {
            inc_now=1; dec_now++;
        }
        //cout << temp << "  " << inc_now << "  " << dec_now << endl;
        max_renew(inc_max,inc_now);
        max_renew(dec_max,dec_now);
        prev=temp;
    }

    cout << (inc_max > dec_max ? inc_max : dec_max) << endl;
    return 0;
}
