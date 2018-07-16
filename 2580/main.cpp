#include <iostream>
#include <vector>
using namespace std;

vector < vector <int> > use_vertical(10,vector<int>(10,0));
vector < vector <int> > use_horizental(10,vector<int>(10,0));
vector < vector <int> > sudoku(10,vector<int>(10,0));
vector < pair < int,int > > target;
int use_box[3][3][10] = {0,};

const int N = 9;
int M;
bool flag = false;
void backtrack(int cur) {

    if(flag) return;
    if(cur == M) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++)
                cout << sudoku[i][j] << " ";
            cout << "\n";
        }
        flag = true;
        return;
    }

    int y = target[cur].first;
    int x = target[cur].second;
    for(int i=1; i<=9; i++) {
        if(use_vertical[y][i] == 0 && use_horizental[x][i] == 0 && use_box[(y-1)/3][(x-1)/3][i] == 0) {
            sudoku[y][x] = i;
            use_vertical[y][i] = 1;
            use_horizental[x][i] = 1;
            use_box[(y-1)/3][(x-1)/3][i] = 1;
            backtrack(cur+1);
            sudoku[y][x] = 0;
            use_vertical[y][i] = 0;
            use_horizental[x][i] = 0;
            use_box[(y-1)/3][(x-1)/3][i] = 0;
        }
    }
}

int main()
{
    int temp;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            cin >> temp;
            sudoku[i][j]=temp;
            use_vertical[i][temp] = 1;
            use_horizental[j][temp] = 1;
            use_box[(i-1)/3][(j-1)/3][temp] = 1;
            if(temp == 0) target.push_back(make_pair(i,j));
        }

    M=target.size();

    backtrack(0);

    return 0;
}
