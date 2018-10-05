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
    state[' ']=-1;

    int W;
    int Ef=0,Eb=0,V=0;
    int flag = 1;
    string input;
    cin >> W;
    char c;
    cin >> c;
    getline(cin,input);

    int curState = 0;
    for(char c : input) {
        if(flag == 0) break;
        int dest = state[c];
        if(dest == 0) {
            flag = 1;
            cout << "\nDestination is wrong\n";
            break;
        }
        else if(dest == -1) continue;
        cout << curState << "/" << dest<< " ";
        if(adjMatrix[curState][dest]) {
            switch(dest) {
            case 1:
                V++;
                break;
            case 2:
                V+=2;
                Ef+=2;
                break;
            case 3:
                V+=2;
                Ef+=2;
                Eb++;
                break;
            case 4:
                Ef++;
                break;
            case 5:
                paren.push('(');
                if(paren.empty() || paren.top() != '(') {
                    flag = 0;
                    cout << "\nParentheses Unmatched\n";
                }
                else {
                    paren.pop();
                    Ef++;
                }
                break;
            case 6:
                Ef++;
                break;
            case 7:
                Ef++;
                break;
            case 8:
                if(paren.empty() || paren.top() != '[') {
                    flag = 0;
                    cout << "\nParentheses Unmatched\n";
                }
                else {
                    paren.pop();
                    Ef++;
                }
                break;
            }
            curState = dest;
        }
        else {
            flag = 0;
            cout << "\nEndorsement error.\n";
        }
    }

    flag = flag && paren.empty() && (curState == 1 || curState == 6 || curState == 8);
    cout << '\n';
    if(flag) {
        cout << Ef+Eb*W-V;
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
