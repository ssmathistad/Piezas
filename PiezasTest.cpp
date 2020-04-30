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
	// 0-2 then 1-2 is col 2
	Piezas obj;
	obj.dropPiece(3);
	Piece piece_at = obj.pieceAt(0, 3);
	ASSERT_EQ(piece_at, Invalid);
}
