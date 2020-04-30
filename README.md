[![Build Status](https://travis-ci.org/ssmathistad/Piezas.svg?branch=master)](https://travis-ci.org/ssmathistad/Piezas)


# Piezas

## Associated Enumerated Types
`Piece` has four possible values: `X`,`O`,`Invalid`, and `Blank`

## Member Variables
board

**board** is a 2D vector of Pieces that represents the playing board
___
`Piece turn` 

**turn** represents whose turn it is to place a piece (defaults to X)

## Public Functions
`Piezas()`

*Constructor sets an empty board (3 rows, 4 columns) and specifies it is X's turn first*
___
`void reset();`

*Resets each board location to the Blank Piece value, with a board of the same size as previously specified*

`Piece dropPiece(int column)`

*Places a piece of the current turn on the board, returns what piece is placed, and toggles which Piece's turn it is. dropPiece does NOT allow to place a piece in a location where a column is full. In that case, placePiece returns Piece Blank value Out of bounds coordinates return the Piece Invalid value. Trying to drop a piece where it cannot be placed loses the player's turn*
___
`Piece pieceAt(int row, int column)`

*Returns what piece is at the provided coordinates, or Blank if there are no pieces there, or Invalid if the coordinates are out of bounds*

___
`Piece gameState()`

*Returns which Piece has won, if there is a winner, Invalid if the game is not over, or Blank if the board is filled and no one has won ("tie"). For a game to be over, all locations on the board must be filled with X's and O's (i.e. no remaining Blank spaces). The winner is which player has the most adjacent pieces in a single line. Lines can go either vertically or horizontally. If both X's and O's have the same max number of pieces in a line, it is a tie.*
