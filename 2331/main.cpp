#include <iostream>

using namespace std;

int A,p;

int pow(int a,int b) {
    int ret=1;
    for(int i=b; i>0; i--)
        ret*=a;
    return ret;
}

int process(int t) {
    int ret=0;
    while(t>0) {
        int q=t%10;
        ret+=pow(q,p);
        t/=10;
    }
    return ret;
}

int main()
{
    int visit[300000]={0,};

    cin >> A >> p;

    int cnt=1;
    int cur=0,next=A;

    do {
        cur=next;
        visit[cur]=cnt++;
        next=process(cur);
        //cout << cur << " ";
    }while(visit[next] == 0);

    cout << visit[next]-1;

    return 0;
}
