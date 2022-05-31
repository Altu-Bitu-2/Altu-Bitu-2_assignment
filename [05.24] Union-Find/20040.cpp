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
        return node; //반환
    }
    return parent[node] = findParent(parent[node]); //정점 노드 찾을 때까지 반복
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) { //x, y가 같은 그룹이면
        return false; //false 리턴
    }
    if (parent[xp] < parent[yp]) { //xp가 새로운 루트이면
        parent[xp] += parent[yp]; //yp의 자식 노드들을 붙여준 후
        parent[yp] = xp; //xp가 yp의 루트가 됨
    } else { //yp가 새로운 루트이면
        parent[yp] += parent[xp]; //xp 자식 노드 붙여준 후
        parent[xp] = yp; //yp가 xp의 루트가 됨
    }
    return true; //true 리턴
}

/**
 * [사이클 게임]
 *
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */

int main() {
    int n, m, x, y;

    //입력
    cin >> n >> m;
    parent.assign(n, -1); //-1로 초기화
    for (int i = 0; i < m; i++) {
        cin >> x >> y; //입력

        //연산 & 출력
        if (!unionInput(x, y)) { //사이클이 생성됨
            cout << i + 1; //값 출력
            return 0;
        }
    }
    cout << 0;
    return 0;
}