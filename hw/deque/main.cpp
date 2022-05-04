#include <iostream>

using namespace std;

enum dequeMode {front = 0, back};

class Deque {
  private:
    int begin, end;
    int maxSize;
    int *deque;
  
  public:
    Deque(int maxSize):begin(maxSize), end(maxSize), maxSize(maxSize), deque(new int[maxSize]) {
    }

    Deque(const Deque &d):begin(d.begin), end(d.end), maxSize(d.maxSize), deque(new int[maxSize]) {
      for(int i = 0; i < maxSize; i++) deque[i] = d.deque[i];
    }

    ~Deque() {
      delete[] deque;
    }

    int getBegin() {
      return begin;
    }

    int getEnd() {
      return end;
    }

    int getMaxSize() {
      return maxSize;
    }

    void printDeque() {
      if(begin == maxSize && end == maxSize) return;
      for(int i = 0; i < (end - begin + maxSize) % maxSize; i++) 
        cout << deque[(begin + i) % maxSize] << " ";
      cout << endl;
    }

    void insert(int key, dequeMode dm);

    void remove(dequeMode dm);
};

void Deque::insert(int key, dequeMode dm) {
  if(begin == maxSize && end == maxSize) { // Empty deque
    begin = 0; end = 0;
    deque[begin] = key;
  }
  else if(begin == (end + 1) % maxSize) return; // Full deque
  else if(dm == front) {
    begin = (maxSize + begin - 1) % maxSize;
    deque[begin] = key;
  }
  else {
    end = (end + 1) % maxSize;
    deque[end] = key;
  }
}

void Deque::remove(dequeMode dm) {
  if(begin == maxSize && end == maxSize) return;
  else if(begin == end) { begin = maxSize; end = maxSize; }
  else if(dm == front)
    begin = (begin + 1) % maxSize;
  else 
    end = (maxSize + end - 1) % maxSize;
}

class Queue:public Deque {
  public:
    Queue(int maxSize):Deque(maxSize) {
    }

    void insert(int key) {
      Deque::insert(key, back);
    }

    void remove() {
      Deque::remove(front);
    }
};

int main() {
  Deque d(6);

  d.insert(10, front);
  d.insert(20, front);
  d.insert(30, front);
  d.insert(40, back);
  d.insert(60, back);
  d.insert(50, back);
  
  d.printDeque();
  d.remove(back);
  d.remove(front);
  d.printDeque();

  Queue q(6);

  q.insert(10);
  q.insert(20);
  q.insert(30);
  q.insert(40);
  q.insert(60);
  q.insert(50);
  
  q.printDeque();
  q.remove();
  q.printDeque();

  return 0;
}