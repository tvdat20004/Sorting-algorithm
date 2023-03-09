#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6;
double arr[10][MAX];
int main()
{
	clock_t start;
	freopen("text.inp","r",stdin);
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			cin>>arr[i][j];
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		start = clock();
		sort(arr[i], arr[i] + MAX);
		// for (int j = 0; j < 10; ++j)
		// {
		// 	cout<<arr[i][j]<<' ';
		// }
		// cout<<endl;
		double duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
		cout << "Time for array "<<i<<": "<< duration<<"s\n";
	}
    return 0;
}