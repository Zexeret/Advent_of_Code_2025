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
        safe_password += (amount / 100);
        amount = amount % 100;

        if (direction == 'L')
        {
            if (dial_position != 0 && amount >= dial_position)
                safe_password++;
            dial_position -= amount;
        }
        else if (direction == 'R')
        {
            if (dial_position != 0 && amount >= 100 - dial_position)
                safe_password++;
            dial_position += amount;
        }

        dial_position = (dial_position + 100) % 100;
    }

    cout << safe_password << endl;
    cout << endl;
}