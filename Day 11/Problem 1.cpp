#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

map<string, vector<string>> getInput()
{
    map<string, vector<string>> graph;
    string line;

    while (getline(cin, line))
    {
        if (line.empty())
            continue;

        // Split at ':'
        size_t pos = line.find(':');
        if (pos == string::npos)
            continue; // invalid format

        string key = line.substr(0, pos);
        string rest = line.substr(pos + 1);

        // Trim leading spaces
        while (!rest.empty() && rest[0] == ' ')
            rest.erase(rest.begin());

        // Split by spaces into tokens
        stringstream ss(rest);
        string node;
        while (ss >> node)
        {
            graph[key].push_back(node);
        }
    }

    // Output parsed data to verify
    // for (auto &p : graph) {
    //     cout << p.first << " -> ";
    //     for (auto &v : p.second) cout << v << " ";
    //     cout << "\n";
    // }

    return graph;
}

map<string, ll> visited;

ll pathFrom(string node, map<string, vector<string>> graph)
{
    if (node == "out")
        return 1;

    visited[node] = -1;
    ll paths = 0;
    for (auto nextNode : graph[node])
    {
        if (visited.find(nextNode) != visited.end())
        {
            if (visited[nextNode] == -1)
                continue;
        } else {
            visited[nextNode] = pathFrom(nextNode, graph);
        }
        
        paths += visited[nextNode];
    }

    return paths;
}

int solve()
{
    map<string, vector<string>> graph = getInput();

    ll answer = 0;
    visited["out"] = 1;

    cout << pathFrom("svr", graph) << endl;

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
