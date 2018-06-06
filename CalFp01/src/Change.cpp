/*
 * Change.cpp
 */

#include "Change.h"

string calcChange(int m, int numCoins, int *coinValues)
{

	string res;
	vector<vector<vector<int>>> answer(m,vector<vector<int>>(numCoins, vector<int>()));
	vector<int> coins = minCoin(m, numCoins, coinValues, answer);

	for (int i = coins.size() - 1; i >= 0; --i) {
		if(coins.at(i) == 0)
			return "-";
		res.push_back('0' + coins.at(i));
		res.push_back(';');
	}
	return res;
}

vector<int> minCoin(int m, int numCoins, int *coinValues, vector<vector<vector<int>>> &answer)
{
	if(m == 0)
		return vector<int>();

	if(answer.at(m - 1).at(numCoins - 1).size() != 0)
			return answer.at(m - 1).at(numCoins - 1);

	else if(m < coinValues[numCoins - 1])
	{
		if(numCoins - 1 == 0)
			return vector<int>(1,0);
		else
			return minCoin(m , numCoins - 1, coinValues, answer);
	}
	else if(m == coinValues[numCoins - 1])
	{
		return vector<int>(1, coinValues[numCoins - 1]);
	}
	else
	{
		vector<int> sum1 = minCoin(m - coinValues[numCoins - 1], numCoins, coinValues, answer);

		if(numCoins == 1)
		{
			sum1.push_back(coinValues[numCoins - 1]);
			return sum1;
		}

		vector<int> sum2 = minCoin(m , numCoins - 1, coinValues, answer);

		//The second and third condition take into account the non-solutions that have less coins than the real
		//solutions
		if((sum1.size() < sum2.size() && sum1.at(sum1.size() - 1) != 0)  || (sum2.at(sum2.size() - 1) == 0))
		{
			sum1.push_back(coinValues[numCoins - 1]);
			answer.at(m - 1).at(numCoins - 1) = sum1;
			return sum1;
		}
		else
		{
			answer.at(m - 1).at(numCoins - 1) = sum2;
			return sum2;
		}
	}
}

