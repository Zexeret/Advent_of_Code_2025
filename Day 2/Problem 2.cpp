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

bool isInvalidId(const string &id)
{
    int length = id.length();
    int size = 1;
    // cout << "Checking ID: " << id << endl;
    for (; size <= length / 2; size++)
    {
        if (length % size != 0)
        {
            continue;
        }

        bool isInvalid = true;
        for (int i = 0; i < length; i += size)
        {
            string part = id.substr(i, size);
            string nextPart = id.substr(i + size, size);
            // cout << "  Comparing parts: " << part << " and " << nextPart << endl;
            if (part != nextPart)
            {
                // cout << "   Parts differ: " << part << " and " << nextPart << endl;
                isInvalid = false;
                break;
            }

            if (i + size >= length - size)
            {
                break;
            }
        }

        // cout << "  Part size: " << size << ", isInvalid: " << isInvalid << endl;

        if (isInvalid)
        {
            // cout << "Invalid ID found: " << id << " with part size: " << size << endl;
            return true;
        }
    }

    return false;
}

int main()
{
    vector<pair<string, string>> ranges = getInput();
    vector<string> invalidIds;
    long long answer = 0;

    for (auto range : ranges)
    {
        // cout << "Start: " << range.first << ", End: " << range.second << endl;
        for (long long i = stoll(range.first); i <= stoll(range.second); i++)
        {
            string id = to_string(i);

            if (isInvalidId(id))
            {
                invalidIds.push_back(id);
                answer += i;
            }
        }
    }

    cout << answer << endl;
}