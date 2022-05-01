//
// Created by s2soo on 2022-05-01.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx) {
    while (left < right) { // left와 right 포인터의 위치가 겹치기 전까지
        if (left == idx) { // left와 idx가 같으면
            left++; // left 오른쪽으로 한 칸 이동
            continue; // pass
        }
        if (right == idx) { // right와 idx가 같으면
            right--; // right 왼쪽으로 한 칸 이동
            continue; // pass
        }

        if (num[left] + num[right] == num[idx]) { // 각 포인터가 가리키는 값의 합이 입력받은 다른 수와 같으면
            return true; // 좋은 수임
        }
        if (num[left] + num[right] > num[idx]) { // 각 포인터가 가리키는 값의 합이 더 크면
            right--; // right를 왼쪽으로 한 칸 이동 (= 더 작은 수로)
        } else { // 각 포인터가 가리키는 값의 합이 더 작으면
            left++; // left를 오른쪽으로 한 칸 이동 (= 더 큰 수로)
        }
    }
    return false; // 합을 이루지 못하면 좋은 수가 아니므로 false 반환
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {
    int n, ans = 0;

    //입력
    cin >> n;
    vector<int> num(n, 0); // 입력 받을 수 저장
    for (int i = 0; i < n; i++) {
        cin >> num[i]; // 수 입력
    }

    //연산
    sort(num.begin(), num.end()); // 입력 받은 수 정렬
    for (int i = 0; i < n; i++) {
        if (isGood(num, 0, n - 1, i)) { // 좋은 수이면
            ans++; // 좋은 수 개수 증가
        }
    }

    //출력
    cout << ans;
    return 0;
}