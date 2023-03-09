#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6;
double arr[10][MAX];
void quickSort(int index, int left, int right) 
{
    if (left >= right) 
        return;
    double pivot = arr[index][(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (arr[index][i] < pivot) {
            i++;
        }
        while (arr[index][j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[index][i], arr[index][j]);
            i++;
            j--;
        }
    }
    quickSort(index, left, j);
    quickSort(index, i, right);
}
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
		quickSort(i, 0, MAX - 1);
		// for (int j = 0; j < 10; ++j)
		// {
		// 	cout<<arr[i][j]<<' ';
		// }
		// cout<<endl;
		double duration = ((clock() - start ) / (double) CLOCKS_PER_SEC);
		cout << "Time for array "<<i<<": "<<duration<<"s\n";
	}
    return 0;
}
