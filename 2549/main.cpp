#include <iostream>
#include <string>
using namespace std;

const int SIZE = 4;

int stateTable[33333334]; // 1��2��3��4�� 1��2��3��4��

bool check(const vector <int>& ans,const vector <int>& state) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j < SIZE; j++) {
            if(ans[i][j] != state[i][j]) return false;
        }
    }
    return true;
}

void backtrack(const int state) {
    int mask = 1;
    for(int i=0; i<8; i++) {

    }
}

int main()
{


    return 0;
}
