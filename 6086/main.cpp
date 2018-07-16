#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
#define INF 987654321
#define S 0
#define E 25
#define MAX_A 60
using namespace std;
int n, z;
char x, y;
int level[MAX_A];
int work[MAX_A];
struct Edge {
    int v, cap, rev;
    Edge(int v, int cap, int rev) :v(v), cap(cap), rev(rev) {}
};    //���� ����ü , �ݴ��ʿ� ���� �� ������ �뷮 ������ ������ ��ġ�� �������ִ�.
vector<vector<Edge>> vt;
void addEdge(int s,int e,int c){
    vt[s].emplace_back(e, c, (int)vt[e].size());
    vt[e].emplace_back(s, c, (int)vt[s].size() - 1);
}    //������ ������ ��ŭ�� �־��־� ������ ������ ��ġ�� �����Ѵ�.

bool bfs(){
    memset(level, -1, sizeof(level));        //���� �׷��� �ʱ�ȭ
    queue<int> qu;
    level[S] = 0;
    qu.push(S);        //S�� �ҽ��� �ǹ��Ѵ�.
    while (qu.size()){
        int here = qu.front();
        qu.pop();
        for (auto i : vt[here]) {
            int there = i.v;
            int cap = i.cap;
            if (level[there] == -1 && cap > 0) {    //������ ���� �������� �ʾҰ� �ܿ��뷮�� 0�̻�
                level[there] = level[here] + 1;    //������ ������+1�� �Ҵ����ش�.
                qu.push(there);
            }
        }
    }
    return level[E] != -1;    //E�� ��ũ�� �ǹ��Ѵ�. ��ũ�� ������ �Ҵ��� �ȵ� ��� 0�� ����
}

int dfs(int here, int crtcap) {
    if (here == E)return crtcap;        //��ũ�� ��� ���� �帣�� ������ return
    for (int &i = work[here]; i < vt[here].size(); i++) {    //work �迭���� ���� Ž�� ��ġ�� ����Ǿ� �ִ�.
        int there = vt[here][i].v;
        int cap = vt[here][i].cap;
        if (level[here] + 1 == level[there] && cap>0) {    //���� �׷����� 1��ŭ ũ�� �ܿ� �뷮�� 0 �̻��� ����
            int c= dfs(there, min(crtcap, cap));        //dfs�� ���� ��ġ Ž��
            if (c> 0) {        //��ũ���� �����Ͽ� �帣�� ���������� 0 �̻��� ���
                vt[here][i].cap -= c;    //���� �뷮���� ���� ������ŭ�� ����
                vt[there][vt[here][i].rev].cap += c;    //������ ������ c��ŭ �뷮�� �߰�����
                return c;
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d", &n);
    vt.resize(MAX_A);
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        scanf("%d", &z);
        int a, b;
        if ('A' <= x&&x <= 'Z')
            a = x - 'A';
        else
            a = x - 'a' + 26;
        if ('A' <= y&&y <= 'Z')
            b = y - 'A';
        else
            b = y - 'a' + 26;
        addEdge(a, b, z);
        addEdge(b, a, z);
    }
    int res = 0;
    while (bfs()){    //���� �׷����� ����� ���� ��쿡�� ����
        memset(work, 0, sizeof(work));
        while (1){
            int flow = dfs(S, INF);    //���������� ���Ͽ�
            if (!flow)break;
            res += flow;    //���������� 1�̻��� ��� maximum flow�� ������
        }
    }
    printf("%d", res);
    return 0;
}
