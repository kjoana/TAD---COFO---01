#define TRUE 1
#define FALSE 0

typedef struct  _cofo_ Cofo;

Cofo *criarCofo(int maxItens);
int destruirCofo(Cofo *c);
int inserirCofo (Cofo *c, int item);
int removerCofo(Cofo *c, int key);
int verificarCofo (Cofo *c, int key);
void mostrarCofo (Cofo *c);
