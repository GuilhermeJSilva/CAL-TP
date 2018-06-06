/*
 * Change.h
 */

#ifndef CHANGE_H_
#define CHANGE_H_

#include "Defs.h"

/* Calcula o troco num determinado montante m, utilizando um n�mero m�nimo
 * de moedas de valores unit�rios indicados (coinValues).
 * O array coinValues deve estar ordenado por ordem crescente.
 * O par�metro numCoins indica o tamanho do array.
 * Devolve:
 * Uma string com a sequ�ncia de valores das moedas por valores decrescente.
 * Por exemplo: calcChange(9, 3, {1, 2, 5}) = "5;2;2;"
 * */
string calcChange(int m, int numCoins, int *coinValues);

vector<int> minCoin(int m, int numCoins, int *coinValues, vector<vector<vector<int>>> &answer);

#endif /* CHANGE_H_ */
