/*
���� 005 ����� ����*
: 2���� ��� arr1�� arr2�� �Է¹޾�, arr1�� arr2�� ���� ����� ��ȯ�ϴ� �Լ�, solution�� �ϼ����ּ���.

���� ����
- ��� arr1, arr2�� ��� ���� ���̴� 2 �̻� 100 �����Դϴ�.
- ��� arr1, arr2�� ���Ҵ� -10 �̻� 20 ������ �ڿ����Դϴ�.
- ���� �� �ִ� �迭�� �־����ϴ�.
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


//�Ʒ� �ڵ�� �׽�Ʈ �ڵ� �Դϴ�.
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