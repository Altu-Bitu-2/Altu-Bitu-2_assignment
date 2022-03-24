//
// Created by s2soo on 2022-03-24.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// unsigned long long 형으로 변수 선언해도 틀림

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a,b;
    cin >> a >> b;

    int len_a = a.length();
    int len_b = b.length();

    vector<int> vec_a, vec_b, carry, result;
    // 자리수 맞추기
    if (len_a > len_b) {
        for (int i=0; i<len_a-len_b; i++)
            vec_b.push_back(0);
    }
    else {
        for (int i=0; i<len_b-len_a; i++)
            vec_a.push_back(0);
    }

    int tmp;
    for (int i=0; i<len_a; i++) {
        tmp = a[i] - '0'; // 문자 -> 정수
        vec_a.push_back(tmp);
    }
    for (int i=0; i<len_b; i++) {
        tmp = b[i] - '0';
        vec_b.push_back(tmp);
    }

    int len = max(len_a, len_b);
    carry.assign(len+1, 0);
    result.assign(len+1, 0);

    // 1의 자리 수부터 덧셈
    int sum = 0, res;
    for (int i=len-1; i>=0; i--) {
        sum = vec_a[i] + vec_b[i];
        if (sum >= 10) {
            carry[i]++;
            sum = sum % 10;
        }

        // carry값 더하면서 다시 10 넘을 수 있으니 한 번 더 확인
        res = sum + carry[i+1];
        if (res >= 10) {
            carry[i]++;
            res = res % 10;
        }

        result[i+1] = res;
    }

    if (carry[0])
        result[0] = 1;

    if (result[0]) {
        for (int i=0; i<len+1; i++)
            cout << result[i];
    }
    else {
        for (int i=1; i<len+1; i++)
            cout << result[i];
    }


}