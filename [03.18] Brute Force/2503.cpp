//
// Created by s2soo on 2022-03-24.
//

#include <iostream>
#include <vector>

using namespace std;

struct baseball {
    int num;
    int strike;
    int ball;
};

int main() {
    int n;
    cin >> n;

    vector<baseball> v;
    for (int i=0; i<n; i++) {
        baseball input;
        cin >> input.num >> input.strike >> input.ball;
        v.push_back(input);
    }

    // 브루트 포스
    vector<bool> flag(1000, true);
    int num_strike, num_ball;
    int n1, n2, n3, ex, ex1, ex2, ex3; // 백의자리, 십의자리, 일의자리 수
    for (int i=123; i<=987; i++) {
        n1 = i / 100;
        n2 = (i/10) % 10;
        n3 = i % 10;

        // 0이 들어가거나 숫자 겹치면 pass
        if (n1 == 0 || n2 == 0 || n3 == 0 || n1 == n2 || n2 == n3 || n1 == n3) {
            flag[i] = false;
            continue;
        }

        // 주어진 입력들 확인
        for (int j=0; j<n; j++) {
            ex = v[j].num;
            ex1 = ex / 100;
            ex2 = (ex/10) % 10;
            ex3 = ex % 10;

            num_strike = 0, num_ball = 0;
            // 스트라이크
            if (ex1 == n1)
                num_strike++;
            if (ex2 == n2)
                num_strike++;
            if (ex3 == n3)
                num_strike++;

            // 볼
            if (ex1 == n2 || ex1 == n3)
                num_ball++;
            if (ex2 == n1 || ex2 == n3)
                num_ball++;
            if (ex3 == n1 || ex3 == n2)
                num_ball++;

            // 비교
            if (num_strike != v[j].strike || num_ball != v[j].ball)
                flag[i] = false;
        }
    }

    int sum = 0;
    for (int i=123; i<=987; i++) {
        if (flag[i] == true)
            sum++;
    }
    cout << sum;

    return 0;
}