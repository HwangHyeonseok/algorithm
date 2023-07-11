// �ð� ���� ����
// 1-1. ���� �ð��� �а� ���� ���� ���ļ� 60 �̸��̸� -> �״�� ���� �� ���
// 1-2. ���� �ð��� �а� ���� ���� ���ļ� 60 �̻��̸�
// ���� ���� ���� 60 �̸��� �� ������ �ð��� +1 �ϰ�, ���� -60�Ѵ�.

// �������� : 23�ø� �Ѿ�� 0�÷� �ǵ��ư��� ��.

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int min; // ��
    int hour; // �ð�
    int plus_min; // ���� �ð�

    cin >> hour >> min;
    cin >> plus_min;
    min = min+plus_min;

    while(min >= 60) {
        hour++; 
        min-=60;
        if(hour>=24) {
            hour -= 24;
        }
    }
    
    cout << hour << " " << min;
    
    return 0;
}