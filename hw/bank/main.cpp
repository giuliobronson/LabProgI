#include <iostream>

using namespace std;

typedef struct stats {
  float averageTime;
  int dropouts;
} stats;

class Client {
  private:
    string name;
    int timeSinceArrival;
    int serviceDuration;

  public:
    Client(string name, int timeSinceArrival, int serviceDuration):
    name(name), timeSinceArrival(timeSinceArrival), serviceDuration(serviceDuration) {
    }

    string getName() {
      return name;
    }

    int getTimeSinceArrival() {
      return timeSinceArrival;
    }

    int getServiceDuration() {
      return serviceDuration;
    }

    void incrementTime() {
      timeSinceArrival++;
    }
};

class CommonClient:public Client {
  private:
    int maxWaintingTime;
  public:
    CommonClient(string name, int timeSinceArrival, int serviceDuration, int maxWaintingTime):
    Client(name, timeSinceArrival, serviceDuration), maxWaintingTime(maxWaintingTime) {
    }

    int getMaxWaintingTime() {
      return maxWaintingTime;
    }
};

class PreferredClient:public Client {
  public:
    PreferredClient(string name, int timeSinceArrival, int serviceDuration):
    Client(name, timeSinceArrival, serviceDuration) {
    }
};

class Bank {
  private:
    int numberOfClients;
    int maxCapacity;
    Client **queue;
  
  public:
    Bank(int maxCapacity):
    numberOfClients(0), maxCapacity(maxCapacity), queue(new Client*[maxCapacity]) {
    }

    Bank(const Bank &b): numberOfClients(b.numberOfClients) {
      for(int i = 0; i < numberOfClients; i++) queue[i] = b.queue[i];
    }

    ~Bank() {
      delete[] queue;
    }

    bool insertClient(Client &c);

    stats simulate();
};

bool Bank::insertClient(Client &c) {
  if(numberOfClients + 1 > maxCapacity) return false;
  queue[++numberOfClients - 1] = &c;
  return true;
}

stats Bank::simulate(){
  float time = 0;
  int min = 0, client = 0, dropouts = 0, service = 0;
  while(client < numberOfClients) {
    min++; service++;
    for(int i = client; i < numberOfClients; i++) {
      if(!queue[i]) continue; 
      queue[i]->incrementTime();
      CommonClient *ptr = (CommonClient*) queue[i];
      if(i != client && ptr->getMaxWaintingTime() < ptr->getTimeSinceArrival()) {
        cout << min << " " << ptr->getName() << " gave up waiting" << endl;
        queue[i] = NULL;
        dropouts++;
      }
    }
    if(!queue[client]) {
      client++; service = 0;
      continue;
    }
    else if(queue[client]->getServiceDuration() == service) {
      cout << min << " " << queue[client]->getName() << " was attended" << endl;
      time += queue[client]->getTimeSinceArrival() - queue[client]->getServiceDuration();
      client++; service = 0;
    }
  }

  stats st;
  st.dropouts = dropouts;
  st.averageTime = time / (numberOfClients - dropouts);
  return st;
}

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