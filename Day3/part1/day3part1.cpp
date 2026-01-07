#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> v;
    ifstream file("d3p1.txt");

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
    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        char first_max = '0';
        int first_max_index = 0;
        for (int j = 0; j < v[i].length() - 1; j++)
        {

            char str = v[i][j];
            int str_num = str - '0';
            if (str_num > (first_max - '0'))
            {
                first_max = v[i][j];
                first_max_index = j;
            }
        }
        char second_max = '0';
        int second_max_index = first_max_index + 1;
        for (int k = first_max_index + 1; k < v[i].length(); k++)
        {
            char str2 = v[i][k];
            if ((str2 - '0') > (second_max - '0'))
            {
                second_max = str2;
                // second_max_index = i;
            }
        }

        string maxi = "";
        maxi += first_max;
        maxi += second_max;
        cout << "Max pair: " << maxi << endl;
        sum += stoi(maxi);
        maxi = "";
    }

    cout << sum << endl;

    return 0;
}