#pragma once
#include <stdlib.h>
#include <iostream>
#include<ctime>
#include <cstdlib>
#include<Windows.h>
#include<iomanip>



using namespace std;

int board[4][4];
int dirLine[] = { 1, 0, -1, 0 };
int dirColumn[] = { 0,1,0,-1 };


bool canDoMove(int line, int column, int nextline, int nextColumn)

{

	if (nextline < 0 || nextColumn < 0 || nextline >= 4 || nextColumn >= 4 ||
		(board[line][column] != board[nextline][nextColumn] && board[nextline][nextColumn] != 0))


		return false;

	return true;




}


pair<int, int> generateUnoccupiedPosition() {
	int occupied = 1, line, column;
	while (occupied) {
		line = rand() % 4;
		 column = rand() % 4;
		 if (board[line][column] == 0)
			 occupied = 0;
	}

	return make_pair(line, column);
}
void addPiece() {
	pair<int, int>pos = generateUnoccupiedPosition();
	board[pos.first][pos.second] = 2;
}


void game() {
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			board[i][j] = 0;
		}
	
		addPiece();

	}
}
void printUI() 
{
	system("cls");
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; ++j)

			if (board[i][j] == 0)

		cout <<setw(4)<< ".";


			else

				cout << setw(4) << board[i][j];

		cout << "\n";
	}
	
		
		cout << "n:Новая игра, w:Вверх, a:Влево, s:Вниз, d:Вправо ,q:Выйти";
}

void applyMove(int direction) {
	int StartLine = 0, startColumn = 0, lineStep = 1, columnStep = 1;
	if (direction == 0) {

		StartLine = 3;
		lineStep = -1;
	}
	if (direction == 1) {
		startColumn = 3;
		columnStep = -1;
	}
	int movePossible = 0, CanAddPiece = 0;
	do {
	for (int i = StartLine; i >= 0 && i < 4; i += lineStep)
	{
		
			movePossible = 0;
			for (int j = startColumn; j >= 0 && j < 4; j += columnStep)
			{
				int nextI = i + dirLine[direction], nextJ = j + dirColumn[direction];

				if (board[i][j]&&canDoMove(i, j, nextI, nextJ)) {
					board[nextI][nextJ] += board[i][j];
					board[i][j] = 0;
					movePossible = CanAddPiece=1;

				}
			}

		printUI();
	}
		}
			
			while (movePossible);
			if (CanAddPiece)
				addPiece();
		
}



