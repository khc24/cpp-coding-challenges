/*
문제 025 베스트 앨범**
링크: https://school.programmers.co.kr/learn/courses/30/lessons/42579
: 스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 
노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때,
베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

제약 조건
- genres[i]는 고유번호가 i인 노래의 장르입니다.
- plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
- genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
- 장르 종류는 100개 미만입니다.
- 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
- 모든 장르는 재생된 횟수가 다릅니다.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


// 직접 풀이
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	unordered_map<string, int> genres_plays_total;
	unordered_map<string, vector<int>> best_num;

	for (int i = 0; i < genres.size(); i++)
	{
		if (genres_plays_total.find(genres[i]) == genres_plays_total.end())
		{
			genres_plays_total[genres[i]] = plays[i];
			best_num[genres[i]].push_back(i);
		}
		else
		{
			genres_plays_total[genres[i]] += plays[i];
			if (best_num[genres[i]].size() == 2)
			{
				if (plays[best_num[genres[i]][1]] < plays[i])
				{
					if (plays[best_num[genres[i]][0]] < plays[i])
					{
						best_num[genres[i]][1] = best_num[genres[i]][0];
						best_num[genres[i]][0] = i;
					}
					else
					{
						best_num[genres[i]][1] = i;
					}
				}
			}
			else
			{
				if (plays[best_num[genres[i]][0]] < plays[i])
				{
					int temp = best_num[genres[i]][0];
					best_num[genres[i]][0] = i;
					best_num[genres[i]].push_back(temp);
				}
				else
				{
					best_num[genres[i]].push_back(i);
				}
			}


		}
	}

	vector<pair<string, int>> vec(genres_plays_total.begin(), genres_plays_total.end());

	sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
		return a.second > b.second; // 내림차순
		});

	for (const auto& genre : vec)
	{
		for (const auto& idx : best_num[genre.first]) answer.push_back(idx);
	}

	return answer;
}

// 해설지 풀이
bool compareGenre(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second > b.second;
}

bool compareSong(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution_commentary(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	unordered_map<string, vector<pair<int, int>>> genres_dict;
	unordered_map<string, int> play_dict;

	//❶ 장르별 총 재생 횟수와 각 곡의 재생 횟수 저장
	for (int i = 0; i < genres.size(); ++i) {
		genres_dict[genres[i]].push_back({ i, plays[i] });
		play_dict[genres[i]] += plays[i];
	}

	//❷ 총 재생 횟수가 많은 장르순으로 정렬
	vector<pair<string, int>> sorted_genres(play_dict.begin(), play_dict.end());
	sort(sorted_genres.begin(), sorted_genres.end(), compareGenre);

	//❸ 각 장르 내에서 노래를 재생 횟수 순으로 정렬해 최대 2곡 까지 선택
	for (auto& genre : sorted_genres) {
		auto& songs = genres_dict[genre.first];
		sort(songs.begin(), songs.end(), compareSong);

		for (int i = 0; i < min(2, (int)songs.size()); ++i) {
			answer.push_back(songs[i].first);
		}
	}

	return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>
void print(vector<int> vec)
{
	copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 })); //출력값 :  1 0 0 1
	return 0;

}