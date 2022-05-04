#include <iostream>

using namespace std;

enum gameSituation { 
  oWin, 
  xWin, 
  tie, 
  lastInvalidMove, 
  lastValidMove 
};

class TickTackToe {
  private:
    char player;
    int numberPlay;
    int boardSize;
    char **board;
    
  public:
    TickTackToe(int boardSize):player('O'), numberPlay(0), boardSize(boardSize), board(new char*[boardSize]) {
      for(int i = 0; i < boardSize; i++) board[i] = new char[boardSize];
      for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) board[i][j] = ' ';
      }
    }

    TickTackToe(const TickTackToe &t):player(t.player), numberPlay(t.numberPlay), boardSize(t.boardSize) {
      for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) 
          board[i][j] = t.board[i][j];
      }
    }

    ~TickTackToe() {
      for(int i = 0; i < boardSize; i++) delete[] board[i];
      delete[] board;
    }

    void printBoard(){
      printf("\n");
      for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++)
          printf(j == 0 ? " %c" : " | %c", board[j][i]);
        printf("\n");
        if(i == boardSize - 1) continue;
        for(int j = 1; j <= 4 * boardSize; j++) printf("-");
        printf("\n");
      }
      printf("\n");
    }

    bool checkWinner(int x, int y);

    gameSituation play(int x, int y);
};

bool TickTackToe::checkWinner(int x, int y) {
  bool winner = true;
  for(int i = 0; i < boardSize; i++) {
    if(board[i][y] == board[x][y]) continue;
    winner = false; 
    break;
  }
  if(winner) return true;
  winner = true;
  for(int j = 0; j < boardSize; j++) {
    if(board[x][j] == board[x][y]) continue;
    winner = false; 
    break;
  }
  if(winner) return true;
  winner = true;
  if(x == y) {
    for(int k = 0; k < boardSize; k++) {
      if(board[k][k] == board[x][y]) continue;
      winner = false; 
      break;
    }
    if(winner) return true;
  }
  if(x + y == boardSize - 1) {
    for(int k = 0; k < boardSize; k++) {
      if(board[k][boardSize - k - 1] == board[x][y]) continue;
      winner = false; 
      break;
    }
    if(winner) return true;
  }
  return false;
}

gameSituation TickTackToe::play(int x, int y) {
  if(x < 0 || x >= boardSize || y < 0 || y >= boardSize || board[x][y] == 'O' || board[x][y] == 'X') 
    return lastInvalidMove;
  else board[x][y] = player;
  if(checkWinner(x, y)) {
    if(player == 'O') return oWin;
    else return xWin;
  }
  else if(++numberPlay == boardSize * boardSize) return tie;
  else if(numberPlay % 2) player = 'X';
  else player = 'O';
  return lastValidMove;
}

int main() {
  int n;

  cout << "Enter the size of the board: ";
  cin >> n;

  TickTackToe t(n);
  gameSituation gs;

  do {
    int x, y;
    cout << "Enter the coordinates you wanna play: ";
    cin >> x >> y;

    gs = t.play(x, y);
    t.printBoard();
    if(gs == oWin) cout << "O Wins" << endl;
    else if(gs == xWin) cout << "X Wins" << endl;
    else if(gs == tie) cout << "Tied" << endl;
    else if(gs == lastInvalidMove) cout << "Invalid move" << endl;
    else cout << "Valid move" << endl;

  } while(gs != oWin && gs != xWin && gs != tie);

  return 0;
}