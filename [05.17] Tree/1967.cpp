//
// Created by s2soo on 2022-05-24.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>> &graph) {
    int pos = node, len = 0; //지름을 구성하는 노드 중 하나, 그 노드까지의 거리
    for (int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i].first; //지름을 구성하는 노드 기준으로 연결된 다른 노트 탐색
        if (next_node == parent) { //다음 노드가 부모 노드면
            continue; //pass
        }

        ci dfs_search = dfs(next_node, node, graph); //자식 노드에 대해 dfs 탐색
        if (graph[node][i].second + dfs_search.second > len) { //기존 거리보다 길다면 갱신
            len = graph[node][i].second + dfs_search.second; //거리 갱신
            pos = dfs_search.first; //지름을 구성하는 노드 갱신
        }
    }
    return {pos, len}; //지름을 구성하는 노드와 지름 반환
}

/**
 * [트리의 지름]
 *
 * 1. 지름을 이루는 두 점은 모두 리프 노드
 * 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 * 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드
 *
 * 부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
 */

int main() {
    int n, p, c, w;

    //입력
    cin >> n; //n: 노드의 개수
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //그래프 선언 및 초기화
    for (int i = 1; i < n; i++) { //무방향 그래프로 만들기
        //간선에 대한 정보
        cin >> p >> c >> w; //p: 부모 노드의 번호, c: 자식 노드의 번호, w: 간선의 가중치
        graph[p].push_back({c, w}); //그래프 정보 저장(부모 노드 기준)
        graph[c].push_back({p, w}); //그래프 정보 저장(자식 노드 기준)
    }

    //연산
    ci first_node = dfs(1, -1, graph); //지름을 구성하는 노드 하나 찾기
    ci second_node = dfs(first_node.first, -1, graph); //지름을 구성하는 다른 노드 찾기

    //출력
    cout << second_node.second;
    return 0;
}