// BFS - Flood Fill ���� + �������� ������ + �Է� ������ ��Ư�� ���� (BFS�� ������)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 101 // M,N�� �ִ� 100
int Board[MAX_N][MAX_N]; // 1 : bfs Ž�� �Ұ���(��)
int M,N,K; // M��N(���� ����), k�� ���簢�� ����

vector<int> areas; // �� ������ ����

int bfs(int start_x, int start_y) {
    int area = 0;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    queue< pair<int, int> > q;
    
    q.push(make_pair(start_x, start_y)); // ť�� x,y
    Board[start_y][start_x] = 1;
    area++;

    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        area++;

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x >= N || next_x < 0 || next_y >= M || next_y < 0) continue;
            if(Board[next_y][next_x] != 0) continue; // �̹� �湮�� ���

            q.push({next_x, next_y});
            Board[next_y][next_x] = 1;
        }

    }
    return area;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int answer = 0; // �и��Ǿ� ���������� ������ ����
        // �Է�
    cin >> M >> N >> K;
    for(int i=0; i<K; i++) {
        int start_x, start_y, end_x, end_y;
        cin >> start_x >> start_y >> end_x >> end_y;
        for(int j=start_y; j< end_y; j++) { // y
            for(int k=start_x; k< end_x; k++) { // x
                Board[j][k] = 1; // ������ ���� | �迭�� : [y][x]
            }
        }
    }

    // bfs ��ȸ ��ġ ã�� : 
    for(int i=0; i<M; i++) { // y
        for(int j=0; j<N; j++) { //x
            if(Board[i][j] == 0) {
                areas.push_back(bfs(j, i)); // bfs�� (x,y)
                answer++;
            }
        }
    } 

    // ���� ���� �������� ����
    sort(areas.begin(), areas.end());

    // ���� ���
    cout << answer << "\n";
    for(int i=0; i<areas.size(); i++) {
        cout << areas[i] - 1 << " ";
    }
    return 0;
}