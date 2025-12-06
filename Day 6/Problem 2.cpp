#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

vector<string> getNumbers()
{
    vector<string> inputs;
    string line;
    while (std::getline(cin, line))
    {
        if (line.empty())
        {
            break;
        }

        inputs.push_back(line);
    }

    return inputs;
}

ll getInitialValue(char &op)
{
    if (op == '+')
    {
        return 0;
    }
    else if (op == '*')
    {
        return 1;
    }
    return 0;
}

int solve()
{
    vector<string> homework = getNumbers();
    ll rows = homework.size();
    ll answer = 0;

    ll maxCols = 0;
    for (const string &row : homework)
    {
        maxCols = max(maxCols, (ll)row.size());
        // cout << maxCols << "\n";
    }
    for (string &row : homework)
    {
        row.resize(maxCols, ' ');
        // cout << row << "\n";
    }

    ll currCol = 0;
    for (; currCol < maxCols;)
    {
        char op = homework[rows - 1][currCol];
        ll solution = getInitialValue(op);
        do
        {
            string num = "";
            for (ll r = 0; r < rows - 1; r++)
            {
                if (homework[r][currCol] != ' ')
                {
                    num.append(1, homework[r][currCol]);
                }
            }
            if (num.empty())
            {
                currCol++;
                continue;
            }

            if (op == '+')
            {
                solution += stoll(num);
            }
            else if (op == '*')
            {
                solution *= stoll(num);
            }
            // cout << num << " " << solution << "\n";
            currCol++;
        } while (currCol < maxCols && (homework[rows - 1][currCol] != '+' && homework[rows - 1][currCol] != '*'));

        answer += solution;
    }

    cout << answer << "\n";
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