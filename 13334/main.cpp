#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Events {
public:
    int location,type; //type -1 : home, 1: office
    Events(const int _loc=0,const int _type=0) : location(_loc), type(_type) {}
    bool operator < (const Events& rhs) const {
        if(location != rhs.location) return location < rhs.location;
        return type < rhs.type;
    }
};


int N,d;

int main()
{

    cin >> N;
    vector <int> Home(N);
    vector <int> Office(N);
    vector <Events> Data(2*N);
    for(int i=0; i<N; i++)
        cin >> Home[i] >> Office[i];
    for(int i=0; i<N; i++) {
        int& home = Home[i],office = Office[i];
        if(home > office) {
            int temp=home;
            home = office;
            office = temp;
        }
        if(office - home > d) continue;
        Data[i*2] = Events(home,1);
        Data[i*2+1] = Events(office-d,-1);
    }
    cin >> d;
    N = Data.size();
    sort(Data.begin(),Data.end());

    int cur = 0, Max = 0;
    for(int i=0; i<N; i++) {
        Events& index = Data[i];
        cur -= index.type;
        Max = max(Max,cur);
    }

    cout << Max;
    return 0;
}
