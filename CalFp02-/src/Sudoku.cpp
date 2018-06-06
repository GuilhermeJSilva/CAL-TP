/*
 * Sudoku.cpp
 *
 */

#include "Sudoku.h"
#include <vector>
#include <string.h>
#include <climits>

/** Inicia um Sudoku vazio.
 */
Sudoku::Sudoku()
{
	this->initialize();
	this->n_solucoes = 0;
	this->countFilled = 0;
}

/**
 * Inicia um Sudoku com um conte�do inicial.
 * Lan�a excep��o IllegalArgumentException se os valores
 * estiverem fora da gama de 1 a 9 ou se existirem n�meros repetidos
 * por linha, coluna ou bloc 3x3.
 *
 * @param nums matriz com os valores iniciais (0 significa por preencher)
 */
Sudoku::Sudoku(int nums[9][9])
{
	this->initialize();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (nums[i][j] != 0)
			{
				int n = nums[i][j];
				numbers[i][j] = n;
				lineHasNumber[i][n] = true;
				columnHasNumber[j][n] = true;
				block3x3HasNumber[i / 3][j / 3][n] = true;
				countFilled++;
			}
		}
	}
	this->n_solucoes = 0;
}

void Sudoku::initialize()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int n = 0; n < 10; n++)
			{
				numbers[i][j] = 0;
				lineHasNumber[i][n] = false;
				columnHasNumber[j][n] = false;
				block3x3HasNumber[i / 3][j / 3][n] = false;
			}
		}
	}

	this->countFilled = 0;
}

/**
 * Obtem o conte�do actual (s� para leitura!).
 */
int** Sudoku::getNumbers()
{
	int** ret = new int*[9];

	for (int i = 0; i < 9; i++)
	{
		ret[i] = new int[9];

		for (int a = 0; a < 9; a++)
			ret[i][a] = numbers[i][a];
	}

	return ret;
}

/**
 * Verifica se o Sudoku j� est� completamente resolvido
 */
bool Sudoku::isComplete()
{
	return countFilled == 9 * 9;
}



/**
 * Resolve o Sudoku.
 * Retorna indica��o de sucesso ou insucesso (sudoku imposs�vel).
 */
bool Sudoku::solve()
{

	//this->print();
	//cout << endl;

	if(countFilled == 81)
	{
		this->print();
		cout << endl;
		n_solucoes++;
		return true;
	}

	int x ,y;
	int n_accepted = INT_MAX;
	vector<bool> num_accepted;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int tmp_n_accepted = 9;
			vector<bool> acceptable_num(10,true);
			if(this->numbers[i][j] != 0)
				continue;
			for(int k = 0; k < 10; k++)
			{
				acceptable_num[k] = acceptable_num[k] & !this->columnHasNumber[j][k];
				acceptable_num[k] = acceptable_num[k] & !this->lineHasNumber[i][k];
				acceptable_num[k] = acceptable_num[k] & !this->block3x3HasNumber[i/3][j/3][k];
				if(!acceptable_num[k])
					tmp_n_accepted--;
			}
			//cout << "x: " << i << " y: " << j << endl;
			//cout << tmp_n_accepted << ' ' << n_accepted << endl;

			if(tmp_n_accepted == 0)
				return false;

			if(tmp_n_accepted <= n_accepted)
			{
				n_accepted = tmp_n_accepted;
				num_accepted.clear();
				num_accepted.insert(num_accepted.begin(),acceptable_num.begin(), acceptable_num.end());
				x = i;
				y = j;
			}

		}
	}

	if(n_accepted == 1)
	{
		int a = 1;
		while(!num_accepted[a])
			a++;
		//cout << "Added: " << a << " in x: " << x << " y: " << y << endl << endl;
		this->numbers[x][y] = a;
		this->countFilled++;
		lineHasNumber[x][a] = true;
		columnHasNumber[y][a] = true;
		block3x3HasNumber[x / 3][y / 3][a] = true;

		if(this->solve())
		{
			return true;
		}
		else
		{
			this->numbers[x][y] = 0;
			this->countFilled--;
			lineHasNumber[x][a] = false;
			columnHasNumber[y][a] = false;
			block3x3HasNumber[x / 3][y / 3][a] = false;
			return false;
		}

	}
	else
	{
		//cout << x << "\t" << y << "\n";
		std::vector<int> possible_sol;
		for(int i = 1; i < 10; i++)
			if(num_accepted[i])
			{
				//cout << i << " acceptated\n";
				possible_sol.push_back(i);
			}

		for(size_t j = 0; j < possible_sol.size(); j++)
		{
			//cout << "Added: " << possible_sol[j] << " in x: " << x << " y: " << y << endl << endl;
			this->numbers[x][y] = possible_sol[j];
			this->countFilled++;
			lineHasNumber[x][possible_sol[j]] = true;
			columnHasNumber[y][possible_sol[j]] = true;
			block3x3HasNumber[x / 3][y / 3][possible_sol[j]] = true;
			if(this->solve())
			{
				return true;
			}
			else
			{
				this->numbers[x][y] = 0;
				this->countFilled--;
				lineHasNumber[x][possible_sol[j]] = false;
				columnHasNumber[y][possible_sol[j]] = false;
				block3x3HasNumber[x / 3][y / 3][possible_sol[j]] = false;
			}
		}
	}

	return false;
}



/**
 * Imprime o Sudoku.
 */
void Sudoku::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int a = 0; a < 9; a++)
			cout << this->numbers[i][a] << " ";

		cout << endl;
	}
}
