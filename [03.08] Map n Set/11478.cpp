//
// Created by s2soo on 2022-03-14.
//

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    string str;
    unordered_set<string> set;

    cin >> str;

    string s;
    for (int i=0; i<str.length(); i++) {
        s = "";
        for (int j=i; j<str.length(); j++) {
            s += str[j];
            set.insert(s);
        }
    }

    cout << set.size();


    return 0;
}