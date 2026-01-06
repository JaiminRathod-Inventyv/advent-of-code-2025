#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> parseCSVLine(string &line)
{
    vector<string> result;
    stringstream ss(line);
    string item;

    while (getline(ss, item, ','))
    {
        result.push_back(item);
    }
    return result;
}

int main()
{
    vector<string> v;
    ifstream file("d2p2.txt");
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }
    string range;
    while (getline(file, range))
    {
        vector<string> parsedLine = parseCSVLine(range);
        for (const string &str : parsedLine)
        {
            v.push_back(str);
        }
    }
    // for(int i=0;i<v.size();i++){
    //     cout << v[i] << endl;
    // }
    long long inValidIds = 0;
    for (int i = 0; i < v.size(); i++)
    {
        string str = v[i];
        long long firstPart = stoll(str.substr(0, str.find('-')));
        long long secondPart = stoll(str.substr(str.find('-') + 1));
        // cout << firstPart << " " << secondPart << endl;
        for (long long j = firstPart; j <= secondPart; j++)
        {
            string numStr = to_string(j);
            // if starts with leading zero than also it is invalid
            if (numStr[0] == '0')
            {
                // cout << j << " ";
                inValidIds += j;
                continue;
            }
            string half_str = numStr.substr(0, numStr.length() / 2);
            for (int k = 1; k <= half_str.length(); k++)
            {
                if (numStr.length() % k == 0)
                {
                    string sub_str = numStr.substr(0, k);
                    int size = numStr.length() / k;
                    string gen_str = "";
                    for (int l = 0; l < size; l++)
                    {
                        gen_str += sub_str;
                    }
                    if (gen_str == numStr)
                    {
                        inValidIds += j;
                        break;
                    }
                }
            }
        }
            // cout << inValidIds << endl;
        }
        cout << inValidIds << endl;

        return 0;
    }