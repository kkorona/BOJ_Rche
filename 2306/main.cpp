#include <iostream>
#include <vector>
#include <string>
using namespace std;

string input;
vector < vector <int> > T;

int getMax(int st,int ed) {
    if(st >= ed) return 0;
    int& r = T[st][ed];
    if(r != -1) return r;
    r=0;
    if(input[st] == 'a' && input[ed] == 't') r = getMax(st+1,ed-1) + 2;
    else if(input[st] == 'g' && input[ed] == 'c') r = getMax(st+1,ed-1) + 2;
    for(int i=st; i<ed; i++)
        r = max(r, getMax(st,i) + getMax(i+1,ed));
    return r;
}

int main() {
    cin >> input;
    int N = input.length();

    T.resize(N,vector<int>(N,-1));

    cout << getMax(0,N-1);

    return 0;
}

