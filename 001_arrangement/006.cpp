/*
���� 006 ������**
:���� ���� ������ �������� ū ��ο� ������. �׳డ ���� ������ ��õ���� �뼺���� �ŵ�����, ���� �ű� ������� ���� �ް��� ���̴�. 
������ �ű� ����ڿ� ���� ����� ���̿� �������� ���̰� �ʹ� ū ���� ��������.

�� ������ ��� �ұ� ��� �� �׳�� �������� ���� �ð��� �÷��� ���̵��� �����ϱ�� �ߴ�. 
���� ���� �����ڶ� ��κ��� ������ ���� ����������, �������� ���ϴ� �κп��� ���⿡ ������ ���Ҵ�. �������� ���� �������� ���ϴ� �ڵ带 �ϼ��϶�.

�������� ������ ���� �����Ѵ�.
���������� ���������� ���� Ŭ�������� ���� �÷��̾��� �� / ���������� ������ �÷��̾� ��
��ü ���������� ���� N, ������ �̿��ϴ� ����ڰ� ���� �����ִ� ���������� ��ȣ�� ��� �迭 stages�� �Ű������� �־��� ��, 
�������� ���� ������������ ������������ ���������� ��ȣ�� ����ִ� �迭�� return �ϵ��� solution �Լ��� �ϼ��϶�.

���� ����
- ���������� ���� N�� 1 �̻� 500 ������ �ڿ����̴�.
- stages�� ���̴� 1 �̻� 200,000 �����̴�.
- stages���� 1 �̻� N + 1 ������ �ڿ����� ����ִ�.
	- �� �ڿ����� ����ڰ� ���� ���� ���� ���������� ��ȣ�� ��Ÿ����.
	- ��, N + 1 �� ������ ��������(N ��° ��������) ���� Ŭ���� �� ����ڸ� ��Ÿ����.
- ���� �������� ���� ���������� �ִٸ� ���� ��ȣ�� ���������� ���� ������ �ϸ� �ȴ�.
- ���������� ������ ������ ���� ��� �ش� ���������� �������� 0 ���� �����Ѵ�.
*/

#include <vector>
#include <map>
#include <algorithm>

using namespace std;


struct compare
{
	bool operator()(pair<int, float> a, pair<int, float> b)
		const {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second > b.second;
	
	}
};


vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	float gamers = stages.size();
	vector<int> stage_in_gamer(N+2, 0);
	vector<pair<int, float>> fail_rate;
	for (int i=0; i < stages.size(); i++)
	{
		stage_in_gamer[stages[i]]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (stage_in_gamer[i]>0)
		{
			fail_rate.push_back({i, stage_in_gamer[i] / gamers });
			gamers -= stage_in_gamer[i];
		}
		else
		{
			fail_rate.push_back({i,0});
		}
	}

	sort(fail_rate.begin(), fail_rate.end(), compare());
	for (const auto& it : fail_rate) answer.push_back(it.first);
	return answer;
}


//�Ʒ� �ڵ�� �׽�Ʈ �ڵ� �Դϴ�.
#include <iterator>
#include <iostream>
void print(vector<int> vec)
{
	copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 })); // 3 4 2 1 5
	print(solution(4, { 4, 4, 4, 4, 4 }));          // 4 1 2 3 

	return 0;
}