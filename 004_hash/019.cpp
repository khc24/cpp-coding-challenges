/*
문제 019 문자열 해싱을 이용한 검색 함수 만들기
: 문자열 배열 string_list와 쿼리 배열 query_list가 있을 때 각 쿼리 배열에 있는 문자열이 string_list의 문자열 배열에 있는지 여부를 확인해야 합니다.
문자열이 있으면 true, 없으면 false가 됩니다. 각 문자열에 대해서 문자열의 존재 여부를 배열 형태로 반환하는 solution() 함수를 작성해 주세요.

제약 조건
- 입력 문자열은 영어 소문자로만 이루어져 있습니다.
- 문자열의 최대 길이는 10^6입니다.
- 해시 충돌은 고려하지 않습니다.
- 아래와 같은 문자열 해싱 방법을 활용해서 해싱 함수를 구현하세요.
- 다음 식에서 p는 31, m은 1,000,000,007로 합니다.
	- hash(s) = (s[0] + s[1]*p + s[2]*p^2 .............. s[n-1]*p^n-1)mod m
*/

#include <vector>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;


vector<bool> solution(vector<string> string_list, vector<string> query_list)
{
	vector<bool> answer;
	map<int, string> hash_table;
	int p = 31;
	int m = 1000000007;

	for (string str : string_list)
	{
		long long hash_value = 0;
		for (int i = 0;i<str.size();i++)
		{
			hash_value += str[i]*pow(p,i);
		}
		hash_value %= m;
		hash_table[hash_value] = str;
	}

	for (string str : query_list)
	{
		long long hash_value = 0;
		for (int i = 0; i < str.size(); i++)
		{
			hash_value += str[i] * pow(p, i);
		}
		hash_value %= m;
		if (hash_table.find(hash_value) != hash_table.end())
		{
			if (hash_table[hash_value] == str)
			{
				answer.push_back(true);
				continue;
			}
		}
		else
		{
			answer.push_back(false);
		}
	}
	return answer;
}


// 해설지 풀이 : 해시 충돌 문제 해결 + 더 나은 성능
long long polynomial_hash(const string& str)
{
	const int p = 31;
	const long long m = 1000000007;
	long long hash_value = 0;

	for (char c : str)
	{
		hash_value = (hash_value * p + c) % m; // pow(p, i)를 쓰지 않고 안전한 방식으로 해시 계산(Overflow 방지)
	}

	return hash_value;
}

vector<bool> solution_commentay(vector<string> string_list, vector<string> query_list)
{
	unordered_set<long long> hash_set; // nordered_set을 사용해 해시 충돌을 효과적으로 방지(map 대신 set)

	for (const string& str : string_list)
	{
		long long hash = polynomial_hash(str);
		hash_set.insert(hash);
	}

	vector<bool> result;

	for (const string& query : query_list)
	{
		long long query_hash = polynomial_hash(query);
		bool found = (hash_set.find(query_hash) != hash_set.end());
		result.push_back(found);
	}
	return result;
}

//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>
void print(vector<bool> vec)
{
	copy(vec.begin(), vec.end(), std::ostream_iterator<bool>(cout, " "));
	cout << endl;
}

int main()
{
	//true를 출력하면 1이되고 false를 출력하면 0
	print(solution_commentay({ "apple", "banana", "cherry" }, { "banana", "kiwi", "melon", "apple" })); // 1 0 0 1
	return 0;

}