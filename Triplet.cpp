#include <bits/stdc++.h>
using namespace std;

int greedy_approach(int N, int M, vector<int> &arr)
{
    vector<int> cnt(M + 5, 0);
    for (int x : arr)
        cnt[x]++;

    int ans = 0;
    for (int i = 1; i <= M; i++)
    {
        while (cnt[i] > 0 && cnt[i + 1] > 0 && cnt[i + 2] > 0)
        {
            ans++;
            cnt[i]--;
            cnt[i + 1]--;
            cnt[i + 2]--;
        }
    }

    for (int i = 1; i <= M; i++)
        ans += cnt[i] / 3;

    return ans;
}

int brute_force(int N, int M, vector<int> &arr)
{
    vector<bool> used(N, false);
    int triplets = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (used[i] || used[j] || used[k])
                    continue;

                vector<int> temp = {arr[i], arr[j], arr[k]};
                sort(temp.begin(), temp.end());

                if (temp[0] == temp[1] && temp[1] == temp[2])
                {
                    triplets++;
                    used[i] = used[j] = used[k] = true;
                }

                else if (temp[0] + 1 == temp[1] && temp[1] + 1 == temp[2])
                {
                    triplets++;
                    used[i] = used[j] = used[k] = true;
                }
            }
        }
    }
    return triplets;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << brute_force(N, M, arr) << endl;
    cout << greedy_approach(N, M, arr) << endl;
    return 0;
}