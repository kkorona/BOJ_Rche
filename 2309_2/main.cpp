#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int data[9],pre_sum;

int main() {

    int a1,a2;

    for(int i=0; i<9; i++) {
        cin >> data[i];
        pre_sum += data[i];
    }

    for(int i=0; i<8; i++)
        for(int j=i+1; j<9; j++)
            if(pre_sum == data[i] + data[j] + 100) {
                a1=i; a2=j;
            }

    vector <int > answer;
    for(int i=0; i<9; i++)
        if(i != a1 && i != a2) answer.push_back(data[i]);

    sort(answer.begin(),answer.end());
    for(int i=0; i<answer.size(); i++)
        cout << answer[i] << endl;

    return 0;
}
