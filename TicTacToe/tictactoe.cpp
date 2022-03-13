#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int row, column; //initialising variables for entering X or 0 by row,column pair
char figure = 'X';
bool tieStatus = false;
string p1 = "Player 1 (X)";
string p2 = "Player 2 (0)";

char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; //Creates array for Tic Tac Toe Grid.

void createGrid() //Function to render the Tic Tac Toe grid for each instance
{
    cout << "\n\n      |     |    \n";
    cout << "    " << grid[0][0] << " |  " << grid[0][1] << "  |  " << grid[0][2] << "  \n";
    cout << "  ____|_____|____\n";
    cout << "      |     |    \n";
    cout << "    " << grid[1][0] << " |  " << grid[1][1] << "  |  " << grid[1][2] << "  \n";
    cout << "  ____|_____|____\n";
    cout << "      |     |    \n";
    cout << "    " << grid[2][0] << " |  " << grid[2][1] << "  |  " << grid[2][2] << "  \n";
    cout << "      |     |    \n\n";
}

void enterFigure() //Asks for human input(cell number) where X or 0 is entered.
{
    int cellNo;
    if (figure == 'X')
    {
        cout << p1 << ", please enter cell number: ";
        cin >> cellNo;
    }

    if (figure == '0')
    {
        cout << p2 << ", please enter cell number: ";
        cin >> cellNo;
    }

    if (cellNo == 1)
    {
        row = 0;
        column = 0;
    }
    if (cellNo == 2)
    {
        row = 0;
        column = 1;
    }
    if (cellNo == 3)
    {
        row = 0;
        column = 2;
    }
    if (cellNo == 4)
    {
        row = 1;
        column = 0;
    }
    if (cellNo == 5)
    {
        row = 1;
        column = 1;
    }
    if (cellNo == 6)
    {
        row = 1;
        column = 2;
    }
    if (cellNo == 7)
    {
        row = 2;
        column = 0;
    }
    if (cellNo == 8)
    {
        row = 2;
        column = 1;
    }
    if (cellNo == 9)
    {
        row = 2;
        column = 2;
    }
    else if (cellNo < 1 || cellNo > 9)
    {
        cout << "Invalid !" << endl;
    }

    if (figure == 'X' && grid[row][column] != 'X' && grid[row][column] != '0') //checks if an already filled cell is referenced again by human; runs the function again.
    {
        grid[row][column] = 'X';
        figure = '0';
    }
    else if (figure == '0' && grid[row][column] != 'X' && grid[row][column] != '0')
    {
        grid[row][column] = '0';
        figure = 'X';
    }
    else
    {
        cout << "Cell is not empty, plz enter empty cell number!" << endl;
        enterFigure();
    }
    createGrid();
}


bool checkStatus() //Function to check the hotizontal/vertical/diagonal rows to check for Winner, gives boolean values.
{
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2] || grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
            return true;
    }

    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] || grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] != 'X' && grid[i][j] != '0')
            {
                return false;
            }
        }
    }
    tieStatus = true;
    return false;
}

void declare() //Function to declare the Game Winner based on the values returned from checkStatus() function.
{
    if (figure == 'X' && tieStatus == false)
    {
        cout << p2 << " wins!!" << endl;
    }
    else if (figure == '0' && tieStatus == false)
    {
        cout << p1 << " wins!!" << endl;
    }
    else
    {
        cout << "It's a draw!" << endl;
    }
}

int main() //Main Driver Method of Program
{
    cout << "TIC TAC TOE - Human vs Human";

    cout << "\n\n      |     |    \n";
    cout << "    " << grid[0][0] << " |  " << grid[0][1] << "  |  " << grid[0][2] << "  \n";
    cout << "  ____|_____|____\n";
    cout << "      |     |    \n";
    cout << "    " << grid[1][0] << " |  " << grid[1][1] << "  |  " << grid[1][2] << "  \n";
    cout << "  ____|_____|____\n";
    cout << "      |     |    \n";
    cout << "    " << grid[2][0] << " |  " << grid[2][1] << "  |  " << grid[2][2] << "  \n";
    cout << "      |     |    \n\n";

    while (!checkStatus())
    {
        enterFigure();
        checkStatus();
    }
    declare();
}
