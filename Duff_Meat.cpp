#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long total_cost = 0;
    int min_price = 1e9;

    for (int i = 0; i < n; i++)
    {
        int a, p;
        cin >> a >> p;
        min_price = min(min_price, p);
        total_cost += (long long)a * min_price;
    }

    cout << total_cost << endl;
    return 0;
}