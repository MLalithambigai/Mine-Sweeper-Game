#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// 21_ENG_116 - R. Abinayan
class MinesweeperGame
{
private:
    int field_grid_size;
    int mines_amount;
    vector<vector<char>> field_cell;
    vector<vector<bool>> mines;
    int flags_amount_now;

public:
    MinesweeperGame(int size, int number_of_mines); // Constructor
    void displayGameField(); // Display the game grid
    void displayFieldMine(); // Display the game grid with mines
    void setMines(); // Place mines randomly
    void revealingCell(int row, int col); // Reveal a cell
    void flagPlacing(int row, int col); // Place a flag
    bool winOrNot(); // Check if the game is won
    void playGame(); // Main game loop
    int adjacentMinesFind(int row, int col); // Count adjacent mines
};

// 21_ENG_075 - M. Lalithambigai
MinesweeperGame::MinesweeperGame(int size, int number_of_mines)
    : field_grid_size(size), mines_amount(number_of_mines), flags_amount_now(number_of_mines)
{
    field_cell.resize(field_grid_size, vector<char>(field_grid_size, 'c')); // Initialize grid cells as covered
    mines.resize(field_grid_size, vector<bool>(field_grid_size, false)); // Initialize no mines on the grid
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation
}

// 21_ENG_075 - M. Lalithambigai
void MinesweeperGame::displayGameField()
{
    // Display column labels
    cout << "  ";
    for (int i = 0; i < field_grid_size; ++i)
    {
        cout << static_cast<char>('A' + i) << " ";
    }
    cout << endl;

    // Display the game grid
    for (int i = 0; i < field_grid_size; ++i)
    {
        cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < field_grid_size; ++j)
        {
            cout << field_cell[i][j] << " ";
        }
        cout << endl;
    }
}

// 21_ENG_075 - M. Lalithambigai
// 21_ENG_138 - T. F. Nusha
void MinesweeperGame::displayFieldMine()
{
    cout << "  ";
    for (int i = 0; i < field_grid_size; ++i)
    {
        cout << static_cast<char>('A' + i) << " ";
    }
    cout << endl;

    // Display the game grid with revealed mines
    for (int i = 0; i < field_grid_size; ++i)
    {
        cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < field_grid_size; ++j)
        {
            if(mines[i][j]==true)
            {
                cout << "M" << " ";
            }
            else
            {
                cout << field_cell[i][j] << " ";
            }

        }
        cout << endl;
    }
}

// 21_ENG_075 - M. Lalithambigai
void MinesweeperGame::setMines()
{
    int minesPlaced = 0;
    while (minesPlaced < mines_amount)
    {
        int row = rand() % field_grid_size;
        int col = rand() % field_grid_size;
        if (!mines[row][col])
        {
            mines[row][col] = true; // Place a mine
            ++minesPlaced;
        }
    }
}
// 21_ENG_075 - M. Lalithambigai
// 21_ENG_138 - T. F. Nusha
void MinesweeperGame::revealingCell(int row, int col)
{
    // Check for a mine at the selected cell
    if (mines[row][col])
    {
        cout << "Game Over! You hit a mine." << endl;
        displayFieldMine();
        exit(0);
    }

    if (field_cell[row][col] == 'c')
    {
        int adjacentMines = adjacentMinesFind(row, col);
        if (adjacentMines == 0)
        {
             field_cell[row][col] = '.'; // Display an empty cell
            // Reveal adjacent cells if they exist
            for (int i = -1; i <= 1; ++i)
            {
                for (int j = -1; j <= 1; ++j)
                {
                    int newRow = row + i;
                    int newCol = col + j;
                    if (newRow >= 0 && newRow < field_grid_size && newCol >= 0 && newCol < field_grid_size)
                    {
                        revealingCell(newRow, newCol);
                    }
                }
            }
        }
        else
        {
            field_cell[row][col] = '0' + adjacentMines;
        }
    }
}
// 21_ENG_075 - M. Lalithambigai
void MinesweeperGame::flagPlacing(int row, int col)
{
    if(flags_amount_now!=0)
    {
        if (field_cell[row][col] == 'c')
        {
             field_cell[row][col] = 'F'; // Place a flag
            --flags_amount_now; // Decrease the count of available flags
        }
        else
        {
            cout << "Invalid move. You can only place a flag on a covered location." << endl;
        }
    }
    else
    {
        cout << "Invalid move. You have no flags left." << endl;
    }
}
// 21_ENG_075 - M. Lalithambigai
bool MinesweeperGame::winOrNot()
{
    for (int i = 0; i < field_grid_size; ++i)
    {
        for (int j = 0; j < field_grid_size; ++j)
        {
            if (mines[i][j] && field_cell[i][j] != 'F')
            {
                return false;  // Game not won if a mine is not flagged
            }
        }
    }
    return true;
}


int MinesweeperGame::adjacentMinesFind(int row, int col)
{
    return 0;
}

// Main function to start and manage the game
void MinesweeperGame::playGame()
{}

int main()
{
    return 0;
}
