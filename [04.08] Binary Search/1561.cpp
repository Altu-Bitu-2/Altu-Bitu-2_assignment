//
// Created by s2soo on 2022-04-15.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll finalChildren(ll t, vector<int> &rides) {
    ll child = 0; // 초기화를 0으로
    for (int i = 1; i < rides.size(); i++) { // 놀이기구의 종류수만큼 반복
        child += (t / rides[i] + 1); // 놀이기구를 타는 마지막 아이의 번호를 구함
    }
    return child; // 구한 아이 번호 반환
}

ll lowerSearch(ll left, ll right, ll target, vector<int> &rides) {
    while (left <= right) { // 놀이기구 타는 최소 시간이 최대 시간을 넘지 않는 동안
        ll mid = (left + right) / 2; // 중간 시간 = 최소 시간과 최대 시간의 평균
        ll child = finalChildren(mid, rides); // 마지막 아이를 찾아서 저장

        if (child >= target) { //줄의 마지막 아이보다 더 뒤에 있는 아이라면
            right = mid - 1; // 최대 시간은 평균 - 1
        } else { // 줄의 마지막 아이보다 앞에 있는 아이라면
            left = mid + 1;  // 최소 시간은 평균 + 1
        }
    }
    return left; // 최소 시간 반환
}

int findRides(int n, int m, vector<int> &rides) {
    ll t = lowerSearch(0, (ll) rides[1] * n, n, rides); // 최소 시간 구함
    ll child = finalChildren(t, rides); // 마지막 아이 구함
    for (int i = m; i >= 1; i--) {
        if (t % rides[i] == 0) { //아이가 탐
            if (child-- == n) { // 아이의 번호가 n번, 즉 마지막 아이라면
                return i; // 그 놀이기구 번호를 반환
            }
        }
    }
}

/**
 * [놀이 공원]
 *
 * n번째 아이가 놀이기구를 타는 시간을 구한 후, 해당 시간에 놀이기구를 타는 아이들을 모두 검사하며 n번째 아이가 타는 놀이기구의 번호를 구한다!
 *
 * 1. n번째 아이가 놀이기구를 타는 시간이 언제인지 parametric search 통해 구함
 *    - 이때, 각 시간 별 놀이기구 타는 아이의 마지막 번호 구하는 공식은 다음과 같음
 *      f(t) = (모든 i(놀이 기구)에 대해서) t/num[i] + n(시간 0일때 놀이기구 타는 아이 수)
 *
 *    - left: 놀이기구 타는 시간의 최소 = 0
 *    - right: 놀이기구 타는 시간의 최대 = 1번 놀이기구 운행 시간 x n (타이트하게 잡으면 최소 운행 시간 x n 이지만 편의상 이렇게 설정)
 *
 *    - n번째 아이가 놀이기구를 타는 첫 시간을 구해야 하므로 lower bound
 *
 * 2. n번째 아이가 놀이기구를 타는 시간을 구했다면, 그 시간에 마지막으로 놀이기구를 타는 아이부터 시작해서
 *    놀이기구를 m부터 탐색하면서 n번째 아이가 몇 번 놀이기구 타는지 구하면 됨!
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> rides(m + 1, 0); // 놀이기구별 운행시간 저장
    for (int i = 1; i <= m; i++) {
        cin >> rides[i];
    }

    if (n <= m) { //아이의 수가 놀이기구 수보다 적다면
        cout << n; // 마지막 아이의 번호 출력
        return 0;
    }

    //연산 & 출력
    cout << findRides(n, m, rides);
    return 0;
}