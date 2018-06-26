#include<map>
#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::string;
using std::map;
using std::vector;
using std::endl;
void GetInput(map<string, vector<double>> &inputMap, std::istream &in)
{
    string name;
    double value;
    while(in >> name && in >> value)
    {        
        inputMap[name].push_back(value);        
    }
}

int main()
{
    map<string, vector<double>> inputMap;
    GetInput(inputMap, cin);
    double allSum = 0;
    int allCount = 0;
    for(map<string, vector<double>>::iterator it = inputMap.begin(); it != inputMap.end(); it++)
    {
        double sum = 0;
        for(double d : it->second)
        {
            sum += d;
        }
        allSum += sum;
        allCount += it->second.size();
        double avg= sum / (it->second.size());
        cout << it->first << " sum:" << sum << " avg:" << avg << endl;
    }
    double allAvg = allSum / allCount;
    cout << "all sum is " << allSum << " all avg is " << allAvg << endl;
    return 0;
}

