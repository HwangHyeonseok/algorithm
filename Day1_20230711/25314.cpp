// long int �� 4����Ʈ �ڷ���
// long long int �� 8����Ʈ �ڷ���, long long long int �� 12����Ʈ �ڷ��� �̶�� ����.
// ��, �ڷ��� 'long' Ű���尡 �ϳ� ���� ������ 4N ����Ʈ�� �ڷ����� �ȴ�. (N�� long Ű������ ����)

#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int bytes;
    cin >> bytes;
    
    while(bytes >= 4) {
        bytes -= 4;
        cout << "long ";
    }
    cout << "int";
    return 0;
}