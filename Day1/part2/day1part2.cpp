#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> v;
    ifstream file("d1p2.txt");

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    string line;
    // while (getline(file, line))
    // {
    //     v.push_back(line);
    // }
    int zero_cnt = 0;
    long long d = 50;
    while (getline(file, line))
    {
        char dir = line[0];
        long long steps = stoll(line.substr(1));
        long long firstHit;
        if (dir == 'R')
            firstHit = (100 - d) % 100;
        else
            firstHit = d % 100;

        if (firstHit == 0)
            firstHit = 100;

        if (firstHit <= steps)
            zero_cnt += 1 + (steps - firstHit) / 100;
        if (dir == 'R')
            d = (d + steps) % 100;
        else
            d = (d - steps % 100 + 100) % 100;
    }
    cout << zero_cnt << endl;
    return 0;
}
