// MenOfPassion(A[], n) {
//     sum <- 0;
//     for i <- 1 to n
//         for j <- 1 to n
//             for k <- 1 to n
//                 sum <- sum + A[i] × A[j] × A[k]; # 코드1
//     return sum;
// }

// 코드1 의 시간복잡도는 O(n^3) 이다. 

// 단, n의 최댓값이 50만이므로 overflow 을 대비한다. long long으로 받는다.

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