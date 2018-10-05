#include <bits/stdc++.h>

using namespace std;

const int adjMatrix[10][10] = {
    {0,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,1,0,1},
    {0,0,0,0,0,1,0,1,0,0},
    {0,0,0,0,0,1,0,1,0,0},
    {0,1,1,1,0,0,0,0,0,0},
    {0,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0} };

int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map <char,int> state;
    stack <char> paren;
    state['S']=1;
    state['B']=2;
    state['L']=3;
    state[',']=4;
    state['(']=5;
    state[')']=6;
    state['[']=7;
    state[']']=8;

    int W;
    int Ef=0,Eb=0,V=0;
    int flag = 1;
    string input;
    cin >> W;
    cin >> input;

    int curState = 0;
    for(char c : input) {
        if(flag == 0) break;
        int dest = state[c];
        if(dest == 0) {
            flag = 1;
            break;
        }
        if(adjMatrix[curState][dest]) {
            switch(dest) {
            case 1:
                V++;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                Ef++;
                paren.push('(');
                break;
            case 5:
                if(paren.empty() || paren.top() != '(') {
                    flag = 0;
                }
                else {

                }
                break;
            case 6:
                break;
            case 7:
                Ef++;
                break;
            case 8:
                if(paren.empty() || paren.top() != '[') {
                    flag = 0;
                }
                else {

                }
                break;
            }
        }
    }

    flag = !paren.empty();

    if(flag) {

    }
    else {
        cout << -1;
    }

    return 0;
}



/*

(0)start : S,B,L;
(1)S : ,, ]
(2)B : (, [
(3)L : (, [
(4), : S,B,L
(5)( : S,B,L
(6)) : ,
(7)[ : S,B,L
(8)] : ,
(9)dead

*/
