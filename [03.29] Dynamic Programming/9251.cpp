//
// Created by s2soo on 2022-04-04.
//

#include <iostream>
#include <vector>
using namespace std;

int LCS(string &s1, string &s2) {

    int len1 = s1.length();
    int len2 = s2.length();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            // 두 문자가 같으면, 이전의 결과값에 1을 더해줌
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // 두 문자가 같지 않으면, 이전의 결과 중 더 길이가 긴 것을 선택
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // 배열 마지막에 저장된 값이 최종 결과
    return dp[len1][len2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    string s1, s2;
    cin >> s1 >> s2;

    cout << LCS(s1, s2);

    return 0;
}