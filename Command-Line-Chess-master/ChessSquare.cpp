#include "ChessSquare.h"
#include "ChessBoard.h"
using namespace std;

ChessSquare::ChessSquare()
{
   occupied=false;
   piece=" ";
   color="";
}

bool ChessSquare::isOccupied() const
{
    return occupied;
}

void ChessSquare::setOccupied(bool value)
{
    occupied=value;
}

string ChessSquare::getPiece() const
{
    return piece;
}

string ChessSquare::getColor() const
{
    return color;
}

void ChessSquare::setColor(string s)
{
    color = s;
}

void ChessSquare::switchColor()
{
    if(color=="b")
    {
        color = "w";
    }
    else if(color=="w")
    {
        color="b";
    }
}

void ChessSquare::setPiece(const string& pieceName)
{
    piece=pieceName;
}
