#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<vector<int>> a;

int solve_K2()
{
    vector<int> pos(N + 1);
    for (int i = 0; i < N; i++)
        pos[a[1][i]] = i;
    vector<int> seq;
    for (int i = 0; i < N; i++)
        seq.push_back(pos[a[0][i]]);
    vector<int> dp;
    for (int x : seq)
    {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end())
            dp.push_back(x);
        else
            *it = x;
    }
    return dp.size();
}

int solve_K3()
{
    vector<int> pos2(N + 1), pos3(N + 1);
    for (int i = 0; i < N; i++)
        pos2[a[1][i]] = i;
    for (int i = 0; i < N; i++)
        pos3[a[2][i]] = i;
    vector<pair<int, int>> keys;
    for (int i = 0; i < N; i++)
        keys.emplace_back(pos2[a[0][i]], pos3[a[0][i]]);
    sort(keys.begin(), keys.end());
    vector<int> dp;
    for (size_t i = 0; i < keys.size(); i++)
    {
        int p3 = keys[i].second;
        auto it = lower_bound(dp.begin(), dp.end(), p3);
        if (it == dp.end())
            dp.push_back(p3);
        else
            *it = p3;
    }
    return dp.size();
}

int main()
{
    cin >> N >> K;
    a.resize(K, vector<int>(N));
    for (int i = 0; i < K; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
    if (K == 2)
        cout << solve_K2() << endl;
    else if (K == 3)
        cout << solve_K3() << endl;
    else
        cout << "K too large" << endl;
    return 0;
}
