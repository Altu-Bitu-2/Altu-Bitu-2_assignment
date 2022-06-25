//
// Created by s2soo on 2022-05-31.
//

#include <iostream>

using namespace std;

string solution(int x, int n) {
    if (n > 1 && n % 2 == 1) { //단항 부정 연산자가 사용된 경우 컴파일 실패
        return "ERROR"; //"ERROR" 출력
    }
    if (n == 1 && x < 0) { //화살표의 길이가 1이므로 0>x인데, x가 음수이므로 항상 참임
        return "INFINITE"; //무한루프
    }
    //x의 초기값이 음수 혹은 0인 경우와
    //화살표의 길이가 1인데(즉, >) x가 양수인 경우는
    //while문에 들어갈 수 없으므로 아무것도 출력되지 않음
    if (n == 1 || x <= 0) {
        return "0"; //출력되지 않음
    }
    if (n == 0) { //x가 양수이므로 항상 참이므로 무한루프
        return "INFINITE"; //무한히 많은 수 출력
    }
    //위의 경우에 해당되지 않는다면 x의 값을 하나씩 줄이면서 해당 과정 반복
    return to_string((x - 1) / (n / 2));
}

/**
 * [화살표 연산자]
 *
 * 1. n이 1보다 큰 홀수인 경우 -> ERROR
 * 2. n이 1인데 x가 음수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 3. n이 1인데 x가 양수인 경우 or x가 0보다 작거나 같은 경우 -> while문에 진입 못함 -> 0
 * 4. n이 0인데 x가 양수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 5. 나머지 경우엔 (x - 1)을 (n / 2)로 나눈 몫을 출력
 *    - 연산했을 때 1 이상이 남을 때까지만 출력을 할 수 있으므로 1을 뺀 값에서 몫을 구함
 */

int main() {
    int x, n;

    //입력
    cin >> x >> n;

    //연산 & 출력
    cout << solution(x, n);
    return 0;
}