// int�� ���� : �� 21��
// int�� ������ �ʰ��� ����� �����Ƿ� long long int �� ����Ѵ�.

#include <iostream>
#include <math.h>

using namespace std;

int main(void) {
    // �ڵ� ���� �ӵ��� �����ֱ� ���� ��ũ��
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long int a,b,c;
    long long int answer;
    cin >> a >> b >> c;
    answer = a+b+c;
    cout << answer;
    return 0;
}