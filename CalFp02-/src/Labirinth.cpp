/*
 * labirinth.cpp
 */

#include "Labirinth.h"

#include <iostream>
using namespace std;



Labirinth::Labirinth(int values[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			labirinth[i][j]=values[i][j];
			visited[i][j]=false;
		}
	this->foundTheSolution = false;
}


void Labirinth::initializeVisited(int x, int y)
{
	for (int i = 0; i < 10; i++)
		for (int a = 0; a < 10; a++)
			visited[i][a] = false;
	visited[y][x] = true;
}




void  Labirinth::printLabirinth()
{
	for (int i = 0; i < 10; i++)
	{
		for (int a = 0; a < 10; a++)
			cout << labirinth[i][a] << " ";

		cout << endl;
	}
}


bool Labirinth::findGoal(int x, int y)
{
	if(this->visited[x][y] || this->labirinth[x][y] == 0)
		return false;

	if(this->labirinth[x][y] == 2)
	{
		this->foundTheSolution = true;
		return true;
	}

	this->visited[x][y] = true;

	if(x - 1 >= 0 && this->findGoal(x - 1, y))
		return true;
	if(y + 1 <= 10 && this->findGoal(x, y + 1))
		return true;
	if(x + 1 <= 10 && this->findGoal(x + 1, y))
		return true;
	if(y - 1 >= 0 && this->findGoal(x, y - 1))
		return true;

	return false;
}


