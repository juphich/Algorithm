#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1000000007;
int coins[100];
long dTable[5001];
int cost, kind;
int result[100];

long Coins()
{
	memset(dTable, 0, sizeof(dTable));
	for(int i = 0; i < kind; i++)
	{
		int coin = coins[i];
		if(coin > cost)
			break;

		dTable[coin]++;

		for(int j = 0; coin + j <= cost; j++)
		{
			dTable[j+coin] = (dTable[j+coin] + dTable[j]) % MAX;
		}       
	}
	return dTable[cost];
}

int main()
{
	memset(result, 0, sizeof(result));
	int cases;

	cin >> cases;
	for(int i = 0; i < cases; i++)
	{
		cin >> cost >> kind;
		for(int j = 0; j < kind; j++)
		{
			cin >> coins[j];
		}
		result[i] = Coins();
	}

	for(int i = 0; i < cases; i++)
	{
		cout << result[i] << endl;
	}
}
