#include <iostream>
#include <vector>

using namespace std;

int solution(vector< vector<int> > &A) {
	// write your code in C++11
	vector<int> row_sum;
	vector<int> col_sum;
	vector<int> row_find;
	vector<int> col_find;

	int n = A.size()-1;
	int m = A[0].size() - 1;
	for (int i = 0; i <= n; i++)
	{
		int sum = 0;
		for (int k = 0; k <= m; k++)
		{
			sum = sum + A[i][k];

		}
		row_sum.push_back(sum);
	}

	//
	for (int i = 0; i <= m; i++)
	{
		int sum = 0;
		for (int k = 0; k <= n; k++)
		{
			sum = sum + A[k][i];

		}
		col_sum.push_back(sum);
	}

	for (int i = 1; i <= n-1; i++)
	{
		int bef = 0;
		int aft = 0;
		for (int p = 0; p < i; p++)
		{
			bef = bef + row_sum[p];

		}
		for (int p = i+1; p <= n; p++)
		{
			aft = aft + row_sum[p];
		}
		if (bef == aft)
		{
			row_find.push_back(i);
		}
	}
	//
	for (int i = 1; i <= m - 1; i++)
	{
		int bef = 0;
		int aft = 0;
		for (int p = 0; p < i; p++)
		{
			bef = bef + col_sum[p];

		}
		for (int p = i + 1; p <= m; p++)
		{
			aft = aft + col_sum[p];
		}
		if (bef == aft)
		{
			col_find.push_back(i);
		}
	}
	
	return col_find.size()*row_find.size();
}
