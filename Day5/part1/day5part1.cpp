#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    ifstream file("d5p1.txt");

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    vector<string> id_ranges;
    vector<long long> ids;
    string str;
    bool newline_found = false;
    while (getline(file, str))
    {
        if (str.empty())
        {
            newline_found = true;
            continue;
        }
        if (!newline_found)
        {
            id_ranges.push_back(str);
        }
        else
        {
            ids.push_back(stoll(str));
        }
    }

    // for(int i=0;i<id_ranges.size();i++){
    //     cout << id_ranges[i] << endl;
    // }

    int fresh_ingredients_count = 0;
    vector<pair<long long , long long>> nums_of_ranges;
    for (int i = 0; i < id_ranges.size(); i++)
    {
        string range = id_ranges[i];
        long long start = stoll(range.substr(0, range.find('-')));
        long long end = stoll(range.substr(range.find('-') + 1));
        nums_of_ranges.push_back({start,end});
    }


    for (int i = 0; i < ids.size(); i++)
    {
        for(int j=0;j<nums_of_ranges.size();j++){
            if(ids[i]>=nums_of_ranges[j].first && ids[i]<=nums_of_ranges[j].second){
                fresh_ingredients_count++;
                break;
            }
        }
    }

    cout << fresh_ingredients_count;

    return 0;
}
