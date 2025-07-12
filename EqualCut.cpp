#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // Precompute prefix sums
    vector<long long> prefix(N);
    prefix[0] = A[0];
    for (int i = 1; i < N; i++)
        prefix[i] = prefix[i - 1] + A[i];

    long long ans = LLONG_MAX;

    // For each middle cut j (between C and D)
    for (int j = 1; j < N - 2; j++)
    {
        // left part: A[0..j]
        int l = 0;
        long long totalLeft = prefix[j];

        while (l + 1 < j)
        {
            long long left1 = prefix[l];
            long long right1 = totalLeft - left1;
            long long left2 = prefix[l + 1];
            long long right2 = totalLeft - left2;

            if (abs(left2 - right2) < abs(left1 - right1))
                l++;
            else
                break;
        }

        // right part: A[j+1..N-1]
        int r = j + 1;
        long long totalRight = prefix[N - 1] - prefix[j];

        while (r + 1 < N - 1)
        {
            long long left1 = prefix[r] - prefix[j];
            long long right1 = totalRight - left1;
            long long left2 = prefix[r + 1] - prefix[j];
            long long right2 = totalRight - left2;

            if (abs(left2 - right2) < abs(left1 - right1))
                r++;
            else
                break;
        }

        long long P = prefix[l];
        long long Q = prefix[j] - prefix[l];
        long long R = prefix[r] - prefix[j];
        long long S = prefix[N - 1] - prefix[r];

        long long mx = max({P, Q, R, S});
        long long mn = min({P, Q, R, S});
        ans = min(ans, mx - mn);
    }

    // Brute Force
    // Try all possible cuts: i<j<k
    // for (int i = 0; i < N - 3; i++)
    // {
    //     for (int j = i + 1; j < N - 2; j++)
    //     {
    //         for (int k = j + 1; k < N - 1; k++)
    //         {
    //             long long P = prefix[i];
    //             long long Q = prefix[j] - prefix[i];
    //             long long R = prefix[k] - prefix[j];
    //             long long S = prefix[N - 1] - prefix[k];

    //             long long mx = max({P, Q, R, S});
    //             long long mn = min({P, Q, R, S});
    //             ans = min(ans, mx - mn);
    //         }
    //     }
    // }

    cout << ans << endl;
    return 0;
}
