#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> v;
    ifstream file("d1p1.txt");

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    string line;
    while (getline(file, line))
    {
        v.push_back(line);
    }
    int zero_cnt = 0;
    int d = 50;
    for (int i = 0; i < v.size(); i++)
    {
        string str = v[i];
        string first_half = str.substr(0, 1);
        string second_half = str.substr(1);
        // cout << first_half << " " << second_half << endl;
        if (first_half == "L")
        {
            d = (d - stoi(second_half)) % 100;
        }
        else
        {
            d = (d + stoi(second_half)) % 100;
        }

        if (d == 0)
        {
            zero_cnt++;
        }
    }
    cout << zero_cnt << endl;
    return 0;
}
