// #ť ����

// �ִ� ���������� ������ �ǸŸ� �Ѵ�. �װ� �ƴ� ���������� ������ ���Ÿ� �Ѵ�.
// �׷���, �ִ� �������� ��� �� �Ŀ��� ���ο� �ִ��� ã�´�.

// 1 1 3 1 2 7 5 4 
// �ִ� ������ 7 �κб��� ��� ���Ÿ� �Ѵ�. 
// ���� 5 4 �� ���� �κп����� �ִ��� 5�̰�, ���ڸ��� �Ǵ�.
// ���� 4�� ���� �κп����� �ִ��� 4�̰�, �� ���� ���ڸ��� �Ǵ�.
#include<iostream>
#include<queue>

using namespace std;

queue<int> q;

int main(int argc, char** argv)
{
	int test_case;
	int T; // �׽�Ʈ ���̽� ��
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        long long ans = 0;  // ����
        int max = 0;
        int N; // �ϼ�
        cin >> N;
        for(int i=0; i<N; i++) {
            int price = 0;
            cin >> price;
            max = max > price? max : price; 
            q.push(price);
        }
        
        while(!q.empty()) {
            if(q.front() < max) { // ��ߵǴ� ���
                ans += max-q.front();
                q.pop();
            }
            else { // ������ �ִ��� �����ų�, �̹� ū ���� ���� ��� -> �ִ��� �������־�� �Ѵ�.
                q.pop();
                int cur_size = q.size();
                max = 0; // �ִ� �ʱ�ȭ
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