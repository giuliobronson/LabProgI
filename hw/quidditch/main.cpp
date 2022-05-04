#include <iostream>
#include <cmath>

using namespace std;

class Player 
{
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

  virtual int getHability(){
    return bonus;
  };
};

class Gunner : public Player 
{
private:
  int hatTricks;

public:
  Gunner(string name, int strength, int speed, int style, int hatTricks) :
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

class Catcher : public Player 
{
private:
  int goldenSnitchs;

public:
  Catcher(string name, int strength, int speed, int style, int goldenSnitchs) :
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

class Scout : public Player 
{
private:
  int bludgers;
  int bonus;

public:
  Scout(string name, int strength, int speed, int style, int bludgers) :
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

class GoalKeeper : public Player 
{
private:
  int cleanShirts;
  int gamesPlayed;

public:
  GoalKeeper(string name, int strength, int speed, int style, int cleanShirts, int gamesPlayed) :
  Player(name, strength, speed, style), cleanShirts(cleanShirts), gamesPlayed(gamesPlayed) {
    bonus = -cleanShirts;
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

class QuidditchTeam 
{
private:
  string name;
  int nPlayers;
  Player **players;

public:
  QuidditchTeam(string name) : name(name), nPlayers(0), players(new Player*[7]) {
    for(int i = 0; i < 7; i++) players[i] = NULL;
  }

  QuidditchTeam(const QuidditchTeam &q) : name(name), nPlayers(q.nPlayers), players(new Player*[7]) {
    for(int i = 0; i < 7; i++) players[i] = q.players[i];
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

  bool alterPlayer(int i, Player &p) {
    if(!players[i]) return false;
    players[i] = &p;
    return true;
  }

  int getTotalHability() {
    int total = 0;
    int nGunner = 0, nCatcher = 0, nScout = 0, nKeeper = 0;
    for(int i = 0; i < nPlayers; i++) {
      Gunner *gunner = dynamic_cast<Gunner*>(players[i]);
      if(gunner) {
        total += gunner->getHability(); nGunner++;
        continue;
      }
      Catcher *catcher = dynamic_cast<Catcher*>(players[i]);
      if(catcher) {
        total += catcher->getHability(); nCatcher++;
        continue;
      }
      Scout *scout = dynamic_cast<Scout*>(players[i]);
      if(scout) {
        total += scout->getHability(); nScout++;
        continue;
      }
      GoalKeeper *keeper = dynamic_cast<GoalKeeper*>(players[i]);
      if(keeper) {
        total += keeper->getHability(); nKeeper++;
        continue;
      }
    }
    if(nGunner == 3 && nCatcher == 1 && nScout == 2 && nKeeper == 1) return total;
    return -1;
  }
};

class Match 
{
public:
  bool play(QuidditchTeam q1, QuidditchTeam q2) {
    int team1 = q1.getTotalHability();
    int team2 = q2.getTotalHability();
    if(team1 == -1 || team2 == -1) return false;
    else if(team1 > team2) cout << q1.getName() << endl;
    else if(team1 < team2) cout << q2.getName() << endl;
    else cout << "Tie" << endl;
    return true;
  }
};

int main() {
  GoalKeeper gk1("Ron Weasley", 5, 3, 4, 10, 20);
  Catcher ct1("Harry Potter", 3, 2, 6, 10);
  Scout sc1("Jimmy Peaks", 3, 6, 4, 8), 
    sc2("Ritchie Coose", 3, 6, 3, 7);
  Gunner gn1("Demelza Robina", 5, 7, 3, 8), 
    gn2("Ginny Weasley", 10, 7, 3, 2),
    gn3("Katie Bell", 2, 7, 4, 4);

  GoalKeeper gk2("Miles Bletchley", 5, 3, 4, 10, 50);
  Catcher ct2("Draco Malfoy", 5, 3, 5, 20);
  Scout sc3("Vincent Crabbe", 3, 6, 4, 8), 
    sc4("Gregory Goyle", 3, 6, 3, 7);
  Gunner gn4("Graham Montague", 5, 7, 3, 8), 
    gn5("Adrian  Pacey", 10, 7, 3, 2),
    gn6("Cassius Warrington", 2, 7, 4, 0);

  QuidditchTeam q1("Gryffindor"), q2("Slytherin");

  q1.insertPlayer(gk1);
  q1.insertPlayer(ct1);
  q1.insertPlayer(sc1);
  q1.insertPlayer(sc2);
  q1.insertPlayer(gn1);
  q1.insertPlayer(gn2);
  q1.insertPlayer(gn3);

  q2.insertPlayer(gk2);
  q2.insertPlayer(ct2);
  q2.insertPlayer(sc3);
  q2.insertPlayer(sc4);
  q2.insertPlayer(gn4);
  q2.insertPlayer(gn5);
  q2.insertPlayer(gn6);

  Match m;

  m.play(q1, q2);

  q1.alterPlayer(0, sc4);

  m.play(q1, q2);

  return 0;
}