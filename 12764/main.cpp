#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Use {
    public:
    int id,time,type;
    bool operator <(const Use &L) const {
        if(time != L.time) return time < L.time;
        else if(type != L.type) return type<L.type;
        return id <L.id;
    }
};


int N;

int main()
{
    scanf("%d",&N);
    int room_used[100001];
    vector <Use > Data(2*N);
    vector <int > assignment(N+1);
    priority_queue <int, vector<int>, greater<int> > Q;

    for(int i=0; i<N; i++) {
        int b,c;
        scanf("%d %d",&b,&c);
        Data[i].id=Data[i+N].id=i;
        Data[i].time=b;
        Data[i+N].time=c;
        Data[i].type=1;
        Data[i+N].type=0;
    }

    sort(Data.begin(),Data.end());

    int ans=0;
    for(int i=0; i<Data.size(); i++) {
        if(Data[i].type == 0) {
            Q.push(assignment[Data[i].id]); //강의실 반납
            room_used[assignment[Data[i].id]]++;
        }
        else {
            if(Q.empty()) {
                ans++;
                assignment[Data[i].id]=ans;
            }
            else {
                assignment[Data[i].id]=Q.top();
                Q.pop();
            }
            //printf("%d번 사용자가 %d번 강의실을 대여했습니다.\n",Data[i].id,assignment[Data[i].id]);
        }
    }
    printf("%d\n",ans);
    for(int i=1; i<=ans; i++)
        printf("%d ",room_used[i]);

    return 0;
}
