#include <iostream>
#include <vector>

using namespace std;

int N;
int used[8];

void pick(vector <int>& picked,int k) {
    if(k == 0) {
        for(int i=0; i<N; i++)
            cout << picked[i] << ' ';
        cout << endl;
        return;
    }
    for(int i=0; i<N; i++) {
        if(used[i] == 0) {
            used[i] = 1; picked.push_back(i+1);
            pick(picked,k-1);
            used[i] = 0; picked.pop_back();
        }
    }
}

int main()
{

    cin >> N;

    vector <int > picked;
    pick(picked,N);

    return 0;
}
