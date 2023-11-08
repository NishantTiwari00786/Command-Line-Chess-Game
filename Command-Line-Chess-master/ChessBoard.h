#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "ChessSquare.h"


class ChessBoard
{
  private:
    vector<vector<ChessSquare*>> board;
  public:
    ChessBoard();
    ChessSquare* getSquare(int row, int col) const;
    bool isValidSquare(int row, int col) const;
    void setupBoard();
    void printBoard() const;
    void movePawn(int oldx, int oldy, int newx, int newy);
    void moveQueen(int oldx, int oldy, int newx, int newy);
    void moveRook(int oldx, int oldy, int newx, int newy);
    void moveKnight(int oldx, int oldy, int newx, int newy);
    void moveBishop(int oldx, int oldy, int newx, int newy);
    void moveKing(int oldx, int oldy, int newx, int newy);
    

};

#endif