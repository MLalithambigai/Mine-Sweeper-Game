# Mine-Sweeper-Game
First, player should select the size of the mine field. Then the field is displayed to the player, where all the locations are coveredandindicated with a ‘c’. The mines should be buried at randomlocations of theselected field. Then user can enter three letters in <row letter><column letter><command>. Row letter - This is from A, B, and etc
Column letter - This is also from A, B, and etc. Command - F - place a flag on the location
R - reveal the uncovered location
In the next iteration, the updated field will be displayed to the user. If the player place a flag, that location will be marked with ‘F’. If the player wanted to reveal the location and no mine is buried inthat
location, number of mines in the eight neighbors of that location is indicated. If
no mines are in the eight neighbors, a dot (.) will be displayed. If player reveal alocation with a bomb, the updated map will be displayed to the player in the next
round but player should start a new game. If the player enters a wrong letter of row or column, wrong command letter, ornumber is entered, then an error message should be displayed and ask user toenter the correct letters.If a flag is used, available flag count should be reducedby one
