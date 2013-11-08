#include <iostream>

using namespace std;
int Clocks[30][16];
const int Max = 10;
const int switches[10][16]= { 
	{3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 3, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 0},
	{0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 3},
	{3, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 3, 0, 3, 0, 0, 0},
	{3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
	{0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
	{0, 0, 0, 0, 3, 3, 0, 3, 0, 0, 0, 0, 0, 0, 3, 3},
	{0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 3, 3, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0}};


bool Check(int* clocks)
{
	for (int i = 0; i < 16; i++ )
	{
		if (clocks[i] != 12 )
			return false;
	}
	return true;
}

int ClockSync(int* clocks, int count)
{
	if(Check(clocks))
		return 0;

	if(count == 10)			//10가지 스위치
		return 1048577;

	int min = 1048577;
	for(int i = 0; i < 4; i++)		//4바퀴를 돌면 원래로 복귀
	{
		int a = ClockSync(clocks, count+1);
		if(min > a+i)
			min = a+i;
		for (int j = 0 ; j < 16; j++)
		{
			clocks[j] = clocks[j] + switches[count][j];
			if ( clocks[j] == 15 )
				clocks[j] = 3;
		}
	}

	return min;
}

int main()
{
	int cases;
	cin >> cases;

	for(int i = 0; i < cases; i++)
	{
		for(int j = 0; j < 16; j++){
			cin >> Clocks[i][j];
		}
	}
	for(int i = 0; i < cases; i++)
	{
		int result = ClockSync(Clocks[i], 0);	
		
		if(result == 1048577)
			cout<<-1<<endl;
		else
		cout<<result<<endl;
	}
}
