#include "Partitioning.h"
/*
 * Partioning.cpp
 */



int s_recursive(int n,int k)
{
	if(n == k || k == 1)
		return 1;
	else
	{
		return s_recursive(n - 1, k - 1) + k*s_recursive(n - 1, k);
	}
}

int s_dynamic(int n,int k)
{
	vector<int> initArray(n - k  + 1, 1);

	for(int i = 2; i  <= k; i++)
	{
		for(size_t j = 1 ; j < initArray.size(); j++)
		{
			initArray.at(j) += initArray.at(j - 1) * i;
		}
	}
	return initArray.at(initArray.size() - 1);
}


int s_dynamic(int n,int k, vector< vector<int> > &res)
{
	vector<int> initArray(n - k  + 1, 1);
	res.push_back(initArray);
	for(int i = 2; i  <= k; i++)
	{
		for(size_t j = 1 ; j < initArray.size(); j++)
		{
			initArray.at(j) += initArray.at(j - 1) * i;
		}
		res.push_back(initArray);
	}
	return initArray.at(initArray.size() - 1);
}

int b_recursive(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += s_recursive(n, i);
	}
	return sum;
}

/**
 * Constructs a table with all the values it needs, by calculating a higher value of S(n,k), then
 * gets the numbers it needs from that table
 */
int b_dynamic(int n)
{
	if(n == 1 || n == 2)
		return n;

	vector< vector<int> > res;
	s_dynamic(2 * n - 3, n - 1, res);

	/*
	for (size_t i = 0; i < res.size(); ++ i) {
		for (size_t j = 0; j < res.at(i).size(); ++j) {
			cout << res.at(i).at(j) << "\t";
			}
		cout << endl;
	}
	cout << endl;
	*/

	int sum = 2;
	for (int i = 2; i < n; ++i) {
		sum += res.at(i - 1).at(n - i);
	}
	return sum;
}


