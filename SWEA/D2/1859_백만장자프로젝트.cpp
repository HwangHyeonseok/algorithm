// #큐 응용

// 최댓값 지점에서는 무조건 판매를 한다. 그게 아닌 구간에서는 무조건 구매를 한다.
// 그런데, 최댓값 지점에서 모두 판 후에는 새로운 최댓값을 찾는다.

// 1 1 3 1 2 7 5 4 
// 최댓값 지점인 7 부분까지 모두 구매를 한다. 
// 이후 5 4 가 남은 부분에서의 최댓값은 5이고, 사자마자 판다.
// 이후 4가 남은 부분에서의 최댓값은 4이고, 이 또한 사자마자 판다.
#include<iostream>
#include<queue>

using namespace std;

queue<int> q;

int main(int argc, char** argv)
{
	int test_case;
	int T; // 테스트 케이스 수
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        long long ans = 0;  // 정답
        int max = 0;
        int N; // 일수
        cin >> N;
        for(int i=0; i<N; i++) {
            int price = 0;
            cin >> price;
            max = max > price? max : price; 
            q.push(price);
        }
        
        while(!q.empty()) {
            if(q.front() < max) { // 사야되는 경우
                ans += max-q.front();
                q.pop();
            }
            else { // 현재의 최댓값을 만나거나, 이미 큰 수를 만난 경우 -> 최댓값을 갱신해주어야 한다.
                q.pop();
                int cur_size = q.size();
                max = 0; // 최댓값 초기화
                for(int i = 0; i < cur_size; i++) {
                    int temp = q.front();
                	q.pop();
                    max = max > temp ? max : temp;
                    q.push(temp);
                }
            }

        }
        cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}