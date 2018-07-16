#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


long long L,MAX;
int K,C;
vector <long long > Cut(10001,0);

int b_search(int _st,int _ed,long long tar) {
    int lo=_st,hi=_ed;

    while(lo <= hi) {
        int mid=(lo+hi)/2;
        if(Cut[mid] == tar) return mid;
        else if(Cut[mid] < tar) hi=mid-1;
        else lo=mid+1;
    }
    return hi;
}

void Process() {
    long long st=0, ed=L;
    int cut_st=0,cut_ed=K;

    int index_first=b_search(cut_st,cut_ed,(st+ed)/2);
    MAX = L - Cut[index_first];
    C--;

    queue < long long > Qst;
    queue < long long > Qed;
    queue < int > Qcst;
    queue < int > Qced;

    //right log
    Qst.push(Cut[index_first]);
    Qed.push(ed);
    Qcst.push(index_first+1);
    Qced.push(cut_ed);

    //left log
    Qst.push(st);
    Qed.push(Cut[index_first]);
    Qcst.push(cut_st);
    Qced.push(index_first);

    while(C>0) {
        C--;
        st=Qst.front();
        ed=Qed.front();
        cut_st=Qcst.front();
        cut_ed=Qced.front();

        Qst.pop();
        Qed.pop();
        Qcst.pop();
        Qced.pop();

        int index=b_search(cut_st,cut_ed,(st+ed)/2);
        MAX = min(MAX,ed - Cut[index]);
        MAX = min(MAX,Cut[index] - st);
        //right log
        Qst.push(Cut[index]);
        Qed.push(ed);
        Qcst.push(index+1);
        Qced.push(cut_ed);

        //left log
        Qst.push(st);
        Qed.push(Cut[index]);
        Qcst.push(cut_st);
        Qced.push(index);
    }

    cout << MAX << " " << Cut[index_first];

}

int main()
{

    cin >> L >> K >> C;
    Cut.resize(K,0);
    for(int i=0; i<K; i++)
        cin >> Cut[i];

    sort(Cut.begin(),Cut.end());

    Process();


    return 0;
}
