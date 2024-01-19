#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WEEKS 1000000

int prices[MAX_WEEKS];
int n;

int max_price_in_halving_period() {
  // Inicializa o pre�o m�ximo como o primeiro pre�o.

  int max_price = prices[0];

  // Percorre a lista de pre�os procurando o maior pre�o.

  for (int i = 1; i < n; i++) {
    if (prices[i] > max_price) {
      max_price = prices[i];
    }
  }

  return max_price;
}

int main() {
  // Entrada.

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &prices[i]);
  }

  // Sa�da.

  printf("%d\n", max_price_in_halving_period());

  return 0;
}