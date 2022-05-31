//
// Created by s2soo on 2022-05-24.
//

#include <iostream>

using namespace std;

struct node_info {
    int data; //키
    node_info *left; //왼쪽 노드
    node_info *right; //오른쪽 노드
};

node_info *makeTree(node_info *node, int data) {
    if (node == NULL) { //이번 노드가 들어가게될 위치
        node = new node_info(); //동적 할당
        node->data = data; //키 입력
        node->left = node->right = NULL; //왼쪽, 오른쪽 노드 초기화
    } else if (node->data > data) { //키 값이 이번 노드의 키 값보다 작다면
        node->left = makeTree(node->left, data); //왼쪽 서브트리 구성
    } else if (node->data < data) { //키 값이 이번 노드의 키 값보다 크다면
        node->right = makeTree(node->right, data); //오른쪽 서브트리 구성
    }
    return node;
}

//후위 순회
void postorder(node_info *node) {
    if (node == NULL) { //노드가 없다면
        return; //트리 없음
    }
    postorder(node->left); //왼쪽 서브트리 훑고
    postorder(node->right); //오른쪽 서브트리 훑고
    cout << node->data << '\n'; //루트 노드 키 값 출력
}

/**
 * 맵과 셋 PPT 중 BST 노드 삽입 과정 참고
 *
 * [이진 검색 트리]
 *
 * 1. 포인터로 왼쪽, 오른쪽 서브트리를 가리키는 구조체 선언
 * 2. NULL 만날 때까지 조건에 따라 왼쪽 또는 오른쪽으로 이동
 * 3. 노드가 들어갈 위치를 찾으면 동적할당 후 노드 만들기
 * 4. 완성한 트리를 후위 순회
 */

int main() {
    int input; //입력받을 노드

    //입력 & 연산
    node_info *root = NULL; //초기화
    while (cin >> input) { //입력이 있는 동안
        root = makeTree(root, input); //트리 생성
    }

    //출럭
    postorder(root);
    return 0;
}