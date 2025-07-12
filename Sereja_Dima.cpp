#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++)
        cin >> cards[i];

    int sereja = 0, dima = 0;
    int l = 0, r = n - 1;
    bool turn = true;

    while (l <= r)
    {
        if (cards[l] > cards[r])
        {
            if (turn)
                sereja += cards[l];
            else
                dima += cards[l];
            l++;
        }
        else
        {
            if (turn)
                sereja += cards[r];
            else
                dima += cards[r];
            r--;
        }
        turn = !turn;
    }

    cout << sereja << " " << dima << endl;

    return 0;
}
