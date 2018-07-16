#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L,C;
char data[15];

vector < vector <char > > answer;

bool check(vector <char>& picked) {
    int count_aeiou = 0, count_else = 0;
    for(int i=0; i<picked.size(); i++) {
        if(picked[i] == 'a' || picked[i] == 'e' || picked[i] == 'i' || picked[i] == 'o' || picked[i] == 'u') count_aeiou++;
        else count_else++;
    }
    if(count_aeiou >= 1 && count_else >= 2)
        return true;
    return false;
}

void pick(vector <char >& picked, int index, int k) {
    if(k == 0) {
        if(check(picked)) answer.push_back(picked);
        return;
    }
    for(int i=index+1; i<C; i++) {
        picked.push_back(data[i]);
        pick(picked,i,k-1);
        picked.pop_back();
    }
}

int main()
{

    cin >> L >> C;
    for(int i=0; i<C; i++)
        cin >> data[i];

    sort(data,data+C);

    vector <char > picked;

    pick(picked,-1,L);

    for(int i=0; i<answer.size(); i++) {
        for(int j=0; j<answer[i].size(); j++)
            cout << answer[i][j];
        cout << endl;
    }

    return 0;
}
