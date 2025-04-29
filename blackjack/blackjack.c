#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blackjack.h"

int carta(void) {
    int num = rand() % 6 + 6;
    return (num == 11) ? 1 : num;
}

void mostrar_estat(int user, int dealer) {
    printf("Tens: %d\nEl dealer té: %d\n", user, dealer);
}

void mostrar_user(int user) {
    printf("Tens: %d\n", user);
}

int comprovar(int user, int dealer) {
    if ((user > 21 && dealer <= 21) || (dealer > user && dealer <= 21 && user <= 21)) {
        printf("Has perdut, tu tens %d i el dealer %d\n", user, dealer);
        return -1;
    } else if ((dealer > 21 && user <= 21) || (user > dealer && dealer <= 21 && user <= 21)) {
        printf("Has guanyat, tu tens %d i el dealer %d\n", user, dealer);
        return 1;
    } else if (user == dealer && user <= 21) {
        printf("Empat a %d\n", user);
        return 0;
    } else if (user > 21 && dealer > 21) {
        printf("Tots dos heu perdut! Tu tens %d i el dealer %d\n", user, dealer);
        return -1;
    }
    return 0;
}

void jugar_sessio(void) {
    int op, resultat;
    char resposta;
    int partides = 0, guanyades = 0, perdudes = 0;

    do {
        int user = carta();
        int dealer = carta();
        bool continuar = true;
        partides++;

        mostrar_estat(user, dealer);

        while (continuar) {
            printf("1. Demanar carta\n2. Plantar-se\n");
            scanf("%d", &op);

            if (op == 1) {
                user += carta();
                dealer += carta();
                resultat = comprovar(user, dealer);
                if (resultat != 0) continuar = false;
            } else if (op == 2) {
                while (continuar) {
                    dealer += carta();
                    resultat = comprovar(user, dealer);
                    if (resultat != 0) continuar = false;
                }
            } else {
                printf("Opció no vàlida.\n");
            }

            if (continuar) {
                mostrar_user(user);
            }
        }

        if (resultat == 1) guanyades++;
        else if (resultat == -1) perdudes++;

        printf("\nVols jugar una altra partida? (s/n): ");
        scanf(" %c", &resposta);

    } while (resposta == 's' || resposta == 'S');

    printf("\n--- Resum de la sessió ---\n");
    printf("Partides jugades: %d\n", partides);
    printf("Guanyades: %d\n", guanyades);
    printf("Perdudes: %d\n", perdudes);
    printf("--------------------------\n");
}
