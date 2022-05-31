//
// Created by s2soo on 2022-05-31.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<ci> parent;

int knapsack(int n, int k) {
    vector<ci> cnt; //first: 아이들의 수, second: 사탕 개수
    for (int i = 1; i <= n; i++) { //아이들 수만큼 반복
        if (parent[i].first < 0) { //정점 노드 경우엔
            cnt.push_back({-parent[i].first, parent[i].second}); //해당 노드의 아이들 수와 사탕 정보 저장
        }
    }
    vector<int> dp(k, 0); //1부터 k-1까지
    for (int i = 0; i < cnt.size(); i++) { //정점 노드 수만큼 반복
        for (int j = k - 1; j >= cnt[i].first; j--) {
            dp[j] = max(dp[j], dp[j - cnt[i].first] + cnt[i].second); //최대한의 사탕을 가져옴
        }
    }
    return dp[k - 1];
}

//Find 연산
int findParent(int node) {
    if (parent[node].first < 0) { //정점 노드이므로
        return node; //반환
    }
    return parent[node].first = findParent(parent[node].first); //정점 노드 찾을 때까지 반복
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) { //x와 y가 같은 그룹이면
        return; //종료
    }
    if (parent[xp].first < parent[yp].first) { //xp가 새로운 루트일 경우
        parent[xp].first += parent[yp].first; //yp의 자식노드들 xp에 붙여줌
        parent[yp].first = xp; //xp가 yp의 루트 노드
        parent[xp].second += parent[yp].second; //yp의 다른 자식노드들(사탕개수)도 붙여주기
    } else { //yp가 새로운 루트일 경우
        parent[yp].first += parent[xp].first; //xp의 자식 노드들 yp에 붙여줌
        parent[xp].first = yp; //yp가 xp의 루트 노드
        parent[yp].second += parent[xp].second; //xp의 다른 자식노드들도 붙여주기
    }
}

/**
 * [할로윈의 양아치]
 *
 * - weighted union find -> 루트 정점에 아이들의 수(집합 원소 수)와 사탕 개수까지 pair 쌍으로 저장하기
 * - dp(냅색)으로 K명 미만의 아이들에게서 뺏을 수 있는 최대 사탕 수 구하기
 */

int main() {
    int n, m, k, a, b; //거리의 아이들 수, 아이들 친구 관계 수, 공명 위한 최소 아이 수, 친구 관계(a-b) 입력

    //입력
    cin >> n >> m >> k; //아이들 수, 친구 관계 수, 최소 아이 수 입력
    parent.assign(n + 1, {-1, 0}); //first: 아이들의 수, second: 사탕 개수
    for (int i = 1; i <= n; i++) { //아이들 수만큼 반복
        cin >> parent[i].second; //아이들이 받은 사탕 수 입력
    }
    while (m--) { //관계 수만큼 반복
        cin >> a >> b; //친구 관계 입력
        unionInput(a, b); //친구 관계 집합 생성
    }

    //연산 & 출력
    cout << knapsack(n, k); //최대 사탕의 수 출력
    return 0;
}