#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  BST tree = createEmptyTree();
  int choice, value;

  do {
    printf("\nSelecione a operacao:\n");
    printf("1. Inserir elemento na arvore\n");
    printf("2. Remover elemento da arvore\n");
    printf("3. Consultar se um elemento esta na arvore\n");
    printf("4. Listar os elementos da arvore\n");
    printf("5. Destruir a arvore vazia\n");
    printf("0. Sair\n");

    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Digite o elemento a ser inserido: ");
      scanf("%d", &value);
      insertElement(&tree, value);
      printf("Elemento inserido na arvore.\n");
      break;
    case 2:
      printf("Digite o elemento a ser removido: ");
      scanf("%d", &value);
      removeElementFromTree(&tree, value);
      printf("Elemento removido da arvore.\n");
      break;
    case 3:
      printf("Digite o elemento a ser procurado: ");
      scanf("%d", &value);
      if (isElementInTree(tree, value)) {
        printf("%d esta na arvore.\n", value);
      } else {
        printf("%d nao esta na arvore.\n", value);
      }
      break;
    case 4:
      if (tree.root == NULL) {
        printf("Arvore vazia.\n");
      } else {
        printf("Elementos da arvore: ");
        listElements(tree);
        printf("\n");
      }
      break;
    case 5:
      destroyEmptyTree(&tree);
      printf("Arvore vazia destruida.\n");
      break;
    case 0:
      printf("Saindo do programa.\n");
      break;
    default:
      printf("Opcao invalida.\n");
    }
  } while (choice != 0);

  return 0;
}
