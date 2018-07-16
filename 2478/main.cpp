#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> P;
int N;

void rotateRight() {
    int temp = P[N-1];
    for(int i=N-1; i>0; i--)
        P[i] = P[i-1];
    P[0] = temp;
    for(int v : P)
                cout << v << " ";
            cout << endl;
}

pair <int,int> findpq() {
    int startPoint = -1;
    int endPoint = -1;
    int flag = 0;
    for(int i=0; i<N-1; i++) {
        if(P[i] == P[i+1]%N +1) {
            int j=i+1,k=i;
            while(P[j] == P[j+1]%N + 1) {
                j = ;
            }
        }
    }
    if(startPoint == -1) return make_pair(-1,-1);
    else return make_pair(startPoint,endPoint);
}

int main() {

    cin >> N;
    int rot1=0, rot2=0;
    pair <int,int> pq;
    P.resize(N,0);
    for(int i=0; i<N; i++)
        cin >> P[i];
    do {
        rotateRight(); rot2++;
        pq = findpq();
        if(pq.first != -1) {
            cout << "reverse!!!!!" << endl;
            reverse(P.begin()+pq.first,P.begin()+pq.second);
            for(int v : P)
                cout << v << " ";
            cout << endl;
            break;
        }
    }while(rot2 <= N);
    while(P[0] != 1) {
        rotateRight();
        rot1++;
    }
    cout << rot1 << endl << pq.first << " " << pq.second << endl << rot2;


    return 0;
}
