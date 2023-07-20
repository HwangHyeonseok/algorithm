#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define MAX_N 10
int Graph[MAX_N][MAX_N]; // 미연결 : 0, 연결 : 1
int edge, node;

void bfs(int root) {
    queue<int> q; // BFS 구현을 위한 보조 큐
    int visited[MAX_N]; // 미방문 : 0, 방문 : 1
    memset(visited, 0, sizeof(visited));

    // root 노드 방문 처리
    q.push(root);
    visited[root] = 1;
    
    while(!q.empty()) {
        // 방문처리 + 출력 처리
        int cur_node = q.front();
        q.pop();

        cout << cur_node << " ";

        // 다음 노드 탐색 - 1) 이전에 방문한 적이 없고 2) 인접한 노드
        for(int next=0; next<node; next++) {
            if (visited[next] == 0 && Graph[cur_node][next] != 0) {
            // 먼저 들어간 노드가 항상 먼저 방문되기 때문에 동일한 노드를 다시 enqueue 할 이유가 없다.
                visited[next] = 1;
                q.push(next);
            }

        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> node >> edge;
     // 간선 연결 정보
    for(int i=0; i<edge; i++) 
    {
        int start, end;
        cin >> start >> end;
        Graph[start][end] = Graph[end][start] = 1;
    }

    bfs(0); // root노드 : 0
    return 0;
}