//
// Created by s2soo on 2022-05-24.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int &erase_node) {
    if (node == erase_node) { //주어진 정점이 지울 노드라면
        return 0; //리프 노트 없음
    }
    //자식 노드가 없거나, 자식 노드가 하나 있고 그 자식 노드가 지울 노드라면
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
        return 1; //리프 노드 1개
    }
    int cnt = 0; //개수 초기화
    for (int i = 0; i < tree[node].size(); i++) { //노드 개수만큼 반복
        cnt += eraseLeafCnt(tree[node][i], erase_node); //노드의 자식 노드를 돌면서 리프 노드 개수 확인
    }
    return cnt; // 개수 반환
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() {
    int n, par, root, erase_node;

    //입력
    cin >> n; //n: 노드의 개수
    tree.assign(n, vector<int>(0)); //트리 초기화
    for (int i = 0; i < n; i++) {
        cin >> par; //각 노드의 부모
        if (par == -1) { //부모 없으면
            root = i;//루트가 부모
            continue;
        }
        tree[par].push_back(i); //부모노드에 대한 자식노드 생성
    }
    cin >> erase_node; //지울 노드의 번호

    //연산 & 출력
    cout << eraseLeafCnt(root, erase_node);
    return 0;
}