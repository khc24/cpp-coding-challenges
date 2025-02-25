/*
���� 018 �� ���� ���� Ư�� ���� �����
: n���� ���� ������ �̷���� �迭 arr�� ���� target�� �־����� �� �� �߿��� ���� target�� �� ����
arr�� �ִ��� ã��, ������ true, ������ false�� ��ȯ�ϴ� solution()�Լ��� �ۼ��ϼ���.
*/

#include <vector>
#include <map>
#include <unordered_set>

using namespace std;


// ���� Ǯ��: O(N��) �ð� ���⵵�� ���� (���� for�� ���)
bool solution(vector<int> arr, int target)
{
    int N = arr.size();

    // ��� �� ���� ������ Ȯ���ϴ� �������, �����Ͱ� ���������� ��ȿ����
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (arr[i] + arr[j] == target) return true;

    return false;
}


// �ؼ��� Ǯ��: Hash Table (�迭) ������� Ž�� �ӵ� ����
// �ð� ���⵵�� O(N��)���� O(N)���� �ٿ�����, target ũ�⸸ŭ�� �޸𸮸� �Ҵ��ؾ� �ϴ� ������ ����
bool solution_commentary(vector<int> arr, int target)
{
    vector<int> hash(target, 0); // target ũ���� �迭�� ���� (�޸� ��� ����)

    // �迭�� �����ϴ� ���ڸ� ���
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= target) continue;  // target�� �Ѵ� ���� ����
        hash[arr[i]] = 1;  // �����ϴ� ���ڸ� ǥ��
    }

    // target���� ���� ���ڸ� �� ���� �����ϴ��� Ȯ��
    for (int i = 0; i < arr.size(); i++)
    {
        int temp_num = target - arr[i];
        if (temp_num <= 0 || temp_num == arr[i]) continue;  // ��ȿ���� ���� �� ����
        if (hash[temp_num] == 1) return true;  // ã���� ��� ��ȯ
    }
    return false;
}


// ����ȭ�� Ǯ��: unordered_set�� ����Ͽ� O(N) ���� + �޸� ��� ����ȭ
bool solution_optimized(const vector<int>& arr, int target) {
    unordered_set<int> hash_set;  // Hash Table (unordered_set Ȱ��)

    // �ϳ��� �迭�� ��ȸ�ϸ鼭 complement(¦�� �Ǵ� ��)�� ã�� ��� ��ȯ
    for (int num : arr) {
        int complement = target - num;  // �ʿ��� ¦�� �Ǵ� ���� ���
        if (hash_set.count(complement)) return true;  // �����ϸ� ��� true ��ȯ
        hash_set.insert(num);  // ���� ���ڸ� Hash Set�� ����
    }

    return false;
}


//�Ʒ� �ڵ�� �׽�Ʈ �ڵ� �Դϴ�.
#include <iostream>

int main()
{
    //true�� ����ϸ� 1�̵ǰ� false�� ����ϸ� 0
    cout << solution_commentary({ 1, 2, 3, 4, 8 }, 6) << endl; // 1
    cout << solution_commentary({ 2, 3, 5,9 }, 10) << endl; // 0
    return 0;

}