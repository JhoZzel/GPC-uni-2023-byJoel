#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main()
{
    vector<int> arr;
    string input;
    getline(cin, input);
    istringstream is(input);
    int num;
    while(is>>num) arr.push_back(num);
}