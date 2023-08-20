// MenOfPassion(A[], n) {
//     sum <- 0;
//     for i <- 1 to n
//         for j <- 1 to n
//             sum <- sum + A[i] × A[j]; # 코드1
//     return sum;
// }

// 코드1 의 시간복잡도는 O(n^2) 이다. 즉, n번 반복함에 따라 코드1도 n^2번 실행되게 된다.

// 단, n의 최댓값이 50만이므로 overflow 을 대비한다. long long으로 받는다.

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n;
    cin >> n;
    cout << n*n << "\n";
    cout << "2"; 

    return 0;
}