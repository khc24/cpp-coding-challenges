/*
문제 023 할인 행사**
링크: https://school.programmers.co.kr/learn/courses/30/lessons/131127
: XYZ 마트는 일정한 금액을 지불하면 10일 동안 회원 자격을 부여합니다. XYZ 마트에서는 회원을 대상으로 매일 한 가지 제품을 할인하는 행사를 합니다.
할인하는 제품은 하루에 하나씩만 구매할 수 있습니다. 알뜰한 정현이는 자신이 원하는 제품과 수량이 할인하는 날짜와 10일 연속으로 일치할 경우에 맞춰서 회원가입을 하려 합니다.
예를 들어, 정현이가 원하는 제품이 바나나 3개, 사과 2개, 쌀 2개, 돼지고기 2개, 냄비 1개이며, XYZ 마트에서 14일간 회원을 대상으로 할인하는 제품이 날짜 순서대로 
치킨, 사과, 사과, 바나나, 쌀, 사과, 돼지고기, 바나나, 돼지고기, 쌀, 냄비, 바나나, 사과, 바나나인 경우에 대해 알아봅시다. 첫째 날부터 열흘 간에는 냄비가 할인하지
않기 때문에 첫째 날에는 회원가입을 하지 않습니다. 둘째 날부터 열흘 간에는 바나나를 원하는 만큼 할인구매할 수 없기 때문에 둘째 날에도 회원가입을 하지 않습니다.
셋째 날, 넷째 날, 다섯째 날부터 각각 열흘은 원하는 제품과 수량이 일치하기 때문에 셋 중 하루에 회원가입을 하려 합니다.

정현이가 원하는 제품을 나타내는 문자열 배열 want와 정현이가 원하는 제품의 수량을 나타내는 정수 배열 number, XYZ 마트에서 할인하는 제품을 나타내는 
문자열 배열 discount가 주어졌을 때, 회원등록시 정현이가 원하는 제품을 모두 할인 받을 수 있는 회원등록 날짜의 총 일수를 return 하는 solution 함수를 완성하시오. 
가능한 날이 없으면 0을 return 합니다.

제약 조건
- 1 ≤ want의 길이 = number의 길이 ≤ 10
  - 1 ≤ number의 원소 ≤ 10
  - number[i]는 want[i]의 수량을 의미하며, number의 원소의 합은 10입니다.
  - 10 ≤ discount의 길이 ≤ 100,000
- want와 discount의 원소들은 알파벳 소문자로 이루어진 문자열입니다.
  - 1 ≤ want의 원소의 길이, discount의 원소의 길이 ≤ 12
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;


// 직접 풀이: 시간 복잡도 O(10N) (clear(), find()로 인해 비효율적)
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int total_count = accumulate(number.begin(), number.end(), 0); // 원하는 총 상품 개수 (10개)

    unordered_map<string, int> map_value;

    for (int i = 0; i <= discount.size() - total_count; i++) {
        map_value.clear(); // ❌ 매번 map을 초기화 → 비효율적

        // 현재 i일부터 10일 동안의 할인 품목 개수 계산
        for (int k = i; k < total_count + i; k++) {
            map_value[discount[k]]++; // 상품 개수 증가
        }

        // 원하는 상품과 개수가 일치하는지 검사 (find() 사용 → 불필요한 연산)
        bool temp = true;
        for (int j = 0; j < want.size(); j++) {
            if (map_value[want[j]] < number[j]) { // ❌ 없는 경우 find() 사용 불필요
                temp = false;
                break;
            }
        }
        if (temp) answer++;
    }
    return answer;
}

// 해설지 풀이: 시간 복잡도 O(N), == 연산자로 비교하여 clear(), find() 제거 → 효율성 증가
int solution_commentary(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    unordered_map<string, int> wantMap;
    for (int i = 0; i < want.size(); i++) // 원하는 상품 개수 저장
        wantMap[want[i]] = number[i];

    for (int i = 0; i < discount.size() - 9; i++) { // ✅ 10일 구간 검사 (O(N))
        unordered_map<string, int> discount_10d;

        for (int j = i; j < i + 10; j++) // 10일 동안의 할인 품목 개수 계산
            discount_10d[discount[j]]++;

        if (wantMap == discount_10d) answer++; // ✅ `==` 연산자로 map 비교 (효율적)
    }

    return answer;
}

//여기부터는 테스트 코드 입니다.
#include <iostream>

int main()
{
    cout << solution({ "banana", "apple", "rice", "pork", "pot" },
        { 3, 2, 2, 2, 1 },
        { "chicken", "apple", "apple", "banana", "rice","apple", "pork", "banana", "pork", "rice", "pot","banana", "apple", "banana" }) << endl; // 3

    cout << solution({ "apple" },
        { 10 },
        { "banana", "banana", "banana", "banana","banana", "banana", "banana", "banana", "banana","banana" }) << endl; // 0
    return 0;
}