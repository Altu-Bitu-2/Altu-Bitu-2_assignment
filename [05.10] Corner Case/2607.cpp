//
// Created by s2soo on 2022-05-17.
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;

//알파벳별 등장횟수 저장
vector<int> alphaMap(string str) {
    vector<int> result(SIZE, 0); // 저장할 벡터(배열) 선언
    for (int i = 0; i < str.size(); i++) { // 입력받은 단어의 글자수만큼 반복
        result[str[i] - 'A']++; // 등장횟수 저장
    }
    return result; // 벡터 반환
}

/**
 * [비슷한 단어]
 *
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */

int main() {
    int n, ans = 0;
    string source, target; // 기준 단어(첫 번째 단어), 비교 단어

    //입력
    cin >> n >> source; // 단어 개수랑 기준 단어 입력

    //연산
    vector<int> source_alpha = alphaMap(source); // 기준 단어의 알파벳별 등장횟수 저장
    while (--n) { // (n-1)번 반복
        cin >> target; // 비교 단어 입력

        int diff = 0; // 두 단어의 차이, 초기화
        vector<int> target_alpha = alphaMap(target); // 비교 단어의 알파벳별 등장횟수 저장
        for (int i = 0; i < SIZE; i++) { //두 단어의 차이
            diff += abs(source_alpha[i] - target_alpha[i]); // 등장횟수를 이용해 두 단어의 차이 계산
        }
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) { //문자를 더하거나, 빼거나, 바꾸거나
            ans++; // 기준을 만족하면 비슷한 단어이므로 ans 증가
        }
    }

    //출력
    cout << ans;
    return 0;
}