#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    ifstream file("d6p1.txt");
    vector<vector<string>> v;
    if (!file.is_open())
    {
        printf("Error opening file\n");
        return 1;
    }
    string line;
    vector<vector<string>> matrix;
    while (getline(file, line))
    {
        stringstream ss(line);
        vector<string> row;
        string token;

        while (ss >> token)
        {
            row.push_back(token);
        }
        matrix.push_back(row);
    }

    long long total_sum = 0;
    for (int col = 0; col < matrix[0].size(); col++)
    {
        long long col_operations;
        string operation = matrix[matrix.size() - 1][col];
        // cout << operation << " ";
        if (operation == "*")
        {
            col_operations = 1;
        }
        else
        {
            col_operations = 0;
        }
        for (int row = 0; row < matrix.size() - 1; row++)
        {
            if (operation == "*")
            {
                col_operations *= stoll(matrix[row][col]);
            }
            else if (operation == "+")
            {
                col_operations += stoll(matrix[row][col]);
            }
        }
        // cout << col_operations << " ";
        total_sum += col_operations;
    }

    cout << total_sum << " ";
    return 0;
}