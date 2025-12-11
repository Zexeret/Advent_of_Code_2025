#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

auto getInput()
{
    vector<string> targetLights;
    vector<vector<vector<ll>>> lightGroups;
    vector<vector<ll>> braceGroupValues;

    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            continue;

        string pattern;
        vector<vector<ll>> groups;
        vector<ll> braceValues;

        // 1. Extract pattern inside [ ]
        ll L = line.find('[');
        ll R = line.find(']');
        pattern = line.substr(L + 1, R - L - 1);

        // Remaining part after ]
        string rest = line.substr(R + 1);

        // 2. Extract parenthesis groups (…)
        {
            regex rgx("\\(([^()]*)\\)");
            smatch match;
            auto begin = rest.cbegin();
            while (regex_search(begin, rest.cend(), match, rgx))
            {
                string inside = match[1];
                vector<ll> nums;
                stringstream ss(inside);
                string token;
                while (getline(ss, token, ','))
                {
                    nums.push_back(stoll(token));
                }
                groups.push_back(nums);
                begin = match.suffix().first;
            }
        }

        // 3. Extract brace group {…}
        {
            regex rgx("\\{([^{}]*)\\}");
            smatch match;
            if (regex_search(rest, match, rgx))
            {
                string inside = match[1];
                stringstream ss(inside);
                string token;
                while (getline(ss, token, ','))
                {
                    braceValues.push_back(stoi(token));
                }
            }
        }

        targetLights.push_back(pattern);
        lightGroups.push_back(groups);
        braceGroupValues.push_back(braceValues);

        // // ----- Debug Print (Remove later) -----
        // cout << "Pattern: " << pattern << "\n";
        // cout << "Groups:\n";
        // for (auto &g : groups) {
        //     cout << "  ( ";
        //     for (int x : g) cout << x << " ";
        //     cout << ")\n";
        // }
        // cout << "Brace Values: ";
        // for (int x : braceValues) cout << x << " ";
        // cout << "\n\n";
        // // --------------------------------------
    }

    return make_tuple(targetLights, lightGroups, braceGroupValues);
}

ll getMinimumToggles(string targetPattern, string currentPattern, vector<vector<ll>> groups, ll currGroupInd, ll currentCount){
    ll n = groups.size() ;
    if(targetPattern == currentPattern) return currentCount ;
    if(currGroupInd == n) return LLONG_MAX ;

    // either take this group index or leave it; 
    vector<ll> switches = groups[currGroupInd] ;
    string updatedPattern = currentPattern ; 
    for(ll switchInd : switches){
        if(updatedPattern[switchInd] == '.') updatedPattern[switchInd] = '#' ;
        else updatedPattern[switchInd] = '.' ;
    }

    ll minWhenTook =  getMinimumToggles(targetPattern, updatedPattern, groups, currGroupInd + 1, currentCount + 1);

    // or dont take it and move onto next one; 
    ll minWhenMissed = getMinimumToggles(targetPattern, currentPattern, groups, currGroupInd + 1, currentCount) ;

    return min(minWhenTook, minWhenMissed) ;
}

int solve()
{
    auto input = getInput();
    vector<string> targetLights = get<0>(input);
    vector<vector<vector<ll>>> lightGroups = get<1>(input);
    vector<vector<ll>> braceGroupValues = get<2>(input);

    ll rows = targetLights.size();
    // for (ll i = 0; i < rows; i++)
    // {
    //     const string &pattern = targetLights[i];
    //     const auto &groups = lightGroups[i];
    //     const auto &braceValues = braceGroupValues[i];

    //     cout << "Target Light Pattern: " << pattern << "\n";
    //     cout << "Light Groups:\n";
    //     for (const auto &g : groups)
    //     {
    //         cout << "  ( ";
    //         for (ll x : g)
    //             cout << x << " ";
    //         cout << ")\n";
    //     }
    //     cout << "Brace Group Values: ";
    //     for (ll x : braceValues)
    //         cout << x << " ";
    //     cout << "\n\n";
    // }

    ll answer = 0;

    for(ll i = 0 ; i < rows ; i++)
    {
         auto &pattern = targetLights[i];
         auto &groups = lightGroups[i];
         auto &braceValues = braceGroupValues[i];

         //. patterns.size() times
        string initialPattern = "";
        for(ll k = 0 ; k < pattern.size() ; k++) initialPattern += '.' ;
        ll minSteps = getMinimumToggles(pattern, initialPattern, groups, 0, 0);

        answer += minSteps ;
     
    }

    cout << answer ;

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
