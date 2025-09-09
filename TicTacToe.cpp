#include <iostream>
using namespace std;

void printBoard(int arr[3][3]) {
    system("cls");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (arr[r][c] == 0) cout << " ";
            else if (arr[r][c] == 1) cout << "X";
            else cout << "O";
            
            if (c != 2) cout << "|";
        }
        if (r != 2) cout << "\n-----\n";
    }
    cout << "\n";
}

int checkWinner(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2])
            return arr[i][0];
        if (arr[0][i] && arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
            return arr[0][i];
    }
    if (arr[0][0] && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2])
        return arr[0][0];
    if (arr[0][2] && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
        return arr[0][2];
    return 0;
}

int main() {
    int arr[3][3] = {0};
    int row, col, winner = 0;
    cout << "\n\t--- WELCOME TO TIC-TAC-TOE ---\n";

    for (int turn = 0; turn < 9 && !winner; turn++) {
        int player = (turn % 2) + 1;
        cout << "\nPlayer " << player << "'s turn\n";

        do {
            cout << "Enter row (1-3): ";
            cin >> row;
            cout << "Enter column (1-3): ";
            cin >> col;
            row--;
            col--;
        } while (row < 0 || row > 2 || col < 0 || col > 2 || arr[row][col] != 0);

        arr[row][col] = player;
        printBoard(arr);
        winner = checkWinner(arr);
    }

    if (winner) 
        cout << "Congratulations Player " << winner << "! You win!\n";
    else 
        cout << "It's a draw!\n";
    cin.ignore();
    cin.get();
    return 0;
}