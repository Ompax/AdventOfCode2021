
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> countVector{};
void solve(string const &diagnostic)
{
    for (int index{}; index < diagnostic.length(); ++index)
    {
        int value = diagnostic[index] - '0'; // Convert char to integer representation.
        countVector[index] += value;
    }
}

void printOutput(const int totalRuns)
{
    string finalBinary{};
    string invertedBinary{};
    for (auto value : countVector)
    {
        if (value > totalRuns / 2)
        {
            finalBinary.append("1");
            invertedBinary.append("0");
        }
        else
        {
            finalBinary.append("0");
            invertedBinary.append("1");
        }
    }
    auto gamma = stoull(finalBinary, 0, 2);
    auto epsilon = stoull(invertedBinary, 0, 2);
    cout << gamma * epsilon << endl;
}

int main()
{
    string diagnostic{};
    bool firstrun{true};
    int totalRuns{};
    while (cin >> diagnostic)
    {
        if (firstrun)
        {
            countVector.resize(diagnostic.length());
            fill(countVector.begin(), countVector.end(), 0);
            firstrun = false;
        }
        solve(diagnostic);
        totalRuns++;
    }
    printOutput(totalRuns);
    return 0;
}