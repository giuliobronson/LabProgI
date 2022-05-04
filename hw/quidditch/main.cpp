#include <iostream>
#include <cmath>

using namespace std;

class Player {
  private:
    string name;
  
  protected:
    int strength;
    int speed;
    int style;
    int bonus;

  public:
    Player(string name, int strength, int speed, int style):
    name(name), strength(strength), speed(speed), style(style) {
    }

    string getName() {
      return name;
    }

    int getStrength() {
      return strength;
    }

    int getSpeed() {
      return speed;
    }

    int getStyle() {
      return style;
    }

    int getHability();
};

class Gunner:public Player {
  private:
    int hatTricks;

  public:
    Gunner(string name, int strength, int speed, int style, int hatTricks):
    Player(name, strength, speed, style), hatTricks(hatTricks) {
      bonus = 20 * hatTricks;
    }

    int getHatTricks() {
      return hatTricks;
    }

    int getHability() {
      return strength + 3 * speed + 2 * style + bonus;
    }
};

class Catcher:public Player {
  private:
    int goldenSnitchs;

  public:
    Catcher(string name, int strength, int speed, int style, int goldenSnitchs):
    Player(name, strength, speed, style), goldenSnitchs(goldenSnitchs) {
      bonus = 10 * goldenSnitchs;
    }

    int getGoldenSnitchs() {
      return goldenSnitchs;
    }

    int getHability() {
      return strength + 2 * speed + 3 * style + bonus;
    }
};

class Scout:public Player {
  private:
    int bludgers;
    int bonus;

  public:
    Scout(string name, int strength, int speed, int style, int bludgers):
    Player(name, strength, speed, style), bludgers(bludgers) {
      bonus = (int)pow(2, bludgers % 100);
    }

    int getBludgers() {
      return bludgers;
    }

    int getHability() {
      return (3 * strength + speed + style) * bonus;
    }
};

class GoalKeeper:public Player {
  int cleanShirts;
  int gamesPlayed;

  public:
    GoalKeeper(string name, int strength, int speed, int style, int cleanShirts, int gamesPlayed):
    Player(name, strength, speed, style), cleanShirts(cleanShirts), gamesPlayed(gamesPlayed) {
      bonus = gamesPlayed - cleanShirts;
    }

    int getCleanShirts() {
      return cleanShirts;
    }

    int getGamesPlayed() {
      return gamesPlayed;
    }

    int getHability() {
      return 2 * strength + 3 * style + bonus;
    }
};

class QuidditchTeam {
  private:
    string name;
    int nPlayers;
    Player **players;

  public:
    QuidditchTeam(string name):name(name), nPlayers(0), players(new Player*[7]) {
      for(int i = 0; i < 7; i++) players[i] = NULL;
    }

    QuidditchTeam(const QuidditchTeam &q):nPlayers(q.nPlayers) {
      for(int i = 0; i < nPlayers; i++) players[i] = q.players[i];
    }

    ~QuidditchTeam() {
      delete[] players;
    }
    string getName() {
      return name;
    }

    bool insertPlayer(Player &p) {
      if(nPlayers > 7) return false;
      players[++nPlayers - 1] = &p;
      return true;
    }

    int getTotalHability() {
      int total = 0;
      for(int i = 0; i < nPlayers; i++) total += players[i]->getHability();
      return total;
    }
};

class Match {
  public:
    bool play(QuidditchTeam q1, QuidditchTeam q2) {
      int team1 = q1.getTotalHability();
      int team2 = q2.getTotalHability();
      if(team1 != -1 && team2 != -1) return false;
      else if(team1 > team2) cout << q1.getName() << endl;
      else if(team1 < team2) cout << q2.getName() << endl;
      else cout << "Tie" << endl;
      return true;
    }
};

int main() {
  GoalKeeper gk1("Ron Wesley", 5, 3, 4, 10, 20);
  Catcher ct1("Harry Potter", 3, 2, 6, 10);
  Scout sc1("Jimmy Peaks", 3, 6, 4, 8), 
    sc2("Ritchie Coose", 3, 6, 3, 7);
  Gunner gn1("Demelza Robina", 5, 7, 3, 8);
  
  return 0;
}