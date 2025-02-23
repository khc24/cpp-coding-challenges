/*
문제 005 행렬의 곱셈*
: 2차원 행렬 arr1과 arr2를 입력받아, arr1에 arr2를 곱한 결과를 반환하는 함수, solution을 완성해주세요.

제약 조건
- 행렬 arr1, arr2의 행과 열의 길이는 2 이상 100 이하입니다.
- 행렬 arr1, arr2의 원소는 -10 이상 20 이하인 자연수입니다.
- 곱할 수 있는 배열만 주어집니다.
*/

#include <vector>

using namespace std;


vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	int arr1_r = arr1.size();
	int arr1_c = arr1[0].size();

	int arr2_r = arr2.size();
	int arr2_c = arr2[0].size();

	vector <vector<int>> answer(arr1_r, vector<int>(arr2_c, 0));

	for(int a=0;a< arr1_r;a++)
		for(int b=0;b< arr2_c;b++)
			for (int c = 0;c < arr1_c; c++) answer[a][b] += arr1[a][c] * arr2[c][b];
			
	return answer;
}


//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>
void print2D(vector<vector<int>> vec)
{
    for (const auto& innerVec : vec) {
        copy(innerVec.begin(), innerVec.end(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    cout << endl;
}

int main()
{
    print2D(solution({ {1, 4}, {3, 2}, {4, 1} }, { {3, 3}, {3,3} }));
    /*
      15 15
      15 15
      15 15
    */
    print2D(solution({ {2, 3, 2}, {4, 2, 4}, {3, 1,4} }, { {5, 4, 3}, {2, 4, 1}, {3, 1, 1} }));     // 1 2 3 
    /*
      22 22 11
      36 28 18
      29 20 14
    */

    return 0;
}