// #�ùķ��̼�-��ã�� #BFS ��� ���� #���� �Լ�(srand, rand) #���ڿ� �Ľ� #����<->���ڿ� ��ȯ ��ų
// ü�� ���̵� : S1~S2

// ���� �ð� : 52�� 34�� -> 18�� 58�� (�� 33��~34�� �ҿ�)
// 8*8 2���� ��Ŀ��� ����Ʈ�� �̵��� �� �ִ� ����� ���� ���Ͻÿ�.
// ��, ������ �������� �־�����, ������ �ִ� �����δ� �̵��� �� ����.
// ����Ʈ�� �̵��� �Ϸ� �� �� �̵��ϴ� ���� �����̶�� 
// -> �̵� ���� ��� ������ -1�ϰ�, ���� ȸ�� Ƚ���� +1 ���ش�.

// �Է� : c2 
// ��� : {�̵� ���ɰ�� ��}�� �̵��� �� �ֽ��ϴ�. (���� {���� ȸ�� Ƚ��}ȸ ȸ��!)

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int board[8][8]; // ������ (�����̹Ƿ� ��� 0���� �ʱ�ȭ -> 0�� �湮���� ����, 2�� ����)
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    srand((unsigned int)time(NULL)); // ���� �õ� �ο�
    string cur_str_location; // �Է¹��� ���� ��ġ
    int cur_x; // ���� x ��ġ (��)
    int cur_y; // ���� y ��ġ (��)

    // ���� ��ġ ���ϱ�(����) - ������ �ߺ����� 6���� ������ �Ѵ�.
    for(int i=0; i<6; i++) { 
        int bomb_location_x; // ���� ��ġ
        int bomb_location_y; // ���� ��ġ
        bomb_location_x = rand() % 8;
        bomb_location_y = rand() % 8;

        // �̹� �ִ� ������ ��� �ٽ� ���� ��ġ�� �����Ѵ�.
        if(board[bomb_location_y][bomb_location_x] == 2) {
            i--;
            continue;
        }
        
        board[bomb_location_y][bomb_location_x] = 2; // ���� ��ġ�� �����Ѵ�.
    }


    cin >> cur_str_location; // ���� ��ġ�� �Է¹޴´�.
    
    // ���ڿ��� ��ġ -> int���� ��ġ�� ��ȯ�ϱ� ���� �ڵ� (�ε��� ����)
    // cur_x, cur_y �� ��������.
    for(int i=0; i<2; i++) {
        if(i==0) {
            cur_x = cur_str_location[i]-'a';
        }
        else if(i==1) {
            cur_y = cur_str_location[i]-'1';
        }
    } 

    
    // ����Ʈ�� �̵��� �� �ִ� ��� ����� ���� �ùķ��̼��� ���� �̵��Ͽ� ������� ����Ѵ�.
    
    int answer = 0; // �̵� ���� ��� �� 
    int bomb_move = 0; // ���� ȸ�� Ƚ��

    // ����Ʈ�� �̵� ���� �迭
    int move_x[8] = {2,-2,-1,1,2,1,-1,-2};
    int move_y[8] = {-1,-1,-2,-2,1,2,2,1};


    for(int i=0; i<8; i++) {
        int later_x = cur_x + move_x[i];
        int later_y = cur_y + move_y[i];
        
        // �̵��� �� ���� ������ �̵��� ���(�� ������ ��� ���)
        if(later_x < 0 || later_x > 7 || later_y < 0 || later_y > 7) {
            continue;
        }

        // ������ ���� ���
        if(board[later_y][later_x] == 2) {
            bomb_move++;
            continue;
        }

        // �������� ��η� �̵��� ���
        answer++;
    }
    
    cout << answer << "�� �̵��� �� �ֽ��ϴ�. (���� " << bomb_move << "ȸ ȸ��!)";
    return 0;
}

// ��ü ���� test case
//�Է� : c2 -> 5�� �̵��� �� �ֽ��ϴ�. (���� 1ȸ ȸ��!) -> ���
//�Է� : d4 -> 7�� �̵��� �� �ֽ��ϴ�. (���� 1ȸ ȸ��!) -> ���
//�Է� : d4 -> 8�� �̵��� �� �ֽ��ϴ�. (���� 0ȸ ȸ��!) -> ���
//�Է� : a1 -> 2�� �̵��� �� �ֽ��ϴ�. (���� 0ȸ ȸ��!) -> ���