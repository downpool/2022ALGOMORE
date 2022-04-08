#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//"greedy" -> "냅색(knapsack)"
int pp[1001][100001] = {0};
int main() {

    //input
    int n, x;
    cin >> n >> x;
    int price[n + 1];
    int page[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> page[i];
    }

    //냅색 알고리즘
    for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= x; j++)
		{   
			if (j >= price[i])
				pp[i][j] = max(pp[i - 1][j], page[i] + pp[i - 1][j - price[i]]);
			else pp[i][j] = pp[i - 1][j];
		}
	}
    cout << pp[n][x];

    return 0;
}