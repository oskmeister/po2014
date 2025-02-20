#include <algorithm>
using namespace std;

int height, n;
int h[25];
int bestSum = 100, best[2];
int sumLeft[25];

void rec(int i, int sum1, int sum2, int n1, int n2, int last1, int last2, int last){
	if (sum1 > height)
		return;
	if (sum2 > height)
		return;
	if (sum1 == height && sum2 == height){
		bestSum = n1 + n2;
		if (n1 > n2)
			swap(n1, n2);
		best[0] = n1;
		best[1] = n2;
		return;
	}
	if (n1 + n2 >= bestSum - 1)
		return;
	if (i >= n)
		return;
	if (sumLeft[i] + sum1 + sum2 < height * 2)
		return;
	if (sum1 < height && sum1 + h[i] > height)
		return;
	if (sum2 < height && sum2 + h[i] > height)
		return;
	if (!i || h[i-1] != h[i] || last <= 0)
		rec(i + 1, sum1 + h[i], sum2, n1 + 1, n2, h[i], last2, 0);
	if (!i || h[i - 1] != h[i] || last <= 1)
		rec(i + 1, sum1, sum2+h[i], n1, n2+1, last2, h[i], 1);
	if (!i || h[i - 1] != h[i] || last <= -1)
		rec(i + 1, sum1, sum2, n1, n2, last1, last2, -1);
}

int main()
{
	scanf("%d%d", &height, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", h + i);
	sort(h, h + n);
	sumLeft[n] = 0;
	for (int i = n - 1; i >= 0; --i){
		sumLeft[i] = sumLeft[i + 1] + h[i];
	}
	rec(0, 0, 0, 0, 0, -1, -1, -1);
	printf("%d %d\n", best[0], best[1]);
	return 0;
}

