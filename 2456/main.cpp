#include <iostream>
#include <algorithm>
using namespace std;

class voteInfo {
public:
    int amount[4],score,index;
    voteInfo() {
        for(int& v:amount) {
            v = 0;
        }
        score = 0;
    }
    bool operator < (const voteInfo& rhs) const {
        if(score != rhs.score) return score < rhs.score;
        for(int i=3; i>=1; i--) {
            if(amount[i] != rhs.amount[i]) return amount[i] < rhs.amount[i];
        }
    }
    bool operator == (const voteInfo& rhs) const {
        if(score != rhs.score) return false;
        for(int i=3; i>=1; i--) {
            if(amount[i] != rhs.amount[i]) return false;
        }
        return true;
    }
};

voteInfo score[3];

int main()
{
    int N;
    cin >> N;
    for(int i=0; i<3; i++) score[i].index = i+1;
    while(N--) {
        static int input[3];
        for(int i=0; i<3; i++) {
            cin >> input[i];
            score[i].score += input[i];
            score[i].amount[input[i]] ++;
        }
    }
    sort(score,score+3);
    if(score[2] == score[1]) cout << 0 << " " << score[2].score;
    else cout << score[2].index << " " << score[2].score;
    return 0;
}
