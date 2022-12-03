#include <bits/stdc++.h>
using namespace std;

// check if the cow ch won in any row or column or diagonal
bool check_single_cow_winner(char ch, const vector<string> &board) {
    for (int i = 0; i < 3; i++) {
        // check rows
        if (board[i][0] == ch && board[i][1] == ch && board[i][2] == ch) {
            return true;
        }
        // check columns
        if (board[0][i] == ch && board[1][i] == ch && board[2][i] == ch) {
            return true;
        }
    }
    // check diagonals
    if (board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) {
        return true;
    }
    if (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch) {
        return true;
    }
    return false;
}

// determine the number of individual cow wins
int individual_wins(const vector<string> &board) {
    int single_cow_wins = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        single_cow_wins += check_single_cow_winner(ch, board);
    }
    return single_cow_wins;
}

// check if both cows ch1 and ch2 are in the row/column/diagonal under review.
bool check_if_winners(char ch1, char ch2, char x, char y, char z) {
    if (x == y && x != z) {
        if (x == ch1 && z == ch2) {
            return true;
        }
        if (x == ch2 && z == ch1) {
            return true;
        }
    } else if (x == z && x != y) {
        if (x == ch1 && y == ch2) {
            return true;
        }
        if (x == ch2 && y == ch1) {
            return true;
        }
    } else if (y == z && x != y) {
        if (y == ch1 && x == ch2) {
            return true;
        }
        if (y == ch2 && x == ch1) {
            return true;
        }
    }
    return false;
}

// check if the cows ch1 and ch2 can win in any of the rows or columns or diagonals
bool check_double_cow_winners(char ch1, char ch2, const vector<string> &board) {
    for (int i = 0; i < 3; i++) {
        // check rows
        if (check_if_winners(ch1, ch2, board[i][0], board[i][1], board[i][2])) {
            return true;
        }
        // check columns
        if (check_if_winners(ch1, ch2, board[0][i], board[1][i], board[2][i])) {
            return true;
        }
    }
    // check diagonals
    if (check_if_winners(ch1, ch2, board[0][0], board[1][1], board[2][2])) {
        return true;
    }
    if (check_if_winners(ch1, ch2, board[0][2], board[1][1], board[2][0])) {
        return true;
    }
    return false;
}

// determine the number of team wins
int team_wins(const vector<string> &board) {
    int double_cow_wins = 0;
    for (char ch1 = 'A'; ch1 <= 'Z'; ch1++) {
        for (char ch2 = ch1 + 1; ch2 <= 'Z'; ch2++) {
            double_cow_wins += check_double_cow_winners(ch1, ch2, board);
        }
    }
    return double_cow_wins;
}

int main() {

    vector<string> board(3);
    for (int i = 0; i < 3; i++) {
        cin >> board[i];
    }

    int individual_cows = individual_wins(board);
    int team_cows = team_wins(board);

    cout << individual_cows << endl;
    cout << team_cows << endl;
}