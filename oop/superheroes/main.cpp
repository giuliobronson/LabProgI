#include <iostream>

using namespace std;

class Superpoder {
  private:
    string nome;
    int categoria;
  
  public:
    Superpoder(string nome, int categoria):
      nome(nome), categoria(categoria) {
    }

    string getNome() {
      return this->nome;
    }

    int getCategoria() {
      return this->categoria;
    }
};

class Personagem {
  private:
    string nome;
    string nomeVidaReal;
    Superpoder **poderes;
    int nPoderes;

  public:
    Personagem(string nome, string nomeVidaReal): 
      nome(nome), nomeVidaReal(nomeVidaReal),
      poderes(new Superpoder*[4]), nPoderes(0) {
    }

    Personagem(const Personagem &p):
      nome(p.nome), nomeVidaReal(p.nomeVidaReal), 
      poderes(new Superpoder*[4]), nPoderes(p.nPoderes) {
        for(int i = 0; i < nPoderes; i++) 
          poderes[i] = p.poderes[i];
    }
    
    ~Personagem() {
      delete[] poderes;
    }

    string getNome() {
      return this->nome;
    }

    string getNomeVidaReal() {
      return this->nomeVidaReal;
    }

    bool adicionaSuperpoder(Superpoder &sp);

    double getPoderTotal();
};

bool Personagem::adicionaSuperpoder(Superpoder &sp) {
  if(nPoderes == 4) return false;
  poderes[nPoderes++] = &sp;
  return true;
}

double Personagem::getPoderTotal() {
  double total = 0;
  for(int i =0; i < nPoderes; i++)
    total += poderes[i]->getCategoria();
  return total;
}

class SuperHeroi: public Personagem {
  public:
    SuperHeroi(string nome, string nomeVidaReal):
      Personagem(nome, nomeVidaReal) {
    }

    double getPoderTotal() {
      return Personagem::getPoderTotal() * 1.1;
    }
};

class Vilao: public Personagem {
  private:
    int tempoDePrisao;
  public:
    Vilao(string nome, string nomeVidaReal, int tempoDePrisao):
        Personagem(nome, nomeVidaReal), tempoDePrisao(tempoDePrisao) {
    }

    double getPoderTotal() {
      return Personagem::getPoderTotal() * (1 + .01 * tempoDePrisao);
    }
};

int main() {
  Superpoder s("voar", 2);

  cout << s.getNome() << " " << s.getCategoria() << endl;

  return 0;
}