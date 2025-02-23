/*
���� 019 ���ڿ� �ؽ��� �̿��� �˻� �Լ� �����
: ���ڿ� �迭 string_list�� ���� �迭 query_list�� ���� �� �� ���� �迭�� �ִ� ���ڿ��� string_list�� ���ڿ� �迭�� �ִ��� ���θ� Ȯ���ؾ� �մϴ�.
���ڿ��� ������ true, ������ false�� �˴ϴ�. �� ���ڿ��� ���ؼ� ���ڿ��� ���� ���θ� �迭 ���·� ��ȯ�ϴ� solution() �Լ��� �ۼ��� �ּ���.

���� ����
- �Է� ���ڿ��� ���� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
- ���ڿ��� �ִ� ���̴� 10^6�Դϴ�.
- �ؽ� �浹�� ������� �ʽ��ϴ�.
- �Ʒ��� ���� ���ڿ� �ؽ� ����� Ȱ���ؼ� �ؽ� �Լ��� �����ϼ���.
- ���� �Ŀ��� p�� 31, m�� 1,000,000,007�� �մϴ�.
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


// �ؼ��� Ǯ�� : �ؽ� �浹 ���� �ذ� + �� ���� ����
long long polynomial_hash(const string& str)
{
	const int p = 31;
	const long long m = 1000000007;
	long long hash_value = 0;

	for (char c : str)
	{
		hash_value = (hash_value * p + c) % m; // pow(p, i)�� ���� �ʰ� ������ ������� �ؽ� ���(Overflow ����)
	}

	return hash_value;
}

vector<bool> solution_commentay(vector<string> string_list, vector<string> query_list)
{
	unordered_set<long long> hash_set; // nordered_set�� ����� �ؽ� �浹�� ȿ�������� ����(map ��� set)

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

//�Ʒ� �ڵ�� �׽�Ʈ �ڵ� �Դϴ�.
#include <iterator>
#include <iostream>
void print(vector<bool> vec)
{
	copy(vec.begin(), vec.end(), std::ostream_iterator<bool>(cout, " "));
	cout << endl;
}

int main()
{
	//true�� ����ϸ� 1�̵ǰ� false�� ����ϸ� 0
	print(solution_commentay({ "apple", "banana", "cherry" }, { "banana", "kiwi", "melon", "apple" })); // 1 0 0 1
	return 0;

}