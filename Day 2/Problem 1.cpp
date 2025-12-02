#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<pair<string, string>> getInput()
{
    vector<pair<string, string>> ranges;

    while (true)
    {
        string line;
        getline(cin, line);
        if (line.empty())
            break;

        // Split by comma
        stringstream ss(line);
        string range;

        while (getline(ss, range, ','))
        {
            if (range.empty())
                continue;

            // Split by dash
            size_t dashPos = range.find('-');
            string start = (range.substr(0, dashPos));
            string end = (range.substr(dashPos + 1));

            ranges.push_back({start, end});
        }
    }

    return ranges;
}

bool isInvalidId(const string &id) {
    int length = id.length();
    string firstHalf = id.substr(0, length / 2);
    string secondHalf = id.substr(length / 2);
    return firstHalf == secondHalf;
}

int main()
{
    vector<pair<string, string>> ranges = getInput();
    vector<string> invalidIds;
    long long answer = 0 ;

    for (auto range : ranges)
    {
        cout << "Start: " << range.first << ", End: " << range.second << endl;
        for(long long i = stoll(range.first); i <= stoll(range.second); i++) {
            string id = to_string(i);
            
            if(isInvalidId(id)) {
                invalidIds.push_back(id);
                answer += i;
            }
           
        }
    }

    cout  << answer << endl;
}