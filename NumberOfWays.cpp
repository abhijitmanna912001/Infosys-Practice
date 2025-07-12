#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long total_sum = 0;
    for (int i = 0; i < n; ++i)
        total_sum += a[i];

    if (total_sum % 3 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    long long target = total_sum / 3;
    long long prefix_sum = 0;
    long long count_target = 0;
    long long answer = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        prefix_sum += a[i];
        if (prefix_sum == 2 * target)
            answer += count_target;

        if (prefix_sum == target)
            count_target++;
    }

    cout << answer << endl;
    return 0;
}
