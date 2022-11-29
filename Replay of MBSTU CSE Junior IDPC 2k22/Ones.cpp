#include <stdio.h>
#include <string.h>

#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long LL;
const int N = 100005;

int n;
char a[N], b[N];

int main() {
	int task;
	for (scanf("%d", &task); task--; ) {
		scanf("%d%s%s", &n, a + 1, b + 1);
		LL s1 = 0, s2 = 0, c1 = 0, c2 = 0, res = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != 48) {
				res += c2 * i - s2;
				c1 += 1, s1 += i;
			}
			if (b[i] != 48) {
				res += c1 * i - s1;
				c2 += 1, s2 += i;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}