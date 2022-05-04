# Aula 3 - Revisão de C

## Abrindo e Fechando um Arquivo

- Ponteiro de arquivo
  - Não é um tipo propriamente dito
  - Declaração de ponteiro para arquivo `FILE *p;`
  - p será um ponteiro para um arquivo

### `fopen()`

```c
  FILE *fopen(char *nome_do_arquivo, char *modo);
```

- O nome do arquivo determina o arquivo a ser aberto.

- Caminho absoluto ou relativo.

- Modo = tipo de uso para o arquivo.

### Modos de Abertura de Arquivos

Modo   | Siginificado
------ | -------------
w      | Gravação. Se o arquivo já existir ele será sobrescrito
a      | Dados adicionados no fim do arquivo
r+     | Leitura e gravação
w+     | Gravação e leitura
a+     | Gravação e leitura. Dados adicionados no fim do arquivo

### Fechando Arquivos

- Todo arquivo deve ser fechado
  - Garantia da escrita
  - Liberação de recurso

```c
  int fclose(FILE *arquivo);
```