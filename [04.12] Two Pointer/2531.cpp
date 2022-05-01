//
// Created by s2soo on 2022-05-01.
//

#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(int n, int d, int k, int c, vector<int> &belt) {
    vector<int> sushi(d + 1, 0); //초밥 먹은 개수

    //쿠폰으로 먹은 초밥
    int section_sushi = 1; // 초기화
    sushi[c]++; // 먹은 개수 증가

    //윈도우 초기화
    for (int i = 0; i < k; i++) {
        if (!sushi[belt[i]]) { // 쿠폰으로 먹은 초밥이 아니라면
            section_sushi++; // 초밥 개수 증가
        }
        sushi[belt[i]]++; // 종류별 초밥 개수 count
    }

    int ans = section_sushi; // 초기화
    for (int i = k; i < n + k; i++) { //슬라이딩 윈도우
        sushi[belt[i - k]]--; // 개수 하나 줄여서 시작
        if (!sushi[belt[i - k]]) { // 해당 종류의 초밥이 없다면
            section_sushi--; // 개수 감소
        }
        if (!sushi[belt[i % n]]) { // 원 형태이므로 모듈러 연산, 초밥 다 먹었으면
            section_sushi++; // 개수 증가
        }
        sushi[belt[i % n]]++; // 먹은 개수 증가
        ans = max(ans, section_sushi); // 큰 값 선택
    }
    return ans; // 값 반환
}

/**
 * [회전 초밥]
 *
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥의 개수를 세어주기
 */

int main() {
    int n, d, k, c;

    //입력
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0); // 초밥 종류 저장
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    //연산 & 출력
    cout << chooseSushi(n, d, k, c, belt);
    return 0;
}