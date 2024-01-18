#include <iostream>

void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
bool makeMove(char board[3][3], char currentPlayer, int row, int col);
bool checkWin(const char board[3][3], char currentPlayer);
bool checkDraw(const char board[3][3]);
void switchPlayer(char &currentPlayer);
bool playAgain();

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameOver = false;

    do {
        initializeBoard(board);

        do {
            displayBoard(board);

            int row, col;
            do {
                std::cout << "Player " << currentPlayer << "'s turn. Enter your move (row and column): ";
                std::cin >> row >> col;
            } while (!makeMove(board, currentPlayer, row, col));

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            }

            if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "The game is a draw!" << std::endl;
                break;
            }

            switchPlayer(currentPlayer);

        } while (!gameOver);

    } while (playAgain());

    return 0;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const char board[3][3]) {
    std::cout << "Game Board:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------" << std::endl;
    }
    std::cout << std::endl;
}

bool makeMove(char board[3][3], char currentPlayer, int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        std::cout << "Invalid move. Try again." << std::endl;
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

bool checkWin(const char board[3][3], char currentPlayer) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }

    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
