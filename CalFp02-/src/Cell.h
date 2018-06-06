/*
 * Cell.h
 *
 *  Created on: 26/02/2018
 *      Author: guilherme
 */

#ifndef SRC_CELL_H_
#define SRC_CELL_H_

#include <vector>
#include <algorithm>
#include <Sudoku.h>
using namespace std;

/*
class Cell {
public:
	Cell();

	const std::vector<int>& getAccepted() const {
		return accepted;
	}

	void setAccepted(const std::vector<int>& accepted) {
		this->accepted = accepted;
	}

	int getActualValue() const {
		return actual_value;
	}

	void setActualValue(int actualValue) {
		actual_value = actualValue;
	}

	void addAccepted(int i) {
		accepted.push_back(i);
	}

	void rmAccepted(int i) {
		auto iter = find(accepted.begin(), accepted.end(), i);

		if (iter != accepted.end())
			return;
		else
			accepted.erase(iter);
	}

	Cell(Sudoku &sudo) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 1; k < 10; k++) {
				if(sudo->)
			}
		}
	}
}

private:
vector<int> accepted;
int actual_value;
pair<int, int> coord;
};

*/

#endif /* SRC_CELL_H_ */
