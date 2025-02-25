/*
문제 022 전화번호 목록**
링크: https://school.programmers.co.kr/learn/courses/30/lessons/42577
: 전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

구조대 : 119
박준영 : 97 674 223
지영석 : 11 9552 4421
전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

제약 조건
- phone_book의 길이는 1 이상 1,000,000 이하입니다.
- 각 전화번호의 길이는 1 이상 20 이하입니다.
- 같은 전화번호가 중복해서 들어있지 않습니다.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


// 직접 풀이 1차: O(N^3) 정확성 통 / 효율성 불통
bool solution_01(vector<string> phone_book) {
    bool answer = true;
    int n = phone_book.size();
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (phone_book[i] >= phone_book[j])
            {
                int count = 0;
                for (int k = 0; k < phone_book[j].size(); k++)
                {
                    if (phone_book[i][k] != phone_book[j][k]) break;
                    count++;
                }

                if (count == phone_book[j].size())
                {
                    answer = false;
                    break;
                }

            }
            else
            {
                int count = 0;
                for (int k = 0; k < phone_book[i].size(); k++)
                {
                    if (phone_book[i][k] != phone_book[j][k]) break;
                    count++;
                }

                if (count == phone_book[i].size())
                {
                    answer = false;
                    break;
                }
            }
        }
        if (answer == false) break;
    }
    return answer;
}


// 해설지 풀이: 정렬을 사용하고, 비교 함수를 substr을 사용하여 시간 복잡도 O(N log N) 축소
bool solution_commentary(vector<string> phoneBook) {

    std::string str = "hello";
    std::cout << str.substr(0, 10); // 🚨 std::out_of_range 예외 발생!


    //❶ 전화번호 목록을 오름차순으로 정렬
    sort(phoneBook.begin(), phoneBook.end());

    //❷ 모든 전화번호를 순회하면서 다음 번호와 비교
    for (int i = 0; i < phoneBook.size() - 1; ++i) {
        //❸ 현재 번호가 다음 번호의 접두어인 경우 false 반환
        if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size())) {
            return false;
        }
    }

    //❹ 어떤 번호도 다른 번호의 접두어가 아닌 경우 true 반환
    return true;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
    //bool 반환할 때 true는 1, false는 0 입니다.
    cout << solution_commentary({ "123", "23", "3" }) << endl; //출력값 : 0
    cout << solution_commentary({ "123", "456", "789" }) << endl; //출력값 : 1
    cout << solution_commentary({ "12", "123", "1235", "567", "88" }) << endl; //출력값 : 0

    return 0;
}