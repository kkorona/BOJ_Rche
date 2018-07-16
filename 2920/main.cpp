#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int N = 8;
    int input[8], ascending[8] = {1,2,3,4,5,6,7,8}, descending[8] = {8,7,6,5,4,3,2,1};
    bool asc = true, desc = true;
    for(int i=0; i<8; i++) {
        cin >> input[i];
        asc = asc && (input[i] == ascending[i]);
        desc = desc && (input[i] == descending[i]);
    }
    string ans("mixed");
    if(asc) ans="ascending";
    if(desc) ans="descending";
    cout << ans;
    return 0;
}
