#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n,k;
    string input;

    cin >> n >> k;
    cin >> input;

    set < char > S;
    char minimum = 'z';
    char maximum = 'a';

    for(char c : input) {
        S.insert(c);
        minimum = min(minimum,c);
        maximum = max(maximum,c);
    }

    if(n >= k) {
        int i;
        for(i=k-1; i>=0; i--) {
            char c = input.at(i);
            if(c == maximum) continue;
            else {
                break;
            }
        }
        char pp = input.at(i);
        for(char c : S) {
            if(c > pp) {
                pp=c;
                break;
            }
        }
        input[i] = pp;
        for(int j=i+1; j<n; j++)
            input[j] = minimum;
    }
    else {
        for(int j=n-1; j<k; j++)
            input.push_back(minimum);
    }

    for(int i=0; i<k; i++)
        cout << input[i];
    return 0;
}
