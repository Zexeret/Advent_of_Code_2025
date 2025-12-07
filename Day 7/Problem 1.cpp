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
ll answer = 0 ;

void propagateBeam(ll beamIndices[][500], vector<string> &tachyon, ll cx, ll cy)
{
    ll rows = tachyon.size();
    ll cols = tachyon[0].size();
    if (cx >= cols || cx < 0 || cy >= rows)
        return;

    if (cy == rows - 1 ||  beamIndices[cy][cx] == 1)
    {
        // reached the end
        return;
    }

    if (tachyon[cy][cx] == '^')
    {
        beamIndices[cy][cx] = 1;
        counter.insert({cy, cx});
        answer++ ;
        propagateBeam(beamIndices, tachyon, cx - 1, cy);
        propagateBeam(beamIndices, tachyon, cx + 1, cy);
    }
    else
    {
        propagateBeam(beamIndices, tachyon, cx, cy + 1);
    }
}

int solve()
{
    vector<string> tachyon = getNumbers();
    ll rows = tachyon.size();
    ll cols = tachyon[0].size();
    ll beamIndices[500][500] = {0};

    // get the index of S char.

    for (ll i = 0; i < cols; i++)
    {
        if (tachyon[0][i] == 'S')
        {
            propagateBeam(beamIndices, tachyon, i, 1);
        }
    }

    cout << counter.size() << "\n";
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