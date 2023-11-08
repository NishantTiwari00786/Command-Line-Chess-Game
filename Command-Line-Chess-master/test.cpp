#include "gtest/gtest.h"
#include "ChessBoard.h"
#include "ChessSquare.h"

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

// check if move is valid (moves the function)
//for bishop tests, took help from ta and used stack overflow
TEST(ChessBoardTest, pawnTest1)
{
    ChessBoard b;
    b.setupBoard();
    b.movePawn(1, 1, 2, 1);
    EXPECT_TRUE(b.getSquare(2, 1)->getPiece()=="P");
}

TEST(ChessBoardTest, pawnTest2)
{
    ChessBoard b;
    b.setupBoard();
    b.movePawn(6, 0, 5, 0);
    EXPECT_TRUE(b.getSquare(5, 0)->getPiece()=="p");
}

TEST(ChessBoardTest, pawnTest3)
{
    ChessBoard b;
    b.setupBoard();
    EXPECT_FALSE(b.isValidSquare(-1, 2));
}

TEST(ChessBoardTest, Bishop_Move_test)
{
	ChessBoard chess_board;
	chess_board.setupBoard();
	//test to check if bishop moves from one place to another accurately 
	chess_board.getSquare(1, 1)->setPiece("B");
	EXPECT_NO_THROW(chess_board.moveBishop(1, 1, 3, 3));
	 
}

TEST(ChessBoardTest, IsBishop_initialpos_valid)
{
	//test to check if bishop initial pos at board is placed accurately which is 3,0
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_FALSE(chess_board.getSquare(3, 0)->isOccupied());
}



TEST(ChessBoardTest, IsBishopMove_valid)
{
		//wrong coordinates to check if bishop moves without following the rules
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_THROW(chess_board.moveBishop(2, 0, 2, 2), std::invalid_argument);
}



TEST(ChessBoardTest, IsBishopMovesandCaptures_test)
{
	//this test basically checks logical accuracy of whole program
	//firstly bishop is placed at 1,1 and pawn is placed 3,3
	//then bishop moves to 3,3 and captures the pawn
	ChessBoard chess_board;

	chess_board.getSquare(1, 1)->setPiece("B");
	chess_board.getSquare(1, 1)->setOccupied(true);
	chess_board.getSquare(3, 3)->setPiece("p");
	chess_board.getSquare(3, 3)->setOccupied(true);
	EXPECT_NO_THROW(chess_board.moveBishop(1, 1, 3, 3));

	ChessSquare* newSquare = chess_board.getSquare(3, 3); // ADDED
    EXPECT_TRUE(newSquare->isOccupied());
    EXPECT_EQ(newSquare->getPiece(), "B");
}


TEST(ChessBoardTest, Queen_Valid)
{ // VALID QUEEN MOVEMENT
    ChessBoard chess_board;
    chess_board.setupBoard();

    chess_board.getSquare(3, 3)->setPiece("Q");
    EXPECT_NO_THROW(chess_board.moveQueen(3, 3, 3, 4));

    // Verify that the queen has moved to the new position
    ChessSquare* newSquare = chess_board.getSquare(3, 4);
    EXPECT_TRUE(newSquare->isOccupied());
    EXPECT_EQ(newSquare->getPiece(), "Q");

    // Verify that the old position is now unoccupied
    ChessSquare* oldSquare = chess_board.getSquare(3, 3);
    EXPECT_FALSE(oldSquare->isOccupied());
    EXPECT_EQ(oldSquare->getPiece(), " ");
}
TEST(ChessBoardTest, Queen_Invalid)
{
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(3, 0)->setPiece("Q");
	EXPECT_THROW(chess_board.moveQueen(3, 0, 2, 4), std::invalid_argument);
}

TEST(ChessBoardTest, Queen_Capture)
{
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(3, 0)->setPiece("Q"); 
	chess_board.getSquare(3, 3)->setPiece("p"); 

	EXPECT_NO_THROW(chess_board.moveQueen(3, 0, 3, 3));

	EXPECT_FALSE(chess_board.getSquare(3, 0)->isOccupied());
	EXPECT_TRUE(chess_board.getSquare(3, 3)->isOccupied()); 
	EXPECT_EQ("Q", chess_board.getSquare(3, 3)->getPiece());
}

TEST(ChessBoardTest, King_Valid){
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(4,0)->setPiece("K");
	EXPECT_NO_THROW(chess_board.moveKing(4, 0, 4, 1));
}

TEST(ChessBoardTest, King_Invalid){
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(4, 0)->setPiece("K");
	EXPECT_THROW(chess_board.moveKing(4, 0, 4, 2), std::invalid_argument);
}

TEST(ChessBoardTest, King_Capture){
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(4, 0)->setPiece("K"); 
	chess_board.getSquare(4, 1)->setPiece("p"); 

	EXPECT_NO_THROW(chess_board.moveKing(4, 0, 4, 1));

	EXPECT_FALSE(chess_board.getSquare(4, 0)->isOccupied());
	EXPECT_TRUE(chess_board.getSquare(4, 1)->isOccupied()); 
	EXPECT_EQ("K", chess_board.getSquare(4, 1)->getPiece());
}

TEST(ChessBoardTest, Rook_Valid)
{ // VALID ROOK
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 0)->setPiece("R");
	EXPECT_NO_THROW(chess_board.moveRook(0, 0, 3, 0));
}
TEST(ChessBoardTest, Rook_Capture)
{ // rook capture
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 0)->setPiece("R"); // Rook at (0, 0)
	chess_board.getSquare(0, 2)->setPiece("p"); // Opponent's piece (pawn) at (0, 2)

	EXPECT_NO_THROW(chess_board.moveRook(0, 0, 0, 2)); // Expect no exception to be thrown

	// Verify that the rook has captured the opponent's piece
	EXPECT_FALSE(chess_board.getSquare(0, 0)->isOccupied()); // Rook is no longer at (0, 0)
	EXPECT_TRUE(chess_board.getSquare(0, 2)->isOccupied());	 // Opponent's piece is captured at (0, 2)
	EXPECT_EQ("R", chess_board.getSquare(0, 2)->getPiece()); // The captured piece is a rook
}

TEST(ChessBoardTest, Rook_Invalid)
{ // INVALID ROOK MOVEMENT
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 0)->setPiece("R");
	EXPECT_THROW(chess_board.moveRook(0, 0, 2, 2), std::invalid_argument);
}
TEST(ChessBoardTest, Knight_Valid)
{ // VALID KNIGHT MOVEMENT
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 1)->setPiece("N");
	EXPECT_NO_THROW(chess_board.moveKnight(0, 1, 2, 2));
	ChessSquare* newSquare = chess_board.getSquare(2, 2); // ADDED
    EXPECT_TRUE(newSquare->isOccupied());
    EXPECT_EQ(newSquare->getPiece(), "N");
}

TEST(ChessBoardTest, Knight_Capture)
{ // knight capture
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 1)->setPiece("N"); // Knight at (0, 1)
	chess_board.getSquare(2, 2)->setPiece("p"); // Opponent's piece (pawn) at (2, 2)

	EXPECT_NO_THROW(chess_board.moveKnight(0, 1, 2, 2)); // Expect no exception to be thrown

	// Verify that the knight has captured the opponent's piece
	EXPECT_FALSE(chess_board.getSquare(0, 1)->isOccupied()); // Knight is no longer at (0, 1)
	EXPECT_TRUE(chess_board.getSquare(2, 2)->isOccupied());	 // Opponent's piece is captured at (2, 2)
	EXPECT_EQ("N", chess_board.getSquare(2, 2)->getPiece()); // The captured piece is a knight
}

TEST(ChessBoardTest, Knight_Invalid)
{ // INVALID KNIGHT MOVEMENT
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(2, 1)->setPiece("N"); // Placing a knight on square (2, 1)

	EXPECT_THROW(chess_board.moveKnight(2, 1, 4, 1), std::invalid_argument);
}
