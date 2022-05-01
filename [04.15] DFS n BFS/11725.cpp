//
// Created by s2soo on 2022-05-01.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list; // 인접 노드
vector<int> parent; // 부모 노드

void dfs_recursion(int prev, int curr) {
    if (parent[curr]) { // 루트에 도달했다면
        return; // 종료
    }
    parent[curr] = prev; // 현재 노드의 부모 노드를 이전 노드로 설정
    for (int i = 0; i < adj_list[curr].size(); i++) { // 형제 노드의 개수만큼 반복
        dfs_recursion(curr, adj_list[curr][i]); // dfs 수행
    }
}

/**
 * [트리의 부모 찾기]
 *
 * 1번 노드에서 출발해서 탐색
 * 루트 노드에서 출발 했기 때문에, 현재 노드의 부모는 이전 노드가 된다.
 */

int main() {
    int n, a, b;

    //입력
    cin >> n;
    adj_list.assign(n + 1, vector<int>(0)); // 초기화
    parent.assign(n + 1, 0); // 초기화
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj_list[a].push_back(b); // a의 형제 노드는 b
        adj_list[b].push_back(a); // b의 형제 노드는 a
    }

    //연산
    dfs_recursion(1, 1); //1번 노드는 루트노드이므로, 부모를 자기 자신으로 설정

    //출력
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n'; // 부모 노드 출력
    }
    return 0;
}