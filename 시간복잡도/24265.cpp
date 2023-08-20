// MenOfPassion(A[], n) {
//     sum <- 0;
//     for i <- 1 to n - 1
//         for j <- i + 1 to n
//             sum <- sum + A[i] × A[j]; # 코드1
//     return sum;
// }

// 코드1 의 시간복잡도는 O(n^2) 이다. 
// 실행 횟수는 (n-1) + (n-2) + .... + 1 이다.
// 즉, 등차수열의 합에 의하여 n-1(n) / 2 이다.

// 단, n의 최댓값이 50만이므로 overflow 을 대비한다. long long으로 받는다.

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