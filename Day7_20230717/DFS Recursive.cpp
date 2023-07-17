// DFS 재귀 구현 연습
#include <iostream>
#include <vector>
#include <string.h> // memset 메서드 사용을 위한 라이브러리
using namespace std;
#define MAX_N 10 // 최대 10 * 10의 맵

int Graph[MAX_N][MAX_N];
int point, edge; // 정점과 간선

int Visited[MAX_N]; // 각 지점이 방문이 되었는지 체크하는 배열

// dfs 재귀 구현
void dfs(int node) {
    // 1. 방문 처리 후 출력
    Visited[node] = 1;
    cout << node << " ";

    // 2. 다음 노드 탐색
    for (int next = 0; next < point; next++) {
        // 다음 노드의 조건 - 이전에 방문한 적이 없고 현재 노드와 연결이 되어 있어야 한다.
        if ((Visited[next] == 0) && (Graph[next][node] == 1))
            dfs(next);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> point >> edge;
    // 간선의 연결 정보 입력
    for (int i = 0; i < edge; i++) {
        int start, end;
        cin >> start >> end;
        Graph[start][end] = Graph[end][start] = 1; // 3과 5가 연결된거나, 5와 3이 연결된거나 같은 의미기 때문
    }

    dfs(0); // root 노드 0

    return 0;
}