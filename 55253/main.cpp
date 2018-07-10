#include <iostream>
#include <string>
using namespace std;

int pi[1000001];

void kmp(const string& pat) {
    int n = pat.length();
    int i = -1, j = 0;
    pi[j] = i;
    while(j < n) {
        if(i == -1 || (i >= 0 && pat[i] == pat[j])) {
            i++;
            j++;
            pi[j] = i;
        }
        else i = pi[i];
    }
}

//문자열 비교
int find_pattern(const string& arr, const string& pat) {
    int n = arr.length();
    int m = pat.length();
    int cnt = 0;
    int i = 0, j = 0;
    while(i < n) {
        if(j == -1 || (j >= 0 && arr[i] == pat[j])) i++, j++;
        else if(arr[i] != pat[j]) j = pi[j];
        if(j == m) {
            cnt++;
            j = pi[j];
        }
    }
    return cnt;
}

int main() {
    int N,M;
    string input;
    cin >> N >> M;
    string P = "IOI";
    N--;
    while(N--) P.append("OI");
    cin >> input;
    kmp(P);
    cout << find_pattern(input,P);
    return 0;
}
