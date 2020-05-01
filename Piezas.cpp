#include "Piezas.h"
#include <vector>
#include <cmath>
#include <string>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    Piece piece = Blank;
    std::vector<Piece> v{piece,piece,piece,piece};

    for (int i = BOARD_ROWS-1; i >= 0; i--) {
        board.push_back(v);
    }

    turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for (int i = BOARD_ROWS-1; i >= 0; i--) {
        for (int j = 0; j < BOARD_COLS; j++) {
            board[i][j] = Blank;
        }
    }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/

/*    Row, col
    * [2,0][2,1][2,2][2,3]
    * [1,0][1,1][1,2][1,3]
    * [0,0][0,1][0,2][0,3]
*/
Piece Piezas::dropPiece(int column)
{
    // 0-2 then 1-2 is col 2
    if (column >= BOARD_COLS || column < 0) {
        return Invalid;
    }

    for (int i = BOARD_ROWS-1; i >= 0; i--) {
        if (board[i][column] == Blank && i <= BOARD_COLS-1) {
            if (turn == X) {
                board[i][column] = X;
                turn = O;
            } else {
                board[i][column] = O;
                turn = X;
            }

            return board[i][column];
        } else if (board[i][column] != Blank && i == BOARD_COLS-1) {
            return Blank;
        }
    }

    return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/

/*    Row, col
    * [2,0][2,1][2,2][2,3]
    * [1,0][1,1][1,2][1,3]
    * [0,0][0,1][0,2][0,3]
*/
Piece Piezas::pieceAt(int row, int column)
{
    // 0,2
    row = std::abs(row-2);

    if (row >= BOARD_ROWS || column >= BOARD_COLS) {
        return Invalid;
    }
    
    if (board[row][column] == Blank) {
        return Blank;
    } else if (board[row][column] == X) {
        return X;
    } else if (board[row][column] == O) {
        return O;
    } else {
        return Invalid;
    }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    int counter = 0;

    for (int i = BOARD_ROWS-1; i >= 0; i--) {
        for (int j = 0; j < BOARD_COLS; j++) {
            if (pieceAt(i, j) == Blank) {
                counter++;
            }
        }
    }

    if (counter > 0) {
        return Invalid;
    }

    //Determine winner

    Piece prev;
    int x_best = 0;
    int o_best = 0;
    bool tied = false;

    // Test rows
    // for (int i = BOARD_ROWS-1; i >= 0; i--) {
        int row_x_cur, row_o_cur = 0;

        for (int j = 0; j < BOARD_COLS; j++) {
            if (j == 1) {
                prev = pieceAt(2, j);
                // Cannot assume x_best/o_best for next test with columns
                (prev == X) ? row_x_cur = x_best = 1 : row_o_cur = o_best = 1;
            } else {
                if (pieceAt(2, j) != prev) {
                    // Reset current row count for prev piece
                    (prev == X) ? row_x_cur = 0 : row_o_cur = 0;
                    prev = pieceAt(2, j);
                } else {
                    if (prev == X) {
                        row_x_cur++;

                        if (row_x_cur > x_best)
                            x_best = row_x_cur;
                    } else {
                        row_o_cur++;

                        if (row_o_cur > o_best)
                            o_best = row_o_cur;
                    }
                }
            }
            (x_best == o_best) ? tied = true : tied = false;
        }
    //}



    /* Row, col
    * [2,0][2,1][2,2][2,3]
    * [1,0][1,1][1,2][1,3]
    * [0,0][0,1][0,2][0,3]

    Row 2: [2,0][2,1][2,2][2,3]
    Row 1: [1,0][1,1][1,2][1,3]
    Row 0: [0,0][0,1][0,2][0,3]

    Col 0: [2,0][1,0][0,0]
    Col 1: [2,1][1,1][0,1]
    Col 2: [2,2][1,2][0,2]
    Col 3: [2,3][1,3][0,3]
    */

    return Blank;
}
