// #�׸���=>��� ��Ģ / ��� �����ϱ� #���� #���ڿ� ����
// ���ڸ� �����ؼ� 30�� ����� �Ƿ��� �� �ڸ����� ���� 3�� ������� �ϰ� �ּ� �� �� �̻��� 0�� �־�� �Ѵ�. 
// 30�� ����� �Ǵ� ���� ū ����� �Ͽ����Ƿ�, ���� �ִ� ���� �� ���� ū ���� ���� �ڸ����� ��ġ�ϸ� �ȴ�.

// ���� ���̵�� : 30�� ����� �����Ϸ��� 10�� ��� && 3�� ��� �� ���ǿ� �ش��ϸ� �ȴ�.
// 10�� ��� ���� : 0�� �ִ�.
// 3�� ��� ���� : ��� �ڸ����� ���� 3�� ������� �Ѵ�.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string input_str_num;
    vector<int> nums;
    int check_sum = 0;
    bool zero_number = false; // ���� 0�� �ϳ� �̻� �ִ��� üũ

    cin >> input_str_num;

    // ���ڿ� -> �ϳ��ϳ��� ���ڷ� ����
    for(int i=0; i<input_str_num.size(); i++) {
        nums.push_back(input_str_num[i]-'0');
    }

    // �� �ڸ����� ��� ���� 3�� ����� �Ǵ��� üũ + ���� 0�� �ϳ� �̻� �ִ��� üũ
    for(int i=0; i<nums.size(); i++) {
        check_sum += nums[i];
        if(nums[i] == 0)
            zero_number = true;
    }
    
    // �� �ڸ����� ��� ���� 3�� ����� �ƴ϶�� � �������ε� 30�� ����� ���� �� ����.
    if(check_sum % 3 != 0 || zero_number == false) {
        cout << "-1";
        return 0;
    }
    
    // �� �ڸ����� ��� ���� 3�� ����� ���
    // 30�� ����� �Ǵ� ���� ū ����� �Ͽ����Ƿ�, ���� �ִ� ���� �� ���� ū ���� ���� �ڸ����� ��ġ�ϸ� �ȴ�.

    sort(nums.begin(), nums.end(), greater<>()); // 4 3 2 1 .. �������� ����
    
    // �״�� ���ڿ��� �ٲپ ����Ѵ�.
    for(int i=0; i<nums.size(); i++) {
        cout << to_string(nums[i]); 
    }

    return 0;
}