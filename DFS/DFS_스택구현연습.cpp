#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

#define MAX_N 10 // �ִ� ��� ���� : 10
int Graph[MAX_N][MAX_N]; 
int node, edge; // ���� ���� ����

void dfs(int root) {
    int visited[MAX_N]; // �湮 ���� üũ �迭
    stack<int> s; // dfs Ž���� ���� ����
    memset(visited, 0, sizeof(visited)); // visited �迭 ���� ��� 0���� �ʱ�ȭ
    
    // ��Ʈ ��� �湮 -> ���� Ǫ��
    s.push(root);

    while(!s.empty()) {
        // 1. ������ top �湮 ó�� (������ �湮 ó���� �� �� ���� ��常)
        int cur_node = s.top();
        s.pop();
        if(visited[cur_node] == 1) continue;
        
        visited[cur_node] = 1;
        cout << cur_node << " ";


        // 2. ���� ��� Ž��
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
    // ���� ���� ���
    for (int i=0; i<edge; i++) {
        int start, end;
        cin >> start >> end;
        Graph[start][end] = Graph[end][start] = 1; 
    }

    dfs(0); // root ��� : 0
    return 0;
}