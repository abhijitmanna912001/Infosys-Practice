#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    int x[105];

    for (int i = 0; i < n; i++)
        cin >> x[i];

    int max_profit = 0;

    for (int d = 0; d < n - 1; d++)
    {
        int profit = x[d] - x[d + 1] - c;
        if (profit > max_profit)
            max_profit = profit;
    }

    cout << max_profit << endl;
    return 0;
}