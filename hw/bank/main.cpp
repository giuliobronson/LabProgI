#include <iostream>

using namespace std;

typedef struct stats {
  float averageTime;
  int dropouts;
} stats;

class Client 
{
private:
  string name;
  int timeArrival;
  int serviceDuration;

public:
  Client(string name, int timeArrival, int serviceDuration) : 
  name(name), timeArrival(timeArrival), serviceDuration(serviceDuration) {
  }

  string getName() {
    return name;
  }

  int getTimeArrival() {
    return timeArrival;
  }

  int getServiceDuration() {
    return serviceDuration;
  }

  void incrementTime() {
    timeArrival++;
  }
};

class CommonClient : public Client
{
private:
  int maxWainting;

public:
  CommonClient(string name, int timeArrival, int serviceDuration, int maxWainting) : 
  Client(name, timeArrival, serviceDuration), maxWainting(maxWainting) {
  }

  int getMaxWaiting() {
    return maxWainting;
  }
};

class PreferredClient : public Client 
{
public:
  PreferredClient(string name, int timeArrival, int serviceDuration) :
  Client(name, timeArrival, serviceDuration) {
  }
};

class Bank 
{
private:
  int maxClients;
  int nCClients;
  int nPClients;
  CommonClient **cclients;
  PreferredClient **pclients;

public:
  Bank(int maxClients) : maxClients(maxClients), nCClients(0), nPClients(0),
  cclients(new CommonClient*[maxClients]), pclients(new PreferredClient*[maxClients]) {
    for(int i = 0; i < maxClients; i++) {
      cclients[i] = NULL; 
      pclients[i] = NULL;
    }
  }

  Bank(const Bank &b) : maxClients(b.maxClients), nCClients(b.nCClients), nPClients(b.nPClients),
  cclients(new CommonClient*[maxClients]), pclients(new PreferredClient*[maxClients]) {
    for(int i = 0; i < maxClients; i++) {
      cclients[i] = b.cclients[i]; 
      pclients[i] = b.pclients[i];
    }
  }

  ~Bank() {
    delete[] cclients;
    delete[] pclients;
  }

  bool insertClient(CommonClient &cc) {
    if(nCClients + nPClients > maxClients) return false;
    cclients[++nCClients - 1] = &cc;
    return true;
  }

  bool insertClient(PreferredClient &pc) {
    if(nCClients + nPClients > maxClients) return false;
    pclients[++nPClients - 1] = &pc;
    return true;
  }

  stats simulate() {
    float tTotal = 0;
    int minute = 0;
    int cclient = 0, pclient = 0;
    int tCommonSrv = 0, tPreferredSrv = 0;
    int dropouts = 0;
    while(cclient + pclient < nCClients + nPClients) {
      minute++; tCommonSrv++; tPreferredSrv++;
      for(int i = cclient; i < nCClients; i++) {
        if(!cclients[i]) continue;
        cclients[i]->incrementTime();
        if(i != cclient && cclients[i]->getMaxWaiting() < cclients[i]->getTimeArrival()) {
          cout << minute << " " << cclients[i]->getName() << " gave up waiting" << endl;
          cclients[i] = NULL;
          dropouts++;
        }
      }
      for(int i = pclient; i < nPClients; i++) {
        if(!pclients[i]) break;
        pclients[i]->incrementTime();
      }
      if(cclient != nCClients && !cclients[cclient]) {
        cclient++; 
        tCommonSrv = 0;
      }
      else if(cclient != nCClients && cclients[cclient]->getServiceDuration() == tCommonSrv) {
        cout << minute << " " << cclients[cclient]->getName() << " was attended" << endl;
        tTotal += cclients[cclient]->getTimeArrival() - cclients[cclient]->getServiceDuration();
        cclient++; tCommonSrv = 0;
      }
      if(pclient == nPClients || !pclients[pclient]) continue;
      else if(pclients[pclient]->getServiceDuration() == tPreferredSrv) {
        cout << minute << " " << pclients[pclient]->getName() << " was attended" << endl;
        tTotal += pclients[pclient]->getTimeArrival() - pclients[pclient]->getServiceDuration();
        pclient++; tPreferredSrv = 0;
      }
    }

    stats st;
    st.dropouts = dropouts;
    st.averageTime = tTotal / (nCClients + nPClients - dropouts);
    return st;
  }
};

int main() {
  Bank b(10);
  CommonClient cc1("João", 1, 3, 5);
  CommonClient cc2("José", 2, 4, 6);
  CommonClient cc3("Luiz", 3, 5, 2);
  PreferredClient pc1("Maria", 1, 3);
  PreferredClient pc2("Ana", 2, 4);
  PreferredClient pc3("Jorge", 3, 5);

  b.insertClient(cc2);
  b.insertClient(cc1);
  b.insertClient(cc3);
  b.insertClient(pc2);
  b.insertClient(pc3);
  b.insertClient(pc1);

  stats st = b.simulate();
  cout << st.averageTime << " " << st.dropouts << endl;

  return 0;
}