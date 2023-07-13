// Ű���� : #���ڿ� �Ľ�(parsing), #��ã�� �ùķ��̼�

// ���� : ���谡 A�� N�� �������� ��ȹ���� ���� �̵��ϴ� ���, ���� �����ϴ� ��ǥ�� (X, Y)�� ����Ͻÿ�.
// ���� : N X N�� 2���� ���, ���谡�� ���� ��ǥ�� 1, 1
// ���� : �ùķ��̼� ���� - �����ϴ� �䱸���׿� ���� �ܰ躰�� ����
// (��, ���� ���� �̵��� �����Ѵ�.)

// U�� up, D�� down, R�� right, L�� left

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    int N; // ���� ũ��� N*N
    int cur_x = 1; int cur_y = 1; // �ʱ� ��ġ
    string str;
    string Buffer;
    vector<string> directions; // ������� �����س��� ����

    cin >> N; // ���� ũ�⸦ ���Ѵ�.
    cin.ignore(); // ���� ����(���� ����)

    getline(cin, str); // ������ �Է� �޴´�.
    istringstream ss(str); // ss ��Ʈ���� ���ڿ��� �־��ش�.

    // �Է¹��� ������ ���ڿ� �Ľ��� �����Ѵ�.
    // ss ��Ʈ������ �� ĭ�� ���� �������� Buffer�� �����Ѵ�.
    while(getline(ss, Buffer, ' ')) {
        directions.push_back(Buffer);
    }

    for(int i=0; i<directions.size(); i++) {
        if(directions[i] == "U") { // Up �Է� ��
            if(cur_y > 1)
                cur_y += -1;
        }
        else if(directions[i] == "D") { // Down �Է� ��
            if(cur_y < N)
                cur_y += +1;
        }
        else if(directions[i] == "L") { // Left �Է� ��
            if(cur_x > 1)
                cur_x += -1;
        }
        else if(directions[i] == "R") { // Right �Է� ��
            if(cur_x < N)
                cur_x += +1;
        }
    }



    cout << cur_y << " " << cur_x;

    return 0;
}