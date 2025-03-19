#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int turn = 0;
char players[2] = {'X', 'O'};

//  Draw the Tic-Tac-Toe Board
void drawBoard() {
	
    // Background
    setbkcolor(CYAN);
    cleardevice();
    
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, 7);
    
    // Draw Grid
    for (int i = 1; i < 3; i++) {
        line(100 * i, 0, 100 * i, 300);
        line(0, 100 * i, 300, 100 * i);
    }

    // Draw X and O
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x = j * 100 + 50;
            int y = i * 100 + 50;
            if (board[i][j] == 'X') {
                setcolor(RED);
                line(x - 25, y - 25, x + 25, y + 25);
                line(x - 25, y + 25, x + 25, y - 25);
            } else if (board[i][j] == 'O') {
                setcolor(GREEN);
                circle(x, y, 25);
            }
        }
    }
}

//  Check Winner
bool checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return true;
    return false;
}

// ResetFunction
void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    turn = 0;
}

// Display Winner and Reset
void displayWinner() {
    setbkcolor(BLACK);
    cleardevice();
    setcolor(YELLOW);
    settextstyle(BOLD_FONT, HORIZ_DIR, 5);
    outtextxy(80, 130, "Winner!");
    delay(2000);
    resetBoard();
    drawBoard();
}

//  Loop
void gameLoop() {
    int x, y;
    while (!kbhit()) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            int row = y / 100;
            int col = x / 100;

            if (board[row][col] == ' ') {
                board[row][col] = players[turn % 2];
                turn++;
                drawBoard();
                
                if (checkWinner()) {
                    displayWinner();
                }
            }
        }
    }
}


int main() {
    // CreativeBanner
    cout << "===================================" << endl;
    cout << "|       Creative Tic-Tac-Toe      |" << endl;
    cout << "===================================" << endl;
    cout << "       |     |      " << endl;
    cout << "    X  |  O  |  X   " << endl;
    cout << "  _____|_____|_____ " << endl;
    cout << "       |     |      " << endl;
    cout << "    O  |  X  |  O   " << endl;
    cout << "  _____|_____|_____ " << endl;
    cout << "       |     |      " << endl;
    cout << "    X  |  O  |  X   " << endl;
    cout << "       |     |      " << endl;
    cout << "===================================" << endl;
    cout << "       Let's Play!       " << endl;
    cout << "===================================" << endl;
    
    
    initwindow(300, 350, "Creative Tic-Tac-Toe");
    drawBoard();
    gameLoop();
    closegraph();
    return 0;
}

