#include <stdio.h>
#include <algorithm>
#include <vector>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
class DATA{
public:
 int s, e;
 const bool operator < (const DATA &d) const{
 return s < d.s; // all s is distinct
 }
 DATA(){}
 DATA(int _s,int _e){ s = _s; e = _e; }
};
bool intersect(const DATA &a, const DATA &b){
 return (a.s < b.s) != (a.e < b.e);
}
int main(){
 vector<DATA> d;
 vector<int> A, B;
 int n, i, s, e;
 scanf("%d",&n);
 for(i=0;i<n;i++){
 scanf("%d %d",&s,&e);
 d.push_back(DATA(s,e));
 }
 sort(d.begin(), d.end());
 int last = -1;
 for(i=0;i<n;i++){
 if(last == -1 || !intersect(d[last], d[i])){
 A.push_back(i);
 last = i;
 }
 else B.push_back(i);
 }
 int as, bs, sol, res, tas, tbs, bal;
 as = 0; bs = 0;
 sol = (n>0)?1:0;
 while(as < A.size() && bs < B.size()){
 if(intersect(d[A[as]], d[B[bs]])){
 tas = as; tbs = bs;
 bal = 0;
 res = 2;
 while(1){
 if( bal <= 0 && as+1 < A.size() && intersect(d[A[as+1]], d[B[bs]]) ){ as ++; res ++; bal = 1;}
 else if( bal >= 0 && bs+1 < B.size() && intersect(d[A[as]], d[B[bs+1]]) ){ bs ++; res ++; bal = -1;}
else if(as+1 < A.size() && intersect(d[A[as+1]], d[B[bs]])) as ++;
 else if(bs+1 < B.size() && intersect(d[A[as]], d[B[bs+1]])) bs ++;
 else break;
 }
 sol = max(sol, res);

 as = tas; bs = tbs;
 bal = 0;
 res = 2;
 while(1){
 if( bal >= 0 && bs+1 < B.size() && intersect(d[A[as]], d[B[bs+1]]) ){ bs ++; res ++; bal = -1;}
 else if( bal <= 0 && as+1 < A.size() && intersect(d[A[as+1]], d[B[bs]]) ){ as ++; res ++; bal = 1;}
 else if(bs+1 < B.size() && intersect(d[A[as]], d[B[bs+1]])) bs ++;
 else if(as+1 < A.size() && intersect(d[A[as+1]], d[B[bs]])) as ++;
 else break;
 }

 as ++; bs ++;
 sol = max(sol, res);
 }
 else{
 if(d[A[as]].s < d[B[bs]].s) as++;
 else bs++;
 }
 }
 printf("%d",sol);
 return 0;
}
