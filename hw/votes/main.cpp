#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

struct Candidate 
{
    int votes;
    int number;
    string name;
    string party;

    Candidate(int number, string name, string party) : votes(0), number(number), 
    name(name), party(party) {
    }

    Candidate(const Candidate &c) : votes(c.votes), number(c.number), name(c.name), party(c.party) {
    }

    Candidate operator++(int) {
        Candidate c(*this);
        this->votes++;
        return c;
    }

    bool operator<(Candidate rhs) {
        return votes < rhs.votes;
    }
};

int main() {
    vector<Candidate> candidates;
    ifstream file; file.open("candidatos.txt", ios::in);
    if(!file.is_open()) return 1;
    while(true) {
        int number; string name, party;
        file >> number >> name >> party;
        if(file.eof()) break;
        candidates.push_back(Candidate(number, name, party));
    }
    file.close();

    for(int i = 1; i < 5; i++) {
        ostringstream aux; aux << "urna" << i << ".txt";
        ifstream file; file.open(aux.str(), ios::in);
        while(true) {
            int n;
            file >> n;
            if(file.eof()) break;
            candidates[n - 1]++;
        }
        file.close();
    }

    sort(candidates.rbegin(), candidates.rend());

    for(vector<Candidate>::iterator it = candidates.begin(); it != candidates.end(); it++) {
        cout << it->name << " - " << it->votes << endl;
    }

    return 0;
}