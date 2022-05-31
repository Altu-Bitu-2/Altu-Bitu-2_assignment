//
// Created by s2soo on 2022-05-31.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { //정점 노드이므로
        return node; //노드 반환
    }
    return parent[node] = findParent(parent[node]); //정점 노드 찾을 때까지 반복
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) { //x, y가 같은 그룹이면
        return; //종료
    }
    if (parent[xp] < parent[yp]) { //xp가 새로운 루트일 경우
        parent[xp] += parent[yp]; //yp의 자식 노드들 xp에 붙여줌
        parent[yp] = xp; //xp가 yp의 루트가 됨
    } else { //yp가 새로운 루트일 경우
        parent[yp] += parent[xp]; //xp의 자식 노드들 yp에 붙여줌
        parent[xp] = yp; //yp가 xp의 루트가 됨
    }
}

int liarParty(vector<int> &parties) {
    int cnt = 0; //개수 초기화
    for (int i = 0; i < parties.size(); i++) { //파티의 크기만큼 반복
        if (findParent(parties[i]) != findParent(0)) { //지민이가 거짓말에 성공할 경우
            cnt++; //개수 증가
        }
    }
    return cnt; //개수 반환
}

/**
 * [거짓말]
 *
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 * -> 이때, 진실을 아는 사람들의 루트 정점을 0으로 설정해서 유니온 파인드를 통해 집합으로 묶고 시작
 * -> 0과 같은 집합이 아니어야 거짓말을 할 수 있음
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m; //사람의 수, 파티의 수 입력
    parent.assign(n + 1, -1); //-1로 초기화

    int init, p;
    cin >> init; //진실 아는 사람 수 입력
    while (init--) { //진실을 아는 사람들
        cin >> p; //번호 입력
        unionInput(0, p); //진실을 아는 사람들의 집합 생성
    }

    int cnt, first_person, person; //각 파티마다 오는 사람의 수와 번호
    vector<int> parties; //파티 배열
    while (m--) { //파티의 수만큼 반복
        cin >> cnt >> first_person; //각 파티에 오는 사람의 수와 번호 입력

        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        while (--cnt) { //각 파티에 오는 사람의 수만큼 반복
            cin >> person; //파티에 오는 사람 입력
            unionInput(first_person, person); //각 파티마다 집합 생성
        }
    }

    //연산 & 출력
    cout << liarParty(parties); //답 출력
    return 0;
}