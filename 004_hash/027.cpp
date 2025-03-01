/*
문제 027 메뉴 리뉴얼***
링크: https://school.programmers.co.kr/learn/courses/30/lessons/72411
: 레스토랑을 운영하던 스카피는 코로나19로 인한 불경기를 극복하고자 메뉴를 새로 구성하려고 고민하고 있습니다.
기존에는 단품으로만 제공하던 메뉴를 조합해서 코스요리 형태로 재구성해서 새로운 메뉴를 제공하기로 결정했습니다. 
어떤 단품메뉴들을 조합해서 코스요리 메뉴로 구성하면 좋을 지 고민하던 "스카피"는 이전에 각 손님들이 주문할 때 
가장 많이 함께 주문한 단품메뉴들을 코스요리 메뉴로 구성하기로 했습니다.
단, 코스요리 메뉴는 최소 2가지 이상의 단품메뉴로 구성하려고 합니다. 또한, 최소 2명 이상의 손님으로부터 
주문된 단품메뉴 조합에 대해서만 코스요리 메뉴 후보에 포함하기로 했습니다.

예를 들어, 손님 6명이 주문한 단품메뉴들의 조합이 다음과 같다면,
(각 손님은 단품메뉴를 2개 이상 주문해야 하며, 각 단품메뉴는 A ~ Z의 알파벳 대문자로 표기합니다.)

손님 번호	주문한 단품메뉴 조합
1번 손님	A, B, C, F, G
2번 손님	A, C
3번 손님	C, D, E
4번 손님	A, C, D, E
5번 손님	B, C, F, G
6번 손님	A, C, D, E, H

가장 많이 함께 주문된 단품메뉴 조합에 따라 "스카피"가 만들게 될 코스요리 메뉴 구성 후보는 다음과 같습니다.

코스 종류		메뉴 구성			설명
요리 2개 코스	A, C				1번, 2번, 4번, 6번 손님으로부터 총 4번 주문됐습니다.
요리 3개 코스	C, D, E				3번, 4번, 6번 손님으로부터 총 3번 주문됐습니다.
요리 4개 코스	B, C, F, G			1번, 5번 손님으로부터 총 2번 주문됐습니다.
요리 4개 코스	A, C, D, E			4번, 6번 손님으로부터 총 2번 주문됐습니다.
[문제]
각 손님들이 주문한 단품메뉴들이 문자열 형식으로 담긴 배열 orders, "스카피"가 추가하고 싶어하는 
코스요리를 구성하는 단품메뉴들의 갯수가 담긴 배열 course가 매개변수로 주어질 때, "스카피"가 
새로 추가하게 될 코스요리의 메뉴 구성을 문자열 형태로 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

제약 조건
* orders 배열의 크기는 2 이상 20 이하입니다.
* orders 배열의 각 원소는 크기가 2 이상 10 이하인 문자열입니다.
   - 각 문자열은 알파벳 대문자로만 이루어져 있습니다.
   - 각 문자열에는 같은 알파벳이 중복해서 들어있지 않습니다.
* course 배열의 크기는 1 이상 10 이하입니다.
   - course 배열의 각 원소는 2 이상 10 이하인 자연수가 오름차순으로 정렬되어 있습니다.
   - course 배열에는 같은 값이 중복해서 들어있지 않습니다.
* 정답은 각 코스요리 메뉴의 구성을 문자열 형식으로 배열에 담아 사전 순으로 오름차순 정렬해서 return 해주세요.
   - 배열의 각 원소에 저장된 문자열 또한 알파벳 오름차순으로 정렬되어야 합니다.
   - 만약 가장 많이 함께 주문된 메뉴 구성이 여러 개라면, 모두 배열에 담아 return 하면 됩니다.
   - orders와 course 매개변수는 return 하는 배열의 길이가 1 이상이 되도록 주어집니다.
*/

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;


// 직접 풀이:
void findCombinations(const string& s, int r, string current, int index , vector<string>& vec) {
    // 종료 조건: r 개의 문자를 선택한 경우 출력
    if (current.size() == r) {
        vec.push_back(current);
        return ;
    }

    // 문자열을 탐색하며 조합 생성
    for (int i = index; i < s.size(); i++) {
        findCombinations(s, r, current + s[i], i + 1, vec);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string, int> um;
    unordered_map<int, int> um_max;
    
    set<string> s;


    for(int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
        

        for (const int& c : course)
        {
            if (orders[i].size() == c)
            {
                s.insert(orders[i]);
                if (um.find(orders[i]) == um.end())
                {
                    
                    um[orders[i]] = 1;
                    //cout << "um[" << orders[i] << "] = 1 = " << um[orders[i]] << endl;

                    if (um_max.find(c) == um_max.end()) um_max[c] = 1;
                }
                else
                {
                    
                    um[orders[i]] += 1;
                    //cout << "um[" << orders[i] << "] += 1 = " << um[orders[i]] << endl;
                    if(um_max[c] < um[orders[i]]) um_max[c] = um[orders[i]];
                }
            }
            else if (orders[i].size() > c)
            {
               
                vector<string> vec;
                findCombinations(orders[i], c, "", 0, vec);

                for (int j = 0; j < vec.size(); j++)
                {
                    s.insert(vec[j]);
                    
                    if (um.find(vec[j]) == um.end())
                    {
                        
                        um[vec[j]] = 1;
                        //cout << "um[" << orders[i].substr(j, c) << "] = 1 =" << um[orders[i].substr(j, c)] << endl;
                        if (um_max.find(c) == um_max.end()) um_max[c] = 1;
                    }
                    else
                    {
                        um[vec[j]] += 1;
                        //cout << "um[" << orders[i].substr(j, c) << "] += 1 = " << um[orders[i].substr(j, c)] << endl;
                        if (um_max[c] < um[vec[j]]) um_max[c] = um[vec[j]];
                    }
                }
            }
        }
    }

    
    for (const string& ss : s)
    {
        //cout << "um[" << ss << "] = " << um[ss] << " um_max[" << ss.size() << "] = " << um_max[ss.size()] << endl;
        if (um[ss] > 1 && um[ss] == um_max[ss.size()])
        {
            answer.push_back(ss);
        }
    }
    return answer;
}

#include <map>

map<string, int> combi; // 주문의 조합 - 조합의 빈도

// 해설지 풀이: 코드 풀이 과정이 정렬 > 조합 > 회대 밴도 > 후보 선택 순으로 단계별로 명확한 처리.
// 실제 주문의 조합을 구하는 함수
void combination(string src, string dst, int depth) {
    if (dst.size() == depth) combi[dst]++;

    else for (int i = 0; i < src.size(); i++)
        combination(src.substr(i + 1), dst + src[i], depth);
}

vector<string> solution_commentary(vector<string> orders, vector<int> course) {
    vector<string> answer;
    // ❶ 각 주문들을 오름차순으로 정렬
    for (string& order : orders)
        sort(order.begin(), order.end());

    for (int len : course) {
        for (string order : orders)
            // ❷ course의 길이에 해당되는 조합 생성
            combination(order, "", len);

        // ❸ 각 주문의 빈도수를 순회하면서 가장 많은 빈도수를 maxOrder에 저장
        int maxOrder = 0;
        for (auto it : combi)
            maxOrder = max(maxOrder, it.second);

        // ❹ 주문 횟수가 2회 이상이면서, 가장 많이 주문된 주문의 구성은 answer에 추가
        for (auto it : combi)
            if (maxOrder >= 2 && it.second == maxOrder)
                answer.push_back(it.first);

        combi.clear();
    }
    // ❺ 반환 전, 문제의 조건에 따라 주문의 구성들을 오름차순 정렬해서 반환 
    sort(answer.begin(), answer.end());
    return answer;
}


//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>
void print(vector<string> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2, 3, 4 })); //출력값 :  AC ACDE BCFG CDE
    print(solution({ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }, { 2, 3, 5 })); //출력값 : ACD AD ADE CD XYZ
    print(solution({ "XYZ", "XWY", "WXA" }, { 2, 3, 4 })); //출력값 : WX XY 

    return 0;
}