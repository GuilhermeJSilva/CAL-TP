/*
 * Sum.cpp
 */

#include "Sum.h"
#include <stdio.h>
#include <limits.h>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <numeric>


string calcSum(int* sequence, int size)
{
	vector<int> seque(sequence, sequence + size);
	vector<pair<int, int>> answer(size - 1, pair<int, int>(0,INT_MAX));
	vector<vector<bool>> calculated(size, vector<bool>(size, false));
	int sum = 0;

	for(size_t i = 0; i < seque.size(); i++)
	{
		sum += seque.at(i);
	}

	answer.push_back(pair<int,int>(0, sum));
	calSum(seque, 0, seque.size(), sum, answer, calculated);

	//Convert to apropeiate string
	stringstream str_stream;

	for(size_t i = 0; i < answer.size(); i++)
	{
		str_stream << answer.at(i).second << ',' << answer.at(i).first << ';';
	}
	return str_stream.str();
}

void calSum(vector<int> &sequence, int index, int m, int sumM, vector<pair<int, int>> &answer, vector<vector<bool>> &calculated)
{
	if(calculated.at(index).at(m - 1))
		return;

	if(answer.at(m - 1).second > sumM)
		answer.at(m - 1) = pair<int,int>(index, sumM);

	calculated.at(index).at(m - 1) = true;
	if(m == 1)
		return;

	calSum(sequence, index, m - 1, sumM - sequence.at(index + m - 1), answer, calculated);

	if(index != (int)(sequence.size() - 1))
		calSum(sequence, index + 1, m - 1, sumM - sequence.at(index), answer, calculated);

}

void testCalcSum(string filename)
{
	ofstream oStream(filename.c_str());

	if(oStream.is_open())
	{
		for(int i = 10; i <= 500; i += 10)
		{
			unsigned long long  time = 0;
			int sequence[500];

			for(int k = 0; k < 100; k++)
			{
				printf("Iteration: %d %d.\n", i, k);
				for(int j = 0; j < i; j++)
					sequence[i] = rand() % (10 * i);


				auto start = std::chrono::high_resolution_clock::now();
				printf("Starting: %d %d.\n", i ,k);
				calcSum(sequence, i);
				printf("Ending: %d %d.\n\n", i ,k);
				auto finish = std::chrono::high_resolution_clock::now();

				auto mili = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
				time +=  (unsigned long long)mili;
			}
			oStream << i << '\t' << time << endl;
		}

	}
	else
	{
		printf("Failed to open\n");
	}
	oStream.close();
}
