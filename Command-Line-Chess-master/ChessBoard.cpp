#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include "ChessBoard.h"
#include "ChessSquare.h"

using namespace std;

ChessBoard::ChessBoard()
{
    board.resize(8, vector<ChessSquare *>(8, nullptr));

    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)

        {
            board[row][col] = new ChessSquare();
        }
    }
}


ChessSquare *ChessBoard::getSquare(int row, int col) const
{
    if (isValidSquare(row, col))
    {
        return board[row][col];
    }
    return nullptr;
}

bool ChessBoard::isValidSquare(int row, int col) const
{
    return (row >= 0 && row < 8 && col >= 0 && col < 8);
}

void ChessBoard::setupBoard()
{
    // Set up the starting configuration of the chessboard
    // White Pieces
    board[0][0]->setPiece("R"); // Rook
    board[0][1]->setPiece("N"); // Knight
    board[0][2]->setPiece("B"); // Bishop
    board[0][3]->setPiece("Q"); // Queen
    board[0][4]->setPiece("K"); // King
    board[0][5]->setPiece("B"); // Bishop
    board[0][6]->setPiece("N"); // Knight
    board[0][7]->setPiece("R"); // Rook

    for(int i = 0; i<8; i++)
    {
        board[0][i]->setColor("w");
    }

    for (int i = 0; i < 8; ++i)
    {
        board[1][i]->setPiece("P"); // Pawn
        board[1][i]->setColor("w");
    }

    // Black Pieces
    board[7][0]->setPiece("r"); // Rook
    board[7][1]->setPiece("n"); // Knight
    board[7][2]->setPiece("b"); // Bishop
    board[7][3]->setPiece("q"); // Queen
    board[7][4]->setPiece("k"); // King
    board[7][5]->setPiece("b"); // Bishop
    board[7][6]->setPiece("k"); // Knight
    board[7][7]->setPiece("r"); // Rook
    
    for(int i = 0; i<8; i++)
    {
        board[7][i]->setColor("b");
    }

    for (int i = 0; i < 8; ++i)
    {
        board[6][i]->setPiece("p"); // Pawn
        board[6][i]->setColor("b");
    }

    // Set occupied to true for the occupied squares
    for (int col = 0; col < 8; ++col) 
    {
        for (int row = 0; row < 8; ++row) 
        {
            
            ChessSquare* square = board[col][row];
            
            if (square->getPiece() != " ") 
            {
                square->setOccupied(true);
            }
            else
            {
                square->setOccupied(false);
            }
        }
    }
}
// used stack overflow for the chess baord dimensions.

void ChessBoard::printBoard() const
{
    cout << "  0 1 2 3 4 5 6 7" << endl;

    for (int row = 0; row < 8; ++row) {
        cout << row << " ";
        for (int col = 0; col < 8; ++col) {
            ChessSquare* square = board[row][col];
            if (square->isOccupied()) {
                cout << square->getPiece() << " ";
            }
            else
            {
                cout << "- ";
            }
        }
        cout << endl;
    }
}

void ChessBoard::movePawn(int c1, int r1, int c2, int r2) //c = vertical, r = horizontal
{
    if(!isValidSquare(c1, r1) || !isValidSquare(c2, r2))
    {
        cout << "Out of bounds, try again" << endl;
        return;
    }

    if(c1==c2 && r1==r2)
    {
        cout << "Cannot move to the same spot" << endl;
        return;
    }
    
    ChessSquare* s1=getSquare(c1, r1);
    ChessSquare* s2=getSquare(c2, r2);

    if(!s1->isOccupied())
    {
        cout << "No piece to move in selected spot" << endl;
        return;
    }
    
    if(s2->isOccupied()) //possible capture, only allow for diagonal captures (c+1), (r+1)
    {
        if(s1->getColor() == s2->getColor())
        {
            cout << "cannot capture your own piece" << endl;
            return;
        }
        
        cout << "capturing" << endl;

        if((abs(c2-c1)==1) && (abs(r2-r1)==1)) //diagonal capture
        {
            s2->switchColor();
            s2->setPiece(s1->getPiece());
            s1->setOccupied(false);
            s1->setColor("");
            s1->setPiece(" ");
        }
        else
        {
            cout << "Can only capture diagonally. try again. " << endl;
        }
    }
    else //moving
    {
        if(r1 != r2) //only allows vertical moves that dont capture
        {
            cout << "Pawns cannot move horizontally without capturing a piece." << endl;
            return;
        }

        s2->setPiece(s1->getPiece());
        s1->setPiece(" ");
        s1->setOccupied(false);
        s2->setOccupied(true);
    }
}
void ChessBoard::moveKnight(int oldx, int oldy, int newx, int newy) {
    ChessSquare* oldSquare = getSquare(oldx, oldy);
    ChessSquare* newSquare = getSquare(newx, newy);

    if (!oldSquare->isOccupied()) {
        throw std::invalid_argument("Invalid move, try again");
    }

    // Check for valid knight movement
    int dx = abs(newx - oldx);
    int dy = abs(newy - oldy);
    if (!((dx == 1 && dy == 2) || (dx == 2 && dy == 1))) {
        throw std::invalid_argument("Invalid move, try again");
    }

    // Check if the destination square is occupied by a piece of the same color
    if (newSquare->isOccupied() && (tolower(newSquare->getPiece()[0]) == tolower(oldSquare->getPiece()[0]))) {
        throw std::invalid_argument("Invalid move, try again");
    }

    // Check if the destination square is occupied by a piece of the opposite color
    if (newSquare->isOccupied() && (tolower(newSquare->getPiece()[0]) != tolower(oldSquare->getPiece()[0]))) {
        cout << "Capturing " << newSquare->getPiece() << endl;
    }

    // Move the knight to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
   board[newy][newx]->setPiece(newSquare->getPiece());
    board[newy][newx]->setOccupied(true);
}



void ChessBoard::moveBishop(int oldx, int oldy, int newx, int newy)
{
    ChessSquare* oldSquare = getSquare(oldx, oldy);
    ChessSquare* newSquare = getSquare(newx, newy);

    if (!oldSquare->isOccupied() || newSquare->isOccupied())
    {
        if (isupper(oldSquare->getPiece()[0]) == isupper(newSquare->getPiece()[0]))
        {
            throw std::invalid_argument("Invalid move, try again");
        }
    }

    // Check for valid bishop movement
    if (abs(oldx - newx) != abs(oldy - newy))
    {
        throw std::invalid_argument("Invalid move, try again");
    }

    // Check if the destination square is occupied by a piece of the opposite color
    if (newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) != isupper(newSquare->getPiece()[0]))
    {
        cout << "Capturing " << newSquare->getPiece() << endl;
    }

    // Move the bishop to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece(newSquare->getPiece());
    board[newy][newx]->setOccupied(true);

    cout << endl<< "Bishop moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl  << endl;
}

void ChessBoard::moveQueen(int oldx, int oldy, int newx, int newy)
{
    ChessSquare* oldSquare = getSquare(oldx, oldy);
    ChessSquare* newSquare = getSquare(newx, newy);

  if (!oldSquare->isOccupied() || newSquare->isOccupied())
{
    if (isupper(oldSquare->getPiece()[0]) == isupper(newSquare->getPiece()[0]))
    {
        throw std::invalid_argument("Invalid move, try again");
    }
}

    // Check for valid queen movement
    if (oldx != newx && oldy != newy && abs(oldx - newx) != abs(oldy - newy))
    {
        throw std::invalid_argument("Invalid move, try again");
    }

    // Check if the destination square is occupied by a piece of the opposite color
    if (newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) != isupper(newSquare->getPiece()[0]))
    {
        cout << "Capturing " << newSquare->getPiece() << endl;
    }

    // Move the queen to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
board[newy][newx]->setPiece(newSquare->getPiece());
    board[newy][newx]->setOccupied(true);

    cout << endl
         << "Queen moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl
         << endl;
}




void ChessBoard::moveKing(int oldx, int oldy, int newx, int newy)
{
    ChessSquare* oldSquare = getSquare(oldx, oldy);
    ChessSquare* newSquare = getSquare(newx, newy);

    if (!oldSquare->isOccupied() || newSquare->isOccupied())
    {
        if (isupper(oldSquare->getPiece()[0]) == isupper(newSquare->getPiece()[0]))
        {
            throw std::invalid_argument("Invalid move, try again");
        }
    }

    // Check for valid king movement
    if (abs(oldx - newx) > 1 || abs(oldy - newy) > 1)
    {
        throw std::invalid_argument("Invalid move, try again");
    }

    // Check if the destination square is occupied by a piece of the opposite color
    if (newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) != isupper(newSquare->getPiece()[0]))
    {
        cout << "Capturing " << newSquare->getPiece() << endl;
    }

    // Move the king to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
   board[newy][newx]->setPiece(newSquare->getPiece());
    board[newy][newx]->setOccupied(true);

    cout << endl
         << "King moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl
         << endl;
}
