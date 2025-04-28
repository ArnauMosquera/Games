#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int carta(void){
    int num;
    num =rand()%6+6;
    if(num==11){
        num=1;
    }
    return num;
}
void estat2(int user,int dealer){
    printf("Tens: %d\nEl dealer te: %d\n",user,dealer);
}
void estat(int n){
    printf("Tens: %d\n",n);
}
bool comprovar(int user, int dealer){
    bool final = false;
    if((user>21)&&(dealer<=21)){
        printf("Has perdut, tu tens %d i el dealer %d\n",user,dealer);
        final=true;
    } else if ((dealer>21)&&(user<=21)){
        printf("Has guanyat, tu tens %d i el dealer %d\n",user,dealer);
        final=true;
    } else if (dealer==user){
        printf("Empat a %d", user);
        final = true;
    } else if (dealer>user){
        printf("Has perdut, tu tens %d i el dealer %d\n",user,dealer);
    } else if (user>dealer){
        printf("Has guanyat, tu tens %d i el dealer %d\n",user,dealer);
    }
    return final;
}
int main(void){
    int op, dealer, user;
    bool continuar=true;
    srand(time(NULL));
    dealer=0;user=0;
    user +=carta();
    dealer +=carta();
    estat2(user, dealer);
    do {
        printf("1.Demanar carta\n2.Plantar-se\n");
        scanf("%d",&op);
        switch (op) {
            case 1:
                user +=carta();
                dealer +=carta();
                if((user>=21)||(dealer>21)){
                    continuar = ! comprovar(user, dealer);
                }
                break;
            case 2:
                while (continuar){
                    dealer +=carta();
                    continuar = !comprovar(user, dealer);
                }
            default:
                break;
        }
        if (continuar){
            estat(user);
        }
    } while (continuar);
    return 0;
}
