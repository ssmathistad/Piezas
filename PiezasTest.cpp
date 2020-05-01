/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

//--- Tests for the intial grid state filled out by the constuctor.

TEST(PiezasTest, initial_state_row_0_col_0)
{
	Piezas obj;
	Piece piece_at = obj.pieceAt(0, 0);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, initial_state_row_0_col_3)
{
	Piezas obj;
	Piece piece_at = obj.pieceAt(0, 3);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, initial_state_row_1_col_0)
{
	Piezas obj;
	Piece piece_at = obj.pieceAt(1, 0);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, initial_state_row_1_col_3)
{
	Piezas obj;
	Piece piece_at = obj.pieceAt(1, 3);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, initial_state_row_2_col_0)
{
	Piezas obj;
	Piece piece_at = obj.pieceAt(2, 0);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, initial_state_row_2_col_3)
{
	Piezas obj;
	Piece piece_at = obj.pieceAt(2, 3);
	ASSERT_EQ(piece_at, Blank);
}

//--- Tests for the intial grid state filled out by the constuctor,
// followed by calling the reset() function.

TEST(PiezasTest, reset_get_piece_at_row_0_col_0_no_dropPiece)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(0, 0);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, reset_get_piece_at_row_0_col_3_no_dropPiece)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(0, 3);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, reset_get_piece_at_row_1_col_0_no_dropPiece)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(1, 0);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, reset_get_piece_at_row_1_col_3_no_dropPiece)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(1, 3);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, reset_get_piece_at_row_2_col_0_no_dropPiece)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(2, 0);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, reset_get_piece_at_row_2_col_3_no_dropPiece)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(2, 3);
	ASSERT_EQ(piece_at, Blank);
}

//--- Tests dropPiece()

//// Invalid col
TEST(PiezasTest, dropPiece_below_min_BOARD_COLS)
{
	// 0-2 then 1-2 is col 2
	Piezas obj;
	obj.dropPiece(-1);
	Piece piece_at = obj.pieceAt(0, -1);
	ASSERT_EQ(piece_at, Invalid);
}

TEST(PiezasTest, dropPiece_above_max_BOARD_COLS)
{
	Piezas obj;
	obj.dropPiece(3);
	Piece piece_at = obj.pieceAt(0, 4);
	ASSERT_EQ(piece_at, Invalid);
}

//// Valid col
TEST(PiezasTest, dropPiece_col_0_within_BOARD_COLS)
{
	Piezas obj;
	obj.dropPiece(0);
	Piece piece_at = obj.pieceAt(0, 0);
	ASSERT_EQ(piece_at, X);
}

TEST(PiezasTest, dropPiece_col_1_within_BOARD_COLS)
{
	Piezas obj;
	obj.dropPiece(1);
	Piece piece_at = obj.pieceAt(0, 1);
	ASSERT_EQ(piece_at, X);
}

TEST(PiezasTest, dropPiece_col_2_within_BOARD_COLS)
{
	Piezas obj;
	obj.dropPiece(2);
	Piece piece_at = obj.pieceAt(0, 2);
	ASSERT_EQ(piece_at, X);
}

TEST(PiezasTest, dropPiece_col_3_within_BOARD_COLS)
{
	Piezas obj;
	obj.dropPiece(3);
	Piece piece_at = obj.pieceAt(0, 3);
	ASSERT_EQ(piece_at, X);
}

// Testing stacking
/*    Row, col
    * [2,0][2,1][2,2][2,3]
    * [1,0][1,1][1,2][1,3]
    * [0,0][0,1][0,2][0,3]
*/
TEST(PiezasTest, two_pieces_in_col_0)
{
	Piezas obj;
	obj.dropPiece(0);
	obj.dropPiece(0);
	Piece piece_at = obj.pieceAt(1, 0);
	ASSERT_EQ(state, O);
}

// Testing gameState
TEST(PiezasTest, no_moves_made_gameState)
{
	Piezas obj;
	Piece state = obj.gameState();
	ASSERT_EQ(state, Invalid);
}



/*
X O X O
X O X O
X O X O
*/
/*
TEST(PiezasTest, board_full_playing_sequentially_by_col)
{
	Piezas obj;
	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(3);
	
	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(3);

	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(3);

	ASSERT_EQ(obj.gameState(), Blank);
}
*/