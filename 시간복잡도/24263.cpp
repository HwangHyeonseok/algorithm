// MenOfPassion(A[], n) {
//     sum <- 0;
//     for i <- 1 to n
//         sum <- sum + A[i]; # 코드1
//     return sum;
// }

// 코드1 의 시간복잡도는 O(n) 이다. 즉, n번 반복함에 따라 코드1도 n번 실행되게 된다.

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    cout << n << "\n";
    cout << "1"; 

    return 0;
}