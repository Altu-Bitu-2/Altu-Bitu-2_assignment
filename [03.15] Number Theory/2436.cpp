//
// Created by s2soo on 2022-03-21.
//

#include <iostream>

using namespace std;

// 유클리드 호제법
long long gcdRecursion(long long a, long long b) {
    if (b == 0)
        return a;
    return gcdRecursion(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 범위: 2 <= gcd, lcm <= 100,000,000
    // int로 변수 선언하면 틀림
    // long long으로 선언해줘야
    long long gcd, lcm;
    cin >> gcd >> lcm;

    // mul = gcd * lcm = A * B (gcd & lcm by A, B)
    // i: lcm의 배수 & mul의 약수
    // (i, mul/i)의 최대공약수 == gcd -> 정답 쌍
    // 합이 더 작은 쌍이 나오면 갱신
    long long mul = gcd * lcm;

    // lcm의 배수 & mul의 약수 찾기
    long long temp, ans1 = gcd, ans2 = lcm;
    for (long long i=2*gcd; i*i<=mul; i+=gcd) { // for문 조건: lcm의 배수
        // mul의 약수
        if (mul % i == 0) {
            temp = mul / i;

            // 최대공약수가 gcd && 합이 더 작음 -> 갱신
            if (gcdRecursion(i, temp) == gcd) {
                if (ans1+ans2 > i+temp) {
                    ans1 = i;
                    ans2 = temp;
                }
            }
        }
    }

    cout << ans1 << " " << ans2 << "\n";
    return 0;
}