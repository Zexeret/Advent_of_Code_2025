#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

vector<string> getInput()
{
    vector<string> inputs;
    string line;
    while (std::getline(cin, line))
    {
        inputs.push_back(line);
    }
    return inputs;
}

int countOfAdjacentSymbols(const vector<string> &inputs, int rowIndex, int columnIndex)
{
    int countOfAdjacent = 0;
    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            if (dx == 0 && dy == 0)
                continue;

            int ycoord = rowIndex + dy, xcoord = columnIndex + dx;

            if (ycoord < 0 || ycoord >= (int)inputs.size())
                continue;
            if (xcoord < 0 || xcoord >= (int)inputs[ycoord].size())
                continue;

            if (inputs[ycoord][xcoord] == '@')
                ++countOfAdjacent;
        }
    }
    return countOfAdjacent;
}

int solve()
{
    vector<string> inputs = getInput();
    vector<string> nextInput = inputs;
    int rows = inputs.size();
    if (rows == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    int ans = 0;
    int currCount = 0;
    do
    {
        currCount = 0;
        for (int r = 0; r < rows; ++r)
        {
            int cols = inputs[r].size();
            for (int c = 0; c < cols; ++c)
            {
                if (inputs[r][c] != '@')
                    continue;
                int cnt = countOfAdjacentSymbols(inputs, r, c);
                if (cnt < 4)
                {
                    nextInput[r][c] = '.';
                    ++currCount;
                }
            }
        }

        inputs = nextInput;
        ans += currCount;
    } while (currCount > 0);

    cout << ans << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // #########***************************FROM BELOW*******************************####################

    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

// 17031