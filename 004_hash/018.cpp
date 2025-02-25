/*
문제 018 두 개의 수로 특정 값을 만들기
: n개의 양의 정수로 이루어진 배열 arr와 정수 target이 주어졌을 때 이 중에서 합이 target인 두 수가
arr에 있는지 찾고, 있으면 true, 없으면 false를 반환하는 solution()함수를 작성하세요.
*/

#include <vector>
#include <map>
#include <unordered_set>

using namespace std;


// 직접 풀이: O(N²) 시간 복잡도를 가짐 (이중 for문 사용)
bool solution(vector<int> arr, int target)
{
    int N = arr.size();

    // 모든 두 수의 조합을 확인하는 방식으로, 데이터가 많아질수록 비효율적
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (arr[i] + arr[j] == target) return true;

    return false;
}


// 해설지 풀이: Hash Table (배열) 사용으로 탐색 속도 개선
// 시간 복잡도를 O(N²)에서 O(N)으로 줄였으나, target 크기만큼의 메모리를 할당해야 하는 단점이 있음
bool solution_commentary(vector<int> arr, int target)
{
    vector<int> hash(target, 0); // target 크기의 배열을 생성 (메모리 사용 증가)

    // 배열에 등장하는 숫자를 기록
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= target) continue;  // target을 넘는 값은 무시
        hash[arr[i]] = 1;  // 존재하는 숫자를 표시
    }

    // target에서 현재 숫자를 뺀 값이 존재하는지 확인
    for (int i = 0; i < arr.size(); i++)
    {
        int temp_num = target - arr[i];
        if (temp_num <= 0 || temp_num == arr[i]) continue;  // 유효하지 않은 값 제외
        if (hash[temp_num] == 1) return true;  // 찾으면 즉시 반환
    }
    return false;
}


// 최적화된 풀이: unordered_set을 사용하여 O(N) 유지 + 메모리 사용 최적화
bool solution_optimized(const vector<int>& arr, int target) {
    unordered_set<int> hash_set;  // Hash Table (unordered_set 활용)

    // 하나씩 배열을 순회하면서 complement(짝이 되는 수)를 찾아 즉시 반환
    for (int num : arr) {
        int complement = target - num;  // 필요한 짝이 되는 숫자 계산
        if (hash_set.count(complement)) return true;  // 존재하면 즉시 true 반환
        hash_set.insert(num);  // 현재 숫자를 Hash Set에 저장
    }

    return false;
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
    //true를 출력하면 1이되고 false를 출력하면 0
    cout << solution_commentary({ 1, 2, 3, 4, 8 }, 6) << endl; // 1
    cout << solution_commentary({ 2, 3, 5,9 }, 10) << endl; // 0
    return 0;

}