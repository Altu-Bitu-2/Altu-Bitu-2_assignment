//
// Created by s2soo on 2022-04-04.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(11);

int getNum(int n) {
    // Top-down 방식
    if (n == 1)
        return dp[1];
    if (n == 2)
        return dp[2];
    if (n == 3)
        return dp[3];

    return getNum(n-1) + getNum(n-2) + getNum(n-3);
}

int main() {
    // 입력
    int tc;
    cin >> tc;

    int n;

    dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 4;
    while (tc--) {
        cin >> n;
        cout << getNum(n) << "\n";
    }
    return 0;
}