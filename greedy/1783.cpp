// https://www.acmicpc.net/problem/1783

// �׸��� + ����
// N�� M�� ������ �ſ� ũ��. ==> �ð����⵵�� O(1)�̾�� �Ѵ�.
// ���� ����Ʈ�� ������ ���������� �����δٴ� ���� �̿��Ѵ�.

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N,M;
    int answer = 1;

    cin >> N >> M;

    // �� �Ʒ� ��� ����
    if(N >= 3) {
        if(M >= 6) answer = M - 2;
        else if(M == 4 || M == 5) answer = 4;
        else if(M == 3) answer = 3;
        else if(M == 2) answer = 2;
        else if(M <= 1) answer = 1;
    }

    // �� �Ʒ��� �Ű��� �����
    if( N == 2) {
        if(M >= 7) answer = 4;
        else if(M >= 5) answer = 3;
        else if(M >= 3) answer = 2;
        else answer = 1;
    }
    if (N == 1) answer = 1;

    cout << answer;
    return 0;
}