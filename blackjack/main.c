#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "blackjack.h"

int main(void) {
    char resposta;
    srand(time(NULL));

    do {
        printf("\n--- Nova sessió ---\n");
        jugar_sessio();
        printf("Vols iniciar una nova sessió? (s/n): ");
        scanf(" %c", &resposta);
    } while (resposta == 's' || resposta == 'S');

    printf("Fins aviat!\n");
    return 0;
}
