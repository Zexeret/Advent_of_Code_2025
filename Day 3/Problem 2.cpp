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

ll solve2(string n, int k)
{
    string str = string(n);
    ll dp[5000][32];
    memset(dp, 0, sizeof(dp));
    for (ll i = 0; i < str.length(); ++i)
    {
        dp[i + 1][1] = max(dp[i][1], (ll)(str[i] - '0'));
        for (ll j = 2; j <= k; ++j)
        {
            dp[i + 1][j] = max(dp[i][j - 1] * 10 + str[i] - '0', dp[i][j]);
        }
    }

    return dp[str.length()][k];
}

int solve()
{
    vector<string> inputs = getInput();
    ll answer = 0;

    cout << inputs.size() << "\n";
    for (const string &input : inputs)
    {
        ll mxansw = solve2(input, 12);
        answer += mxansw;
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

// 17031