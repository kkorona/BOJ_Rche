#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 201505

int n, s[N], total;
int size[N], color[N], cnt;

struct A {
	int size, color, index;
	int sum;
} a[N];

bool comp(A x, A y) { return x.size < y.size; }
bool comp2(A x, A y) { return x.index < y.index; }

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].color, &a[i].size);
		a[i].index = i;
	}

	sort(a + 1, a + n + 1, comp);

	for(int i = 1; i <= n; i++) {
		if(a[i].size != a[i - 1].size) {
			for(int j = 1; j <= cnt; j++) {
				s[color[j]] += size[j];
				total += size[j];
			}
			cnt = 0;
		}

		cnt++;
		size[cnt] = a[i].size;
		color[cnt] = a[i].color;

		a[i].sum = total - s[a[i].color];
	}

	sort(a + 1, a + n + 1, comp2);

	for(int i = 1; i <= n; i++) {
		printf("%d\n", a[i].sum);
	}
	return 0;
}
