//
// Created by s2soo on 2022-05-01.
//

#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int> &house) {
    //윈도우 초기화
    int money = 0; // 돈 초기화
    for (int i = 0; i < m; i++) { // 집의 개수만큼 반복
        money += house[i]; // 각 집의 돈을 더함
    }
    int ans = money < k; //훔쳐야 하는 집 초기화

    if (n == m) { //훔칠 수 있는 경우 딱 1개인 경우
        return ans; // 값 반환
    }
    for (int i = m; i < n + m - 1; i++) { // 슬라이딩 윈도우
        money -= house[i - m]; // 원형 배열 -> (i-m)번째 집의 돈 빼기
        money += house[i % n]; // 원형 배열이므로 모듈러 연산 -> 순서대로 돈 더하기
        if (money < k) { // 방법 장치가 작동하지 않는다면
            ans++; // 방법의 수 증가
        }
    }
    return ans; // 정답 반환
}

/**
 * [도둑]
 *
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 *    => 예를 들어, n = m = 3, k = 4, house = [1, 1, 1] 일 때, 실제 방법의 수는 1번, 2번, 3번 집을 택하는 경우밖에 없지만
 *       예외 처리를 안해줄 경우, 원형으로 돌며 3을 출력하게 됨!
 */

int main() {
    int t, n, m, k;

    cin >> t;
    while (t--) {
        //입력
        cin >> n >> m >> k;
        vector<int> house(n, 0); // 집을 저장할 배열
        for (int i = 0; i < n; i++) {
            cin >> house[i]; // 각 집에서 보관 중인 돈의 양 입력
        }

        //연산 & 출력
        cout << steal(n, m, k, house) << '\n';
    }
    return 0;
}