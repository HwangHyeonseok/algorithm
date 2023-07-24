// 깊이 우선 탐색 구현 연습 - stack 구현 방법일까? 재귀 구현 방법일까?
// 방문 순서가 1 4 3 2 이므로 => stack 구현 방법이다.
// 재귀 구현 방법은 방문 순서가 1 2 3 4 이다.

// 문제 keypoint : 같은 dfs 구현이더라도 stack 구현과 재귀 구현의 노드 순회 순서는 다르다.
// 이를 이용한 문제가 있을까?

// + 2차원 배열은 10만이 넘어가면 메모리 초과가 발생한다. 해결 방안?
// => vector<int> Graph[MAX_EDGE]; 로 해결한다. (단, MAX_EDGE는 최대 간선의 개수)
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define MAX_N 10000 // 최대 간선의 개수 20만
int Graph[MAX_N][MAX_N]; // 연결 X : 0, 연결 O : 1

void dfs(int node, int vertax, int start_node) {
    int visited[MAX_N] = { 0 }; // 각 노드의 방문 상태 체크 // 0으로 초기화 - 방문X - 0 , 방문 O - 1
    memset(visited, 0, sizeof(visited)); 
    stack<int> s; // dfs 구현을 위한 보조 스택

    // 초기 노드 처리 (출력X)
    s.push(start_node);

    while (!s.empty()) {
        // 방문 처리
        int current_node = s.top();
        // 단, 방문하지 않았던 경우만 출력처리
        if(!visited[current_node]) {
            visited[current_node] = 1;
            cout << current_node << "\n";
        }
        s.pop();

        // 다음 방문할 노드 탐색
        for (int next_node = 0; next_node < node; next_node++) {
            // 다음 노드가 될 조건 : 1) 이전에 방문하지 않은 노드 2) 현재 노드와 연결되어 있는 노드
            if (visited[next_node] != 0) continue; // 1) 방문한 경우 예외처리
            if (Graph[next_node][current_node] != 1) continue; // 2) 현재 노드와 연결되지 않은 경우 노드 처리

            // 다음 노드가 충족된 경우에만 스택에 push 처리
            s.push(next_node);
        }


    }
    cout << "0\n"; // 끝나면 0 출력

}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int node, vertax, start_node; // 정점, 간선, 시작 노드(번호)
    cin >> node >> vertax >> start_node;
    // 간선의 연결 상태 입력 받기
    for (int i = 0; i < vertax; i++) {
        int start, end;
        cin >> start >> end;
        Graph[start][end] = Graph[end][start] = 1;
    }

    dfs(node, vertax, start_node);
    return 0;
}