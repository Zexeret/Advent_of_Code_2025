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

set<pair<ll, ll>> counter;

void propagateBeam(ll beamIndices[][500], vector<string> &tachyon, ll cx, ll cy)
{
    ll rows = tachyon.size();
    ll cols = tachyon[0].size();
    if (cx >= cols || cx < 0 || cy >= rows)
        return;

    if (tachyon[cy][cx] == '^' || tachyon[cy][cx] == 'S')
    {
        return;
    }

    if (cy - 1 > 0)
    {
        beamIndices[cy][cx] += beamIndices[cy - 1][cx];

        if (cx - 1 >= 0 && tachyon[cy][cx - 1] == '^')
        {
            beamIndices[cy][cx] += beamIndices[cy - 1][cx - 1];
        }

        if (cx + 1 < cols && tachyon[cy][cx + 1] == '^')
        {
            beamIndices[cy][cx] += beamIndices[cy - 1][cx + 1];
        }
    }
}

int solve()
{
    vector<string> tachyon = getNumbers();
    ll rows = tachyon.size();
    ll cols = tachyon[0].size();
    ll beamIndices[500][500] = {0};

    // get the index of S char.

    for (ll r = 0; r < rows; r++)
    {
        for (ll c = 0; c < cols; c++)
        {
            if (tachyon[r][c] == 'S')
            {
                beamIndices[r + 1][c] = 1;
                continue;
            }

            propagateBeam(beamIndices, tachyon, c, r);
        }
    }
    ll answer = 0;

    for (ll c = 0; c < cols; c++)
    {
        answer += beamIndices[rows - 1][c];
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