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

MinesweeperGame::MinesweeperGame(int size, int number_of_mines)
    : field_grid_size(size), mines_amount(number_of_mines), flags_amount_now(number_of_mines)
{
    field_cell.resize(field_grid_size, vector<char>(field_grid_size, 'c')); // Initialize grid cells as covered
    mines.resize(field_grid_size, vector<bool>(field_grid_size, false)); // Initialize no mines on the grid
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation
}

void MinesweeperGame::displayGameField()
{}

void MinesweeperGame::displayFieldMine()
{}

void MinesweeperGame::setMines()
{}

void MinesweeperGame::revealingCell(int row, int col)
{}

void MinesweeperGame::flagPlacing(int row, int col)
{}

bool MinesweeperGame::winOrNot()
{
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
