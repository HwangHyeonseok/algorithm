#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;
#define MAX_N 10 // �ִ� �� ũ�� 10 * 10
int Graph[MAX_N][MAX_N];
int n; // �� ũ��

void dfs(int start_y, int start_x, int paint) {
    typedef pair<int, int> p;
    stack<p> s;
    // �����¿� �̵��� ���� �迭
    int move_x[4] = {0, 0, -1, 1};
    int move_y[4] = {-1, 1, 0, 0};
    
    // ù ��ġ ���ÿ� push
    s.push(make_pair(start_y, start_x)); // s.push({start_y,start_x}); �� ����

    while(!s.empty()) {
        // 1. �湮 ó�� �� �� ó��
        int cur_x = s.top().second;
        int cur_y = s.top().first;
        s.pop();
        
        if(Graph[cur_y][cur_x] != 0) continue;

        Graph[cur_y][cur_x] = paint;

        // 2. �ֺ� ��� Ž�� (�����¿�)
        for(int next = 0; next < 4; next++) {
            int next_x = cur_x + move_x[next];
            int next_y = cur_y + move_y[next];

            // �̵��� ������ ���� : 1) �̵��� ������ �����̰ų�, 2) �̹� �̵��� ���� ���� ���� 3) �� ���� ��
            if(Graph[next_y][next_x] != 0) // 1) 2)
                continue;
            if(next_x >= n || next_x < 0 || next_y >= n || next_y < 0) //3)
                continue;
            
            s.push(make_pair(next_y, next_x));
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << Graph[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n; 
    // �� ���� �Է�
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int condition; // 0 : �̵� ����, 1 : ��(�̵� �Ұ�)
            cin >> condition;
            Graph[i][j] = condition;
        }
    }
    
    // ���� ����
    int start_x, start_y, paint;
    cin >> start_x >> start_y >> paint;
    
    dfs(start_y, start_x, paint);
    return 0;
}