#include <iostream>
#include <bits/stdc++.h>

using namespace std;

pair<char, int> parseRotation(string rotation)
{
    char direction = rotation[0];
    int amount = stoi(rotation.substr(1));
    return {direction, amount};
}

int main()
{
    string next_rotation;
    int dial_position = 50; // starts with 50
    int safe_password = 0;  // count of times when dial_position == 0

    while (cin >> next_rotation)
    {
        auto [direction, amount] = parseRotation(next_rotation);
        if (direction == 'L')
        {
            dial_position -= amount;
        }
        else if (direction == 'R')
        {
            dial_position += amount;
        }

        dial_position = (dial_position + 100) % 100;
        if (dial_position == 0)
        {
            safe_password++;
        }
    }

    cout << safe_password << endl;
    cout << endl;
}