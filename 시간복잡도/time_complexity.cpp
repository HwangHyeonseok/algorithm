// �ð� ���⵵ �����ϱ�

// 1) ctime ���̺귯���� �߰��Ѵ�.
// 2) time_t ��ü�� ������ش�. (start, end)
// 3) ���� �ð��� ��´�. 
// 4) ���α׷� �ҽ��ڵ带 �ۼ��Ѵ�.
// 5) ���α׷� �ҽ��ڵ带 �����ϰ� �� ���� �ð��� ��´�.
// 6) ( ���� �ð� - ���� �ð� ) / CLOCKS_PER_SEC �� �Ѵ�.

// Ex. ��� : 16.35 �̸�, ���α׷� ������ 16.35�� �ɷȴٴ� �ǹ��̴�.
#include <iostream> 
#include <ctime> // 1)

using namespace std;

int main(void) {
    time_t start, end; // 2)
    double time;
    int sum = 0;

    start = clock(); // �ð� ���� ����

    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 100000; j++) {
            sum += i * j;
        }
    }

    end = clock(); // �ð� ���� ����
    double result = (double)(end - start) / CLOCKS_PER_SEC ; // ���� �ð� - ���� �ð� = �ɸ� �ð�
    cout << result;
    return 0;
}
