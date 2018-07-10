#include <cstdio>
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include <cstdlib>

using namespace std;

class mycomparison
{
      bool reverse;
    public:
      mycomparison(const bool& revparam=false)
        {reverse=revparam;}
      bool operator() (const int& lhs, const int&rhs) const
      {
        if (!reverse)  {
            if(abs(lhs) != abs(rhs)) return (abs(lhs)>abs(rhs));
            else return lhs > rhs;
        }
        else {
            if(abs(lhs) != abs(rhs)) return (abs(lhs)<abs(rhs));
            else return lhs < rhs;
        }
      }
};

int main() {
    int N;
    priority_queue < int, vector<int>, mycomparison > min_heap;

    scanf("%d",&N);

    while(N--) {
        int order;
        scanf("%d",&order);
        if(order == 0) {
            if(min_heap.empty()) printf("0");
            else {
                printf("%d",min_heap.top());
                min_heap.pop();
            }
            printf("\n");
        }
        else min_heap.push(order);
    }
}

