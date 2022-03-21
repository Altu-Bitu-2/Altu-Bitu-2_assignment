//
// Created by s2soo on 2022-03-21.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string n;
    cin >> n;

    // 30의 배수 조건) 1. 끝의 자리수가 '0' 2. 각 자리수 합 == 3의 배수
    int sum = 0;
    bool last_zero = false;
    for (int i=0; i<n.length(); i++) {
        if (n[i] - '0' == 0)
            last_zero = true;
        sum += (n[i] - '0');
    }

    // 0이 없거나 각 자리 수의 합이 3의 배수가 아니면, 30의 배수 X
    if (!last_zero || sum % 3 != 0) {
        cout << -1 << "\n";
        return 0;
    }

    // 가장 큰 30의 배수: 내림차순으로 정렬
    sort(n.begin(), n.end(), greater<>());
    for (int i=0; i<n.length(); i++) {
        cout << n[i];
    }
    cout << "\n";

    return 0;

}
