#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_N 10

int Graph[MAX_N][MAX_N]; // 간선 연결 정보를 담은 배열
int node, edge; // 노드 개수, 간선 개수
int visited[MAX_N]; // 이전 방문 여부 체크
void dfs(int root) {
    // 방문 처리
    visited[root] = 1;
    cout << root << " ";

    // 다음 노드 탐색
    for(int next=0; next<node; next++) {
        // 다음 노드가 될 조건 : 1) 이전에 방문한 적이 없는 노드 2) 이전 노드와 연결이 되어 있는 노드
        if(visited[next] != 0 || Graph[next][root] != 1)
            continue;
        // 재귀적으로 다음 노드에 접근
        dfs(next);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> node >> edge;

    // 노드 연결 정보
    for(int i=0; i<edge; i++) {
        int start, end;
        cin >> start >> end;
        Graph[start][end]  = Graph[end][start] = 1;
    }

    dfs(0); // 시작 노드(root 노드) : 0
    return 0;
}