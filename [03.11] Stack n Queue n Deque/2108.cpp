//
// Created by s2soo on 2022-03-17.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    double sum = 0, size = n;
    int mid, mod, range, avg;

    // 산술평균
    for (int i=0; i<n; i++)
        sum += arr[i];
    avg = (int)round(sum/size);
    cout << avg << "\n";

    // 중앙값
    sort(arr.begin(), arr.end());
    int mid_index = (n-1) / 2;
    mid = arr[mid_index];
    cout << mid << "\n";

    // 최빈값
    map<int, int> m;
    m[arr[0]] = 1;
    for (int i=1; i<n; i++) {
        // 크기순 정렬 -> 중복 여부를 이렇게 확인
        if (arr[i] != arr[i-1]) {
            m[arr[i]] = 1;
        }
        else {
            m[arr[i-1]]++;
        }
    }

    mod = m[arr[0]];
    vector<int> mod_arr;
    for (int i=1; i<n; i++) {
        if (mod < m[arr[i]]) {
            mod = m[arr[i]];
        }
    }

    for (int i=0; i<n; i++) {
        if ( (mod == m[arr[i]]) && (find(mod_arr.begin(), mod_arr.end(), arr[i]) == mod_arr.end()) )
            mod_arr.push_back(arr[i]);
    }

    sort(mod_arr.begin(), mod_arr.end());

    if (mod_arr.size() == 1)
        cout << mod_arr[0] << "\n";
    else
        cout << mod_arr[1] << "\n";


    // 범위 = 최댓값 - 최솟값
    int max, min;
    max = arr[0], min = arr[0];

    for (int i=1; i<n; i++) {
        if (max < arr[i])
            max = arr[i];
        else if (min > arr[i])
            min = arr[i];
    }
    range = max - min;
    cout << range << "\n";


    return 0;
}
