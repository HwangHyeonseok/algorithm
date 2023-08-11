// unordered_set vs set 차이 이용 - 중복 제거 (시간 복잡도 계산 필요)

// 심지어 CD의 목록은 이미 정렬되어 있으므로 정렬도 포함된 set을 굳이 쓸 필요가 없다.
// ==> unordered_set을 사용하자.

#include <unordered_set>
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N,M;  // 최대 100만

    while(1) {
        unordered_set<long long> CD; // 2억대가 넘으므로 long long
        int answer = 0;
        cin >> N >> M;

        if(N == 0 && M == 0) break;
        for(int i=0; i<N; i++) {
            long long x;
            cin >> x;
            CD.insert(x);
        }
        for(int i=0; i<M; i++) {
            long long x;
            cin >> x;
            if(CD.find(x) == CD.end()) continue; // 찾기 못한 경우
            answer++;
        }
        // CD set 비우기
        //CD.clear();
        cout << answer << "\n";

    }
    
    return 0;
}



// 중복 찾기 - set 사용 시 최악의 경우 O(log N ) 이므로, log 100만이다.
// 상근이의 목록에 set 100만개를 삽입하고, 그 목록을 순회하면서 100만개를 찾지만 여러개의 테스트 케이스가 있으므로, 시간 초과가 났던 것이다.

// #include <set>
// #include <iostream>

// using namespace std;

// int main(void) {
//     ios_base::sync_with_stdio(false); cin.tie(nullptr);
//     int N,M;  // 최대 100만

//     while(1) {
//         set<long long> CD; // 2억대가 넘으므로 long long
//         int answer = 0;
//         cin >> N >> M;

//         if(N == 0 && M == 0) break;
//         for(int i=0; i<N; i++) {
//             long long x;
//             cin >> x;
//             CD.insert(x);
//         }
//         for(int i=0; i<M; i++) {
//             long long x;
//             cin >> x;
//             if(CD.find(x) == CD.end()) continue; // 찾기 못한 경우
//             answer++;
//         }
//         // CD set 비우기
//         //CD.clear();
//         cout << answer << "\n";

//     }
    
//     return 0;
// }