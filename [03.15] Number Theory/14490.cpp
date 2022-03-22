//
// Created by s2soo on 2022-03-21.
//

#include <iostream>
#include <string>

using namespace std;

// 유클리드 호제법
int gcdRecursion(int a, int b) {
    if (b == 0)
        return a;
    return gcdRecursion(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;

    string str_n = "", str_m = "";
    int index;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ':') {
            index = i;
            break;
        }
        str_n += s[i];
    }
    str_m = s.substr(index+1, s.size());

    int n = stoi(str_n);
    int m = stoi(str_m);

    // 최대공약수 구하기
    int gcd = gcdRecursion(max(n, m), min(n, m));
    // 약분
    n /= gcd;
    m /= gcd;

    cout << n << ":" << m << "\n";

    return 0;
}