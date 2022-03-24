//
// Created by s2soo on 2022-03-24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> v;

void dfs(int n, string s, int vowel, int consonant) {

    if (s.size() == L) {

        if (vowel >= 1 && consonant >= 2) {
            cout << s << "\n";
        }
        return;

    }

    for (int i = n; i < C; i++) {
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
            dfs(i + 1, s + v[i], vowel + 1, consonant);
        else
            dfs(i + 1, s + v[i], vowel, consonant + 1);
    }

}

int main() {

    cin >> L >> C;

    char c;
    for (int i = 0; i < C; i++) {
        cin >> c;
        v.push_back(c);
    }

    sort(v.begin(), v.end());

    dfs(0, "", 0, 0);

}