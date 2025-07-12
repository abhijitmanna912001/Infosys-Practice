#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;

    vector<long long> freq(n + 2, 0);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        freq[l - 1] += 1;
        freq[r] -= 1;
    }

    for (int i = 1; i < n; i++)
        freq[i] += freq[i - 1];

    freq.resize(n);
    sort(a.rbegin(), a.rend());
    sort(freq.rbegin(), freq.rend());

    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] * freq[i];

    cout << ans << '\n';
    return 0;
}