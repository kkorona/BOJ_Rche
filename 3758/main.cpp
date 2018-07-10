#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k,t;
class team_score {
public:
    vector <int> Score;
    int ScoreSum=0;
    int lastSubmitTime=0;
    int submitCount=0;

    team_score(int k) {
        Score.resize(k+1,0);
    }
    void renew(int problem, int renewScore,int time) {
        if(Score[problem] < renewScore) {
            ScoreSum+=renewScore-Score[problem];
            Score[problem] = renewScore;
        }
        submitCount++;
        lastSubmitTime = time;
    }

    bool operator < (const team_score& rhs) const {
        if(ScoreSum != rhs.ScoreSum) return ScoreSum < rhs.ScoreSum;
        else if(submitCount != rhs.submitCount) return submitCount > rhs.submitCount;
        return lastSubmitTime > rhs.lastSubmitTime;
    }
};

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d%d",&n,&k,&t,&m);
        vector < team_score > Data(n+1,team_score(k));
        while(m--) {
            int i,j,s;
            scanf("%d%d%d",&i,&j,&s);
            Data[i].renew(j,s,-m);
        }
        int ans=1;
        for(int i=1; i<=n; i++) {
            //printf("%d %d %d %d\n",i,Data[i].ScoreSum,Data[i].submitCount,Data[i].lastSubmitTime);
            if(Data[t] < Data[i]) ans++;
        }
        printf("%d\n",ans);
    }

    return 0;
}
