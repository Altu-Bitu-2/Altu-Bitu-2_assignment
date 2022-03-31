//
// Created by s2soo on 2022-03-28.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int n;
    cin >> n;

    int result = 0;
    string word;
    bool flag;
    for (int i=0; i<n; i++) {
        cin >> word;

        // 초기화
        int alpha[26] = {0, };
        flag = false;

        // 알파벳 count
        alpha[word[0]-'a'] += 1;
        for (int j=1; j<word.length(); j++) {
            if (word[j] == word[j-1])
                continue;
            alpha[word[j]-'a']++;
        }

        for (int j=0; j<26; j++) {
            if (alpha[j] > 1) {
                flag = true;
                break;
            }
        }

        if (!flag)
            result++;
    }

    cout << result;

    return 0;
}