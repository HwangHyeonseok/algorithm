// MenOfPassion(A[], n) {
//     sum <- 0;
//     for i <- 1 to n
//         for j <- 1 to n
//             for k <- 1 to n
//                 sum <- sum + A[i] �� A[j] �� A[k]; # �ڵ�1
//     return sum;
// }

// �ڵ�1 �� �ð����⵵�� O(n^3) �̴�. 

// ��, n�� �ִ��� 50���̹Ƿ� overflow �� ����Ѵ�. long long���� �޴´�.

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n;
    cin >> n;
    cout << n*n*n << "\n";
    cout << "3"; 

    return 0;
}