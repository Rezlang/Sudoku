This program is used to solve both traditional sudoku puzzles as well as killer sudoku
puzzle. 

Sudoku rules: 
a row must contain one of each number 1-9
a column must contain one of each number 1-9
each 3x3 zone must contain each number 1-9

Killer Sudoku rules:
Same rules as regular sudoku with the addition of sectors.
The sector will be given with a maximum size and the finished board must have sectors
that contain that value.

If you would like to try and solve a Killer Sudoku on your own, this website will
allow you to do so: https://sudoku.com/killer

Usage:
./run.exe <input-file> <output-file> <regular/killer>

Input style:
The board must be input via text file with the initial layout of the board in a 9x9
grid with spaces seperating each number. Any empty squares must be represented by 0.
For a killer board, the simple board input must be followed by sector identification
the first digit in the sector input must be a negative number where the absolute value
is 1 + the index of the sector. The second value is the maximum size of that sector.
subsequent rows of that sector must contain (y,x) coordinate pairs that make up the zone.
The next zone is begun by a negative number. See example input files for both regular
and killer inputs.
