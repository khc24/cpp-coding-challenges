/*
문제 012 주식 가격**
링크: https://school.programmers.co.kr/learn/courses/30/lessons/42584
: 초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

제약 조건
- prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
- prices의 길이는 2 이상 100,000 이하입니다.
*/

#include <vector>
#include <stack>

using namespace std;


// 직접 풀이 01: 시간 복잡도 O(N^2)
vector<int> solution_01(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (prices[i] > prices[j])
            {
                answer[i] += 1;
                break;
            }
            else
            {
                answer[i] += 1;
            }
        }
    }
    return answer;
}

// 직접 풀이 02:시간 복잡도 O(N)
vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty())
        {
            if (prices[st.top()] <= prices[i])
            {
                break;
            }
            else
            {
                answer[st.top()] = i - st.top();
                st.pop();
            }
        }

        st.push(i);
    }

    while (!st.empty())
    {
        answer[st.top()] = n - st.top() - 1;
        st.pop();
    }

    return answer;
}

// 해설지 풀이 : 불필요한 if-else 분기 제거
vector<int> solution_commentary(vector<int> prices) {
    //❶ 가격이 떨어지지 않은 기간을 저장한 벡터    
    vector<int> answer(prices.size());
    // 스택에는 prices의 인덱스가 들어감, 이전 가격과 현재 가격을 비교하기 위한 용도로 사용됨  
    stack<int> s;

    int priceNum = prices.size();

    for (int i = 0; i < priceNum; i++) {
        while (!s.empty() && prices[s.top()] > prices[i]) {
            //❷ 가격이 떨어졌으므로 이전 가격의 기간 계산 
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    //❸ 스택에 남아있는 가격들은 가격이 떨어지지 않은 경우
    while (!s.empty()) {
        answer[s.top()] = priceNum - s.top() - 1;
        s.pop();
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
    print(solution({ 1, 2, 3, 2, 3 })); // 4 3 1 1 0
    return 0;

}