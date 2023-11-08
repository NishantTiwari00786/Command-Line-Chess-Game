#include "ChessSquare.h"
#include "ChessBoard.h"

int main()
{
<<<<<<< HEAD
    ChessBoard board;
    bool cont = true;
    string turn = "w";
    string movingPiece;
    string move;

    board.setupBoard();
    board.printBoard();
=======

    ChessBoard chessBoard;
    chessBoard.setupBoard();
    chessBoard.printBoard();

   

>>>>>>> master

    int x1, y1, x2, y2;

    while(cont)
    {
        cout <<  "\nEnter your move as a 4 digit string of ints: " << endl << endl;
        cin>>move;
        x1 = stoi(move.substr(0,1));
        y1 = stoi(move.substr(1,1));
        x2 = stoi(move.substr(2,1));
        y2 = stoi(move.substr(3,1));

        board.movePawn(x1, y1, x2, y2);

        board.printBoard();
    }

    return 0;
}


