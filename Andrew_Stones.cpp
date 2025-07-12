#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (n == 3)
        {
            if (a[1] % 2 == 0)
                cout << a[1] / 2 << '\n';
            else
                cout << -1 << '\n';
        }
        else
        {
            bool allOne = true;
            for (int i = 1; i <= n - 2; i++)
            {
                if (a[i] != 1)
                {
                    allOne = false;
                    break;
                }
            }
            if (allOne)
                cout << -1 << '\n';
            else
            {
                long long ans = 0;
                for (int i = 1; i <= n - 2; i++)
                {
                    ans += (a[i] + 1) / 2;
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}
