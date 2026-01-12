#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{

    ifstream file("d5p2.txt");

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    set<long long> valid_ids;

    vector<string> id_ranges;
    vector<pair<long long, long long>> ranges;
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
            long long start = stoll(str.substr(0, str.find('-')));
            long long end = stoll(str.substr(str.find('-') + 1));
            ranges.push_back({start, end});
        }
    }
    sort(ranges.begin(), ranges.end());

    long long total_fresh_ingredients = 0;
    long long current_start = ranges[0].first;
    long long current_end = ranges[0].second;
    for(int i=1;i<ranges.size();i++){
        if(ranges[i].first <= current_end + 1){
            current_end = max(current_end,ranges[i].second);

        }else{
            total_fresh_ingredients += (current_end - current_start + 1);
            current_start = ranges[i].first;
            current_end = ranges[i].second;
        }
    }

    total_fresh_ingredients += (current_end - current_start + 1);
    cout << "Total fresh ingredients: " << (total_fresh_ingredients) << endl;
    return 0;
}
