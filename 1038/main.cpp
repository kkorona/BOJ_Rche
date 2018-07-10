#include <iostream>
#include <string>
#include <vector>
using namespace std;

int digit[100];
int _size = 1;
void gen() {
    int pointer = _size-1;
    digit[pointer]++;
    while(pointer > 0 && digit[pointer] == digit[pointer-1] ) {
        digit[pointer] = _size - pointer - 1;
        digit[pointer-1] ++;
        pointer --;
    }
    if(digit[0] == 10) {
        _size++;
        for(int i=0; i<_size; i++)
            digit[i] = _size - i - 1;
    }
}

int main() {

    int N;
    cin >> N;
    if(N >= 1023) {
        cout << -1;
        return 0;
    }
    while(N--) {
        gen();
    }
    for(int i=0; i<_size; i++)
        cout << digit[i];

    return 0;
}
