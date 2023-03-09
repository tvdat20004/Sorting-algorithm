#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6;
double arr[10][MAX];
void merge(int index, int mid, int l, int r)
{
	vector<double> subArr1,subArr2;
	for (int i = l; i <= r; ++i)
	{
		if (i <= mid) subArr1.push_back(arr[index][i]);
		else subArr2.push_back(arr[index][i]);
	}
	int idx1 = 0, idx2 = 0, idx = l; 
	while(idx1 != subArr1.size() && idx2 != subArr2.size())
	{
		if (subArr1[idx1] >= subArr2[idx2]) 
		{
			arr[index][idx] = subArr2[idx2];
			idx2++;
		}
		else 
		{
			arr[index][idx] = subArr1[idx1];
			idx1++;
		}
		idx++;
	}
	while (idx1 < subArr1.size()) 
	{
        arr[index][idx] = subArr1[idx1];
        idx1++;
        idx++;
    }
    while (idx2 < subArr2.size()) 
    {
        arr[index][idx] = subArr2[idx2];
        idx2++;
        idx++;
    }
}
void merge_sort(int index, int l, int r)
{
	if (l >= r) return;
	int mid = (l + r)/2;
	merge_sort(index, l, mid);
	merge_sort(index, mid + 1, r);
	merge(index, mid, l, r);
}
int main()
{
    vector <double> duration;
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
		clock_t start = clock();
		merge_sort(i, 0, MAX - 1);
		// for (int j = 0; j < 10; ++j)
		// {
		// 	cout<<arr[i][j]<<' ';
		// }
		//cout<<endl;
		double duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
		cout << "Time for array "<<i<<": "<<duration<<"s\n";
	}
    return 0;
}