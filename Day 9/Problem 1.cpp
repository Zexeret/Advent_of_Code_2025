#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

vector<vector<ll>> getInput()
{
    vector<vector<ll>> inputs;
    string line;
    while (std::getline(cin, line))
    {
        if (line.empty())
        {
            break;
        }

        std::stringstream ss(line);
        std::string segment;
        vector<ll> parts;

        // Loop to extract segments separated by commas
        while (std::getline(ss, segment, ','))
        {
            parts.push_back(stoll(segment));
        }

        inputs.push_back(parts);
    }

    return inputs;
}

ll getDistance(const vector<ll> &pointA, const vector<ll> &pointB)
{
    ll dx = pointA[0] - pointB[0];
    ll dy = pointA[1] - pointB[1];
    ll dz = pointA[2] - pointB[2];

    return (dx * dx + dy * dy + dz * dz);
}

ll getParent(vector<ll> &connections, ll point)
{
    return connections[point] = (connections[point] == point) ? point : getParent(connections, connections[point]);
}

int solve()
{
    vector<vector<ll>> points = getInput();
    ll n = points.size();

    vector<vector<ll>> distances;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll dist = getDistance(points[i], points[j]);
            distances.push_back({i, j, dist});
        }
    }

    sort(distances.begin(), distances.end(), [](vector<ll> &a, vector<ll> &b)
         { return a[2] < b[2]; });

    vector<ll> connections(n);
    iota(connections.begin(), connections.end(), 0);
    ll pairsToConnect = 1000;

    for (ll i = 0; i < pairsToConnect; i++)
    {
        vector<ll> couple = distances[i];
        ll pointA = getParent(connections, couple[0]);
        ll pointB = getParent(connections, couple[1]);

        if (pointA < pointB)
        {
            connections[pointB] = pointA;
        }
        else
        {
            connections[pointA] = pointB;
        }
    }

    for (int i = 0; i < n; i++)
    {
        getParent(connections, i);
    }

    vector<ll> componentSize(n, 0);
    for (int i = 0; i < n; i++)
    {
        componentSize[connections[i]]++;
    }

    sort(componentSize.begin(), componentSize.end(), greater<ll>());

    cout << componentSize[0] * componentSize[1] * componentSize[2] << "\n";

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
