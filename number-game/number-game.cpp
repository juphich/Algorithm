#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int MAX = 9999999;
int n, board[50], result[50];
int cache[50][50];
//-1000 -1000 -3 -1000 -1000 -1000
//100 -1000 -1000 100 -1000 -1000 1100
//7 -5 8 5 1 -4 -8 6 7 9

int NUMBERGAME(int left, int right) {
	if(left > right) 
            return 0;
	int& ret = cache[left][right];
	if(ret != MAX) 
           return ret;

	ret = max(board[left] - NUMBERGAME(left + 1, right), board[right] - NUMBERGAME(left, right - 1));
  //  cout<<"ret = "<< ret <<" left = "<< left <<" right = "<< right << endl;
	if(right - left >= 2) 
    {
		ret = max(ret, -NUMBERGAME(left + 2, right));
		ret = max(ret, -NUMBERGAME(left, right - 2));
	}
	return ret;
}

int main() {
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; ++i) 
    {
    	cin >> n;
    	for(int j = 0; j < n; j++) 
                cin >> board[j];
    	for(int j = 0; j < n; j++)
    		for(int k = 0; k < n; k++)
    			cache[j][k] = MAX;
    	
        result[i] = NUMBERGAME(0, n-1);
    }
    
    for(int i = 0; i < cases; ++i) 
    {
            cout << result[i] << endl;
    }
//    system("PAUSE");
}
