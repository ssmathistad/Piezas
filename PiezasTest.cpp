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

///

TEST(PiezasTest, reset_state_row_0_col_0)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(0, 0);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, reset_state_row_0_col_3)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(0, 3);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, reset_state_row_1_col_0)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(1, 0);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, reset_state_row_1_col_3)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(1, 3);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, reset_state_row_2_col_0)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(2, 0);
	ASSERT_EQ(piece_at, Blank);
}

TEST(PiezasTest, reset_state_row_2_col_3)
{
	Piezas obj;
	obj.reset();
	Piece piece_at = obj.pieceAt(2, 3);
	ASSERT_EQ(piece_at, Blank);
}