//
// Created by s2soo on 2022-04-15.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int> &tree) {
    ll sum = 0; // 초기화를 0으로
    for (int i = 0; i < tree.size(); i++) { // 나무의 수만큼 반복
        if (height >= tree[i]) { // 나무가 height 값보다 높이가 낮아 더이상 자를 수 없으므로
            return sum; // 합을 반환
        }
        sum += (tree[i] - height); // 나무 높이에서 height 값을 자른 나머지 부분을 더함
    }
    return sum; // 합 반환
}

int upperSearch(int left, int right, int target, vector<int> &tree) {
    while (left <= right) { // 최소 높이가 최대를 넘지 않는 동안
        int mid = (left + right) / 2; // 최소와 최대의 평균
        ll tree_cnt = cntTree(mid, tree); // 합을 구함

        if (tree_cnt >= target) { // 합이 원하던 값보다 크거나 같으면
            left = mid + 1; // 최소값은 평균 + 1
        } else { // 합이 원하던 값보다 작으면
            right = mid - 1; // 최대값은 평균 - 1
        }
    }
    return left - 1; // 최소값 - 1 반환
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> tree(n, 0); // 나무의 높이 저장
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end(), greater<>()); // 나무를 노이를 기준으로 내림차순으로 정렬

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree);
    return 0;
}