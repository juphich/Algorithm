#include <iostream>
#include <cstring>

using namespace std;
//테스트 케이스 50
//입력 갯수 500
//부분 수열
//순수열일 때 가장 긴 수
int value[500];
int rvalue[500];
int result[50];	//결과값 저장
int main()
{
	memset(result, 0, sizeof(result));
	int cases;
	cin >> cases;

	for(int m = 0; m < cases; m++)
	{
		memset(value, 0, sizeof(value));
		memset(rvalue, 0, sizeof(rvalue));
		int max = 1;
		int n;
		cin >> n;

		for(int i = 0; i < n; i++)
		{
			cin >> value[i];
		}

		rvalue[0] = value[n-1];

		for(int i = 2; i <= n; i++)
		{
			for(int j = 1; j <= max; j++)
			{
//				cout<< value[n-i] <<"  " << rvalue[max-j] << endl;
				if(value[n-i] < rvalue[max-j])	//현재 값이 클 경우
				{
					int temp;
//					cout<< rvalue[max-j+1] <<" < " << value[n-i] << endl;
					if(rvalue[max-j+1] < value[n-i])
						rvalue[max-j+1] = value[n-i];
					temp = max - j + 2;
					if(max < temp)
						max = temp;
					break;
				}
				else if((max-j) == 0 && (value[n-i] > rvalue[0]))
				{
					rvalue[0] = value[n-i];
				}
			}
		}
		result[m] = max;
	
	}

	for(int m = 0; m < cases; m++)
	{
		cout << result[m] << endl;
	}
}
