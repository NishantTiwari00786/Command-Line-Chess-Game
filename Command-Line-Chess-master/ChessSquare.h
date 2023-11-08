#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <iostream>
#include <cmath>
#include <string>
 
using namespace std;

class ChessSquare
{
    private: 
        bool occupied;
        string piece;
        string color;


    public:
        ChessSquare();
        bool isOccupied() const;
        void setOccupied(bool value);
        void setPiece(const string& pieceName);
        string getPiece() const;
        string getColor() const;
        void setColor(string s);
        void switchColor();
};
#endif