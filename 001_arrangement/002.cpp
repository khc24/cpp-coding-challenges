/*
문제 002 배열 제어하기**
: 정수 배열 lst가 주어집니다. 배열의 중복값을 제거하고 배열 데이터를 내림차순을오 정렬해서 반환하는 solution() 함수를 구현하세요.

제약 조건
- lst의 길이는 2이상 1,000 이하입니다.
- lst의 우너소 값은 -100,000 이상 100,000 이하입니다.
*/

#include <vector>
#include <algorithm> // sort, unique를 위해 선언
#include <set>

using namespace std;


vector<int> solution(vector<int> lst)
{
    // 방법 1 중복값 제거 오름차순 정렬, 중복 제거, 원소 삭제, 내림차순 정렬 
    sort(lst.begin(), lst.end());
    lst.erase(unique(lst.begin(), lst.end()),lst.end());
    
    // vector 내침차순 정렬 방식 1. reverse 함수
    reverse(lst.begin(), lst.end());

    // vector 내침차순 정렬 방식 2. srot()
    sort(lst.begin(), lst.end(), greater<int>());

    // 방법 2 set() 이용한 중복 제거, 내림차순 정렬
    set<int, greater<int>> s(lst.begin(), lst.end());
    vector<int> answer(s.begin(), s.end());


    return answer;
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>
void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
  
    print(solution({ 4, 2, 2, 1, 1, 3, 4 })); // 4 3 2 1  
    print(solution({ 2, 1, 1, 3, 2, 5, 4 })); // 5 4 3 2 1

    return 0;
}