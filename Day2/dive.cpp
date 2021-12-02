
#include <iostream>
#include <algorithm>

using namespace std;

void calculate_difference(int & horizonal_pos, int & depth, int & aim, string command, int value)
{
    if (command == "forward")
    {
        horizonal_pos += value;
        depth += value * aim;
    }
    else if (command == "up")
    {
        aim -= value;
    }
    else // Down
    {
        aim += value;
    }
}

int main()
{
    int horizonal_pos{}, depth{}, aim{};
    string command;
    while (cin >> command)
    {
        int value{};
        cin >> value;
        calculate_difference(horizonal_pos, depth, aim, command, value);
    }
    cout << horizonal_pos * depth << endl;
    return 0;
}