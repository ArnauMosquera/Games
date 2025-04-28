#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void crear_tauler(int n, int *taula[n][n]){
    if(n>MAX){
        printf("La mida del tauler ha de ser igual o inferior al maxim %d",MAX);
        exit(1);
    }
    int tauler[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tauler[i][j]=rand()%2;
        }
    }
}




int main(void){
    srand(time(NULL));
    
    
    return 0;
}
