#include <iostream>
#include <vector>
#include <unordered_map>
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
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }

        long long target_mult = 2 * sum;
        if (target_mult % n != 0)
        {
            cout << 0 << '\n';
            continue;
        }

        long long target = target_mult / n;

        unordered_map<long long, int> freq;
        for (auto num : a)
            freq[num]++;

        long long ans = 0;
        for (auto num : a)
        {
            freq[num]--;
            long long need = target - num;
            if (freq.count(need))
                ans += freq[need];
        }

        cout << ans << '\n';
    }
    return 0;
}
