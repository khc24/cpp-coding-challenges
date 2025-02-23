/*
문제 003 두 수를 뽑아서 더하기*
: 정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 2개의 수를 뽑아
더해 만들 수 있는 모든 수를 배열에 오름차순으로 담아 반환하는 solution() 함수를 완성하세요.

제약조건
- numbers의 길이는 2 이상 100 이하입니다.
- numbers의 모든 수는 0 이상 100 이하입니다.
*/

#include <vector>
#include <algorithm>
#include <set>

using namespace std;


vector<int> solution(vector<int> numbers)
{
	// 중복 제거 및 오름차순 정렬을 위해 set 사용
	set<int> answer_set;

	for (int i = 0; i < numbers.size(); i++)
		for (int j = i + 1;j < numbers.size(); j++)
			answer_set.insert(numbers[i] + numbers[j]);
	
	vector<int> answer(answer_set.begin(), answer_set.end());
	return answer;
};


//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>
void print(vector<int> vec)
{
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(solution({ 2, 1, 3, 4, 1}));     // 2 3 4 5 6 7 
	print(solution({ 5, 0, 2, 7 }));        // 2 5 7 9 12 

	return 0;
}