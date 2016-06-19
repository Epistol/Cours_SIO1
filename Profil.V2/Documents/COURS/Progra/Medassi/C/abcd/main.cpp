
/* Standard Libraries */
#include <stdio.h>   // input and output
#include <string.h>  // strlen()
#include <ctype.h>   // toupper()
#include <stdlib.h>  // exit()
#include <time.h>    // srand(), rand()




void recherche(char caractere, char chaine[255]) {
for (int i=0;i<255;i++){
    if(chaine[i]==caractere){
        printf("Trouvé !");
        i = 255;
    }
}
}

int main(){


bool recherche(char caractere, char chaine[255])
{
    bool retour = false;
    for(int i=0;i<255;i++)
    {

    if(chaine[i]==caractere){
        retour = true;
    }
    }
    return retour;
}

}








