#include <iostream>
#include <cstring>

using namespace std;

int poly(int, int);
const int MAX = 10000000;	//나눌 값 저장
int TEST[50];	//테스트 값 저장 1<= n <= 50
int TEMP[100][100]; //결과값 저장하기 1 <= n <= 100

int main()
{
	memset(TEST, -1, sizeof(TEST));
	memset(TEMP, -1, sizeof(TEMP));
	
	int cases;
	cin >> cases;
	//테스트 케이스
	for(int i = 0; i < cases; i++)
	{
		cin >> TEST[i]; //입력
	}
	//출력
	for(int i = 0; i < cases; i++)
	{
		int result = 0;
		for(int j = 0; j < TEST[i]; j++)	//가장 윗줄 갯수 하나씩 증가
		{
			result += poly(TEST[i], j+1);
		}
		result %= MAX;	//천만으로 나누기
		cout << result << endl;
	}
}
//n 전체갯수
//top 맨윗줄의 갯수
int poly(int n, int top)
{
	if(n == top)
		return 1;

	int& result = TEMP[n-1][top-1];

	if(result != -1)	//기존의 한 결과 값이 있을 경우 리턴
		return result;
	
	result = 0;

	for(int i = 1; i <= n-top; i++)
	{
		int add = i + top - 1;//윗줄에 있는 사각형
		add *= poly(n - top, i); // 윗줄 사각형에 따라 붙는 갯수 *
		add %= MAX;	//천만으로 나누기 int 최대값 초과
		result += add;
		result %= MAX;	//천만으로 나누기 값초과
	}
	return result;
}
