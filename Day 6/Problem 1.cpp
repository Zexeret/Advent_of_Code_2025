#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

vector<vector<string>> getNumbers()
{
    vector<vector<string>> inputs;
    string line;
    while (std::getline(cin, line))
    {
        if (line.empty())
        {
            break;
        }

        // split the line by spaces
        vector<string> numbers;
        stringstream ss(line);
        string num;
        while (ss >> num)
        {
            numbers.push_back(num);
        }

        inputs.push_back(numbers);
    }

    return inputs;
}

ll getInitialValue(const string &op)
{
    if (op == "+")
    {
        return 0;
    }
    else if (op == "*")
    {
        return 1;
    }
    return 0;
}

int solve()
{
    vector<vector<string>> homework = getNumbers();
    ll rows = homework.size();
    ll columns = homework[0].size();

    ll answer = 0;

    for (int c = 0; c < columns; c++)
    {
        string op = homework[rows - 1][c];
        ll solution = getInitialValue(op);
        for (int r = rows - 2; r >= 0; r--)
        {
            // cout << "Processing cell (" << r << ", " << c << ") with value " << homework[r][c] << " and operation " << op << "\n";
            if (op == "+")
            {
                solution += stoll(homework[r][c]);
            }
            else if (op == "*")
            {
                solution *= stoll(homework[r][c]);
            }
            // cout << "Intermediate solution for column " << c << ": " << solution << "\n";
        }
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