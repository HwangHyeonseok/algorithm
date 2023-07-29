// �������� �������� BFS + 3���� �迭

// �� �ε����� ������ ���ϰ� ����ϱ�
// �� ���������� [z][y][x] ��ġ�̴�.

#include <iostream>
#include <queue>
#include <algorithm> // fill ���
#include <tuple> // tuple ���

using namespace std;

#define MAX_N 101  // M,N,H�� �ִ� 100����
int M,N,H;
int Board[MAX_N][MAX_N][MAX_N]; // ���� 1�� ���� �丶��, ���� 0 �� ���� ���� �丶��, ���� -1�� �丶�䰡 ������� ���� ĭ

queue< tuple<int, int, int> > Q; // BFS ���� ť

void bfs() {
    // �����¿� ���Ʒ� ������ ���� �迭
    int dx[6] = {-1, 1, 0, 0, 0, 0};
    int dy[6] = {0, 0, -1, 1, 0, 0};
    int dz[6] = {0, 0, 0, 0, -1, 1}; 
    
    while(!Q.empty()) {
        int cur_x = get<0>(Q.front());
        int cur_y = get<1>(Q.front());
        int cur_z = get<2>(Q.front());
        Q.pop();

        for(int i=0; i<6; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            int next_z = cur_z + dz[i];

            // ���� ���� �ȿ� �ִ��� ���� üũ + ���� ������ �丶�信 �ش��ϴ��� üũ
            if(next_x >= M || next_x < 0 || next_y >= N || next_y < 0 || next_z >= H || next_z < 0) continue;
            if(Board[next_z][next_y][next_x] != 0) continue;
            
            Q.push({next_x, next_y, next_z});
            Board[next_z][next_y][next_x] = Board[cur_z][cur_y][cur_x] + 1;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    fill(&Board[0][0][0], &Board[MAX_N-1][MAX_N-1][MAX_N], -1); // Board �迭 ��� -1�� �ʱ�ȭ 
    int answer = 0;

    cin >> M >> N >> H; // M : x������, N : y������, H : z������
    // �丶�� ���� �Է¹ޱ�
    for(int i=0; i<H; i++) { // z
        for(int j=0; j<N; j++) { // y
            for(int k=0; k<M; k++) { // x
                int condition;
                cin >> condition;
                Board[i][j][k] = condition;
            }
        }
    }
    // �丶�䰡 ���� ���� ��� push�Ͽ� bfs ��ȸ
    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                if(Board[i][j][k] == 1) 
                    Q.push(make_tuple(k,j,i)); // x,y,z�� ������.
            }
        }
    }

    bfs();

    // ������ �丶�䰡 ������ üũ + �̵� Ƚ�� ���ϱ�
    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                if(Board[i][j][k] == 0) {
                    cout << "-1";
                    return 0;
                }
                else {
                    answer = max(answer, Board[i][j][k]);
                }

            }
        }
    }

    cout << answer - 1 ;
    return 0;
}