# Alocação Dinâmica

## *Ponteiros*

- São tipos de variáveis que armazenam endereços de memória.

- Ponteiros sempre ocupam o mesmo tamanho na memória já que sempre se referem ao endereçamento de variáveis. Independem do tipo de variável para o qual aponta.

### Aplicações

- Acessar endereços de memória que o programa aloca em tempo de execução

- Acessar variáveis fora do escopo de uma função 

- Manipulação de listas

- Manipulação de cadeia de caracteres

- Passar o endereço de uma função

- Retornar mais de um valor para uma função

### Sintaxe

```c
  int *ptr;
```
```c
  var == *ptr; // Derreferenciamento
  ptr == &var; // Endereço de 
```

- Ao declarar um ponteiro sem inicializá - lo ele apontará para uma área aleatória da memória.

### Aritmética de Ponteiros

- Ao somar 1 ao ponteiro estaremos nos referindo ao próximo endereço de memória do tipo da variável ao qual se referem.

- Ponteiros podem ser comparados.

### Ponteiros e Matrizes

- Vetores e matrizes são ponteiros fixos para o endereço de memória dos seus primeiros elementos.

### Ponteiro para Ponteiros e Indireção Múltipla

- Um ponteiro pode apontar para outro ponteiro que aponta para um valor.

```c
  int x, *p, **q;

  x = 10; 
  p = &x; // p aponta para x
  q = &p; // q aponta para p
```

### Ponteiros como Parâmetros de Funções

```c
int valor(int a) {
  a = 35;
}

a = 30;
valor(a); // a não é 35
```

```c
int ponteiro(int *a) {
  *a = 35;
}

a = 30;
ponteiro(&a); // a é 35
```

### Alocação Dinâmica

- Permitir alocar memória em tempo de execução.

- Há 4 funções principais para alocação dinâmica pertencentes a biblioteca: `stdlib.h`
  1. `malloc()`
  2. `calloc()`
  3. `realloc()`
  4. `free()`

- `malloc()` e `calloc()` são responsáveis por alocar memória.

- `realloc()` é responsável por realocar memória.

- `free()` libera a memória.

## Alocação Dinâmica

- Ações realizadas:

  1. Determinar a quantidade de memória necessária

  2. Solicitar ao sistema a quantidade de memória necessária

  3. Utilizar a memória alocada

  4. Devolver ao sistema a região de memória após o seu uso

### `malloc()`

```c
  void *malloc(size_t tamanho);
```

- Em nenhum momento é passado o tipo do ponteiro como argumento.

- Recebe o número de bytes necessários.

- Retorna um ponteiro para uma região de memória alocada dinamicamente.

- Se não houver espaço para alocação `malloc()` retorna `NULL`.

```c
int main() {
  int *vetor, n;

  // Espaço de memória a ser alocada
  scanf("%d", &n); 
  // Casting
  vetor = (int*)malloc(n * sizeof(int));
  // Se não houve espaço para alocação
  if(vetor == NULL) {
    printf("Erro: Memória insuficiente");
    return -1;
  }
  else {
    // Libaração do espaço após o uso
    free(vetor);
  }
}
```

- Toda alocação dinâmica utiliza a memória Heap (região de memória livre do computador).

### `free()`

```c
  void *free(void *ptr);
```

- Libera a região alocada no sistema.

- Apenas libera regiões de memória alocadas com `malloc()`.

- A mesma região de memória só pode ser liberada uma vez.

### `calloc()`

```c
  void *calloc(size_t nelements, size_t elementSize);
```

- Similar a `malloc()`, porém inicializa a área com valores nulos.

### `realloc()`

```c
  void *calloc(void *ptr, size_t size);
```

- Retorna um ponteiro para a área de memória com tamanho especificado, contendo os mesmos dados do ponteiro anterior.

- Se houver falha na realocação, mantém o ponteiro original inalterado e retorna `NULL`.

## Diretivas de Compilação

- Comandos não - compiláveis dirigidos ao pré - processador.

- O pré - processador altera o programa fonte segundo essa diretiva.

##  Tipos de Dados Definidos pelo Usuário

### Struct

- Agrupa vários tipos em um só.

- Serve para aagrupar tipos de dados diferentes formando um novo tipo de dados.

```c
  struct pessoa {
    char[20] nome;
    char[20] telefone;
    int idade;
  } var;
```

```c
  typedef struct tipo ficha_pessoal {
    char nome[50];
    char[20] telefone;
    int idade;
  } TFicha;
```

### Enum

- Permite definir tipos de ddados por meio de valores limitados ordenados.

- Cada valor é denotado por um identificador não - ambíguo.

```c
  enum dias_da_semana {domingo, segunda, terca, quarta, quinta, sexta, sabado};
```