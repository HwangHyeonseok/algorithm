// MenOfPassion(A[], n) {
//     sum <- 0;
//     for i <- 1 to n
//         for j <- 1 to n
//             sum <- sum + A[i] �� A[j]; # �ڵ�1
//     return sum;
// }

// �ڵ�1 �� �ð����⵵�� O(n^2) �̴�. ��, n�� �ݺ��Կ� ���� �ڵ�1�� n^2�� ����ǰ� �ȴ�.

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    cout << n*n << "\n";
    cout << "2"; 

    return 0;
}