// ���� �켱 Ž�� ���� ���� - stack ���� ����ϱ�? ��� ���� ����ϱ�?
// �湮 ������ 1 4 3 2 �̹Ƿ� => stack ���� ����̴�.
// ��� ���� ����� �湮 ������ 1 2 3 4 �̴�.

// ���� keypoint : ���� dfs �����̴��� stack ������ ��� ������ ��� ��ȸ ������ �ٸ���.
// �̸� �̿��� ������ ������?

// + 2���� �迭�� 10���� �Ѿ�� �޸� �ʰ��� �߻��Ѵ�. �ذ� ���?
// => vector<int> Graph[MAX_EDGE]; �� �ذ��Ѵ�. (��, MAX_EDGE�� �ִ� ������ ����)
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define MAX_N 10000 // �ִ� ������ ���� 20��
int Graph[MAX_N][MAX_N]; // ���� X : 0, ���� O : 1

void dfs(int node, int vertax, int start_node) {
    int visited[MAX_N] = { 0 }; // �� ����� �湮 ���� üũ // 0���� �ʱ�ȭ - �湮X - 0 , �湮 O - 1
    memset(visited, 0, sizeof(visited)); 
    stack<int> s; // dfs ������ ���� ���� ����

    // �ʱ� ��� ó�� (���X)
    s.push(start_node);

    while (!s.empty()) {
        // �湮 ó��
        int current_node = s.top();
        // ��, �湮���� �ʾҴ� ��츸 ���ó��
        if(!visited[current_node]) {
            visited[current_node] = 1;
            cout << current_node << "\n";
        }
        s.pop();

        // ���� �湮�� ��� Ž��
        for (int next_node = 0; next_node < node; next_node++) {
            // ���� ��尡 �� ���� : 1) ������ �湮���� ���� ��� 2) ���� ���� ����Ǿ� �ִ� ���
            if (visited[next_node] != 0) continue; // 1) �湮�� ��� ����ó��
            if (Graph[next_node][current_node] != 1) continue; // 2) ���� ���� ������� ���� ��� ��� ó��

            // ���� ��尡 ������ ��쿡�� ���ÿ� push ó��
            s.push(next_node);
        }


    }
    cout << "0\n"; // ������ 0 ���

}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int node, vertax, start_node; // ����, ����, ���� ���(��ȣ)
    cin >> node >> vertax >> start_node;
    // ������ ���� ���� �Է� �ޱ�
    for (int i = 0; i < vertax; i++) {
        int start, end;
        cin >> start >> end;
        Graph[start][end] = Graph[end][start] = 1;
    }

    dfs(node, vertax, start_node);
    return 0;
}