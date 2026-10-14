#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Checks if position is inside the board 
bool isSafe(int x, int y, int N, const vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Counts onward moves from a square 
int countMoves(int x, int y, int N, const vector<vector<int>>& board, const int dx[], const int dy[]) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (isSafe(x + dx[i], y + dy[i], N, board)) count++;
    }
    return count;
}

// Recursive backtracking 
bool solveKnightTour(int x, int y, int moveNum, int N, vector<vector<int>>& board, const int dx[], const int dy[]) {
    if (moveNum == N * N + 1) return true; // All squares visited

    // Collect valid moves 
    vector<pair<int, int>> candidates;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isSafe(nx, ny, N, board)) {
            candidates.push_back({countMoves(nx, ny, N, board, dx, dy), i});
        }
    }

    // Try squares with fewest onward moves first
    sort(candidates.begin(), candidates.end());

    for (auto& c : candidates) {
        int nextX = x + dx[c.second];
        int nextY = y + dy[c.second];

        board[nextX][nextY] = moveNum;

        if (solveKnightTour(nextX, nextY, moveNum + 1, N, board, dx, dy)) {
            return true;
        }

        board[nextX][nextY] = -1; // Backtrack
    }
    return false;
}

int main() {
    int N, startX, startY;
    cout << "Knight's Tour\n";
    cout << "Enter Board Size N (e.g. 5 for 5x5): ";
    cin >> N;
    cout << "Enter Starting Row (0 to " << N - 1 << "): ";
    cin >> startX;
    cout << "Enter Starting Col (0 to " << N - 1 << "): ";
    cin >> startY;

    if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
        cout << "Invalid starting position\n";
        return 0;
    }

    // Initialize board with -1
    vector<vector<int>> board(N, vector<int>(N, -1));

    // Eight possible knight moves (L-shaped)
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    board[startX][startY] = 1; // Mark starting point

    if (solveKnightTour(startX, startY, 2, N, board, dx, dy)) {
        cout << "\nKnight's Tour Solution:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << setw(4) << board[i][j];
            }
            cout << "\n";
        }
    } else {
        cout << "No valid Knight's Tour exists for " << N << "x" << N << " starting from (" << startX << ", " << startY << ").\n";
    }

    return 0;
}