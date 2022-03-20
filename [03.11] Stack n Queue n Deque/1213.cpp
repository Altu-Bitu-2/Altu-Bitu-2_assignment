//
// Created by s2soo on 2022-03-17.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    int alpha[26] = {0, };
    int len = input.length();
    for (int i=0; i<len; i++)
        alpha[input[i] - 'A'] += 1;

    int num_of_odd = 0, index_of_odd;
    for (int i=0; i<26; i++) {
        if (alpha[i] % 2 == 1) {
            num_of_odd++;
            index_of_odd = i;
            alpha[i]--;
        }
    }

    // 홀수 개인 알파벳이 두 개 이상이면 팰린드롬 불가능
    if (num_of_odd > 1) {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }

    string result = "", result_reverse = "";
    // 문자열 길이가 짝수 -> 모든 알파벳이 짝수 개
    if (len % 2 == 0) {
        // 일단 개수를 반으로 줄여줌
        for (int i=0; i<26; i++) {
            alpha[i] /= 2;
        }

        for (int i=0; i<26; i++) {
            while (alpha[i] > 0) {
                result += (i + 'A');
                alpha[i]--;
            }
        }

        result_reverse = result;
        reverse(result_reverse.begin(), result_reverse.end());
        result += result_reverse;
        cout << result << "\n";
        return 0;
    }
    // 문자열 길이가 홀수 -> 한 알파벳만 홀수 개
    else {
        for (int i=0; i<26; i++) {
            alpha[i] /= 2;
        }

        for (int i=0; i<26; i++) {
            while (alpha[i] > 0) {
                result += (i + 'A');
                alpha[i]--;
            }
        }

        result_reverse = result;
        reverse(result_reverse.begin(), result_reverse.end());
        result += index_of_odd + 'A';
        result += result_reverse;
        cout << result << "\n";
        return 0;
    }

}