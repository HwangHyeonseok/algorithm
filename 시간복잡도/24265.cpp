// MenOfPassion(A[], n) {
//     sum <- 0;
//     for i <- 1 to n - 1
//         for j <- i + 1 to n
//             sum <- sum + A[i] �� A[j]; # �ڵ�1
//     return sum;
// }

// �ڵ�1 �� �ð����⵵�� O(n^2) �̴�. 
// ���� Ƚ���� (n-1) + (n-2) + .... + 1 �̴�.
// ��, ���������� �տ� ���Ͽ� n-1(n) / 2 �̴�.

// ��, n�� �ִ��� 50���̹Ƿ� overflow �� ����Ѵ�. long long���� �޴´�.

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n;
    cin >> n;
    cout << n*(n-1)/2 << "\n";
    cout << "2"; 

    return 0;
}