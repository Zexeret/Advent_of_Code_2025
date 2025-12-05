#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

vector<pair<ll, ll>> getRangedInput()
{
    vector<pair<ll, ll>> inputs;
    string line;
    while (std::getline(cin, line))
    {
        int dashPos = line.find('-');
        if (dashPos == string::npos)
        {
            break;
        }

        ll first = stoll(line.substr(0, dashPos));
        ll second = stoll(line.substr(dashPos + 1));

        inputs.push_back({first, second});
    }
    return inputs;
}

vector<ll> getNumbers()
{
    vector<ll> inputs;
    string line;
    while (std::getline(cin, line))
    {
        if (line.empty())
        {
            break;
        }
        inputs.push_back(stoll(line));
    }
    return inputs;
}

int solve()
{
    vector<pair<ll, ll>> ranges = getRangedInput();
    vector<ll> ingredients = getNumbers();

    sort(ranges.begin(), ranges.end());

    ll answer = 0;
    ll currRangePos = 0;

    for (auto &range : ranges)
    {
        if (range.first > range.second)
        {
            cout << "  Skipping invalid range: " << range.first << "-" << range.second << "\n";
            continue;
        }
        cout << "Processing range: " << range.first << "-" << range.second << "\n";
        if (currRangePos <= range.second)
        {
            ll low = max(range.first, currRangePos);
            ll high = range.second;

            ll inc = high - low + 1;
            cout << "  Adding " << inc << endl;

            answer += inc;
            currRangePos = high + 1;
        }
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