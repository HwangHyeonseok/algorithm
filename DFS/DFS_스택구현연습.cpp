#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

#define MAX_N 10 // 최대 노드 개수 : 10
int Graph[MAX_N][MAX_N]; 
int node, edge; // 노드와 간선 개수

void dfs(int root) {
    int visited[MAX_N]; // 방문 여부 체크 배열
    stack<int> s; // dfs 탐색을 위한 스택
    memset(visited, 0, sizeof(visited)); // visited 배열 값을 모두 0으로 초기화
    
    // 루트 노드 방문 -> 스택 푸시
    s.push(root);

    while(!s.empty()) {
        // 1. 스택의 top 방문 처리 (이전에 방문 처리를 한 적 없는 노드만)
        int cur_node = s.top();
        s.pop();
        if(visited[cur_node] == 1) continue;
        
        visited[cur_node] = 1;
        cout << cur_node << " ";


        // 2. 다음 노드 탐색
        for(int next = 0; next < node; next++) {
            if(visited[next] != 0 || Graph[next][cur_node] != 1) {
                continue;
            }
            
            s.push(next);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> node >> edge;
    // 간선 정보 등록
    for (int i=0; i<edge; i++) {
        int start, end;
        cin >> start >> end;
        Graph[start][end] = Graph[end][start] = 1; 
    }

    dfs(0); // root 노드 : 0
    return 0;
}