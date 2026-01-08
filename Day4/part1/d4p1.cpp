#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool checkUpperAdjecent(vector<vector<char>> &v, int i, int j)
{
    if (i - 1 >= 0)
    {
        if ('@' == v[i - 1][j])
        {
            return true;
        }
    }
    return false;
}

bool checkLeftAdjecent(vector<vector<char>> &v, int i, int j)
{
    if (j - 1 >= 0)
    {
        if ('@' == v[i][j - 1])
        {
            return true;
        }
    }
    return false;
}

bool checkRightAdjecent(vector<vector<char>> &v, int i, int j)
{
    if (j + 1 < v[0].size())
    {
        if ('@' == v[i][j + 1])
        {
            return true;
        }
    }
    return false;
}

bool checkDownAdjecent(vector<vector<char>> &v, int i, int j)
{
    if (i + 1 < v.size())
    {
        if ('@' == v[i + 1][j])
        {
            return true;
        }
    }
    return false;
}

bool checkLeftTopAdjecent(vector<vector<char>> &v, int i, int j)
{
    if (i - 1 >= 0 && j - 1 >= 0)
    {
        if ('@' == v[i - 1][j - 1])
        {
            return true;
        }
    }
    return false;
}

bool checkRightTopAdjecent(vector<vector<char>> &v, int i, int j)
{
    if (i - 1 >= 0 && j + 1 < v[0].size())
    {
        if ('@' == v[i - 1][j + 1])
        {
            return true;
        }
    }
    return false;
}

bool checkLeftDownAdjecent(vector<vector<char>> &v, int i, int j)
{
    if (i + 1 < v.size() && j - 1 >= 0)
    {
        if ('@' == v[i + 1][j - 1])
        {
            return true;
        }
    }
    return false;
}

bool checkRightDownAdjecent(vector<vector<char>> &v, int i, int j)
{
    if (i + 1 < v.size() && j + 1 < v[0].size())
    {
        if ('@' == v[i + 1][j + 1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream file("d4p1.txt");

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    vector<string> line;
    string str;
    while (getline(file, str))
    {
        line.push_back(str);
    }

    vector<vector<char>> v(line.size(), vector<char>(line[0].size()));

    for (int i = 0; i < line.size(); i++)
    {
        for (int j = 0; j < line[i].size(); j++)
        {
            v[i][j] = line[i][j];
        }
    }

    int cnt_for_four = 0;
    int fork_cnt = 0;

    for (int i = 0; i < v.size(); i++)
    {
       
        for (int j = 0; j < v[i].size(); j++)
        {
            cnt_for_four=0;
            if (v[i][j] == '.')
                continue;
            if (checkUpperAdjecent(v, i, j))
                cnt_for_four++;
            if (checkLeftAdjecent(v, i, j))
                cnt_for_four++;
            if (checkRightAdjecent(v, i, j))
                cnt_for_four++;
            if (checkDownAdjecent(v, i, j))
                cnt_for_four++;
            if (checkLeftTopAdjecent(v, i, j))
                cnt_for_four++;
            if (checkRightTopAdjecent(v, i, j))
                cnt_for_four++;
            if (checkLeftDownAdjecent(v, i, j))
                cnt_for_four++;
            if (checkRightDownAdjecent(v, i, j))
                cnt_for_four++;

            if (cnt_for_four < 4)
                fork_cnt++;
        }
    }

    cout << fork_cnt << endl;

    return 0;
}