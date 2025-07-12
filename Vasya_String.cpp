#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getMaxBeauty(const string &s, int k, char ch)
{
    int n = s.size();
    int left = 0, maxLen = 0, count = 0;

    for (int right = 0; right < n; ++right)
    {
        if (s[right] != ch)
            count++;

        while (count > k)
        {
            if (s[left] != ch)
                count--;

            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main()
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    int maxBeautyA = getMaxBeauty(s, k, 'a');
    int maxBeautyB = getMaxBeauty(s, k, 'b');

    cout << max(maxBeautyA, maxBeautyB) << endl;

    return 0;
}
