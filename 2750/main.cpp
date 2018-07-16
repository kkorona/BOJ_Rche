#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector <int > arr;
    scanf("%d",&n);
    while(n--) {
        int x;
        scanf("%d",&x);
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    for(int i=0; i<arr.size(); i++)
        printf("%d\n",arr[i]);
    return 0;
}
