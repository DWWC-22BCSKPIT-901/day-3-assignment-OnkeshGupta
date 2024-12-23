#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string makeLargestSpecial(string s) {
    vector<string> subs;
    int count = 0, start = 0;

    for (int i = 0; i < s.size(); ++i) {
        count += (s[i] == '1') ? 1 : -1;

        if (count == 0) {
            string special = "1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0";
            subs.push_back(special);
            start = i + 1;
        }
    }

    sort(subs.rbegin(), subs.rend());

    string result;
    for (const string& sub : subs) {
        result += sub;
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    cout << makeLargestSpecial(s) << endl;

    return 0;
}