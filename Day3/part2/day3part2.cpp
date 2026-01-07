#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> v;
    ifstream file("d3p2.txt");

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
    long long sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int max_pos = 0;
        int cnt = 12;
        string maxi = "";
        while (cnt)
        {
            char latest_max = '0';
            int latest_index = -1;
            for (int j = max_pos; j <= v[i].length() - cnt; j++)
            {
                if (v[i][j] > latest_max)
                {
                    latest_max = v[i][j];
                    latest_index = j;
                }
            }
            maxi += latest_max;
            max_pos = latest_index + 1;
            cnt--;
        }
        cout << "maxi" << maxi << endl;
        sum += stoll(maxi);
    }
    cout << sum << endl;

    return 0;
}