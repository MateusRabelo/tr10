#include <stdio.h>
#include <stdlib.h>


int main(){
   
   	//variables that can be used
   	unsigned int vetor[200];
   	int bit_locale, num, bit_index, i, j;
   	
    //cleaning memory trash
    for (i = 0; i < 200; i++){
        vetor[i] = 0;
    }

    //basic menu with a mini description
    printf("\n\nOpa, seja bem-vindo\n\n\n");
    printf("Adicione numeros entre 0 e 5000\n\n");
    printf("Digite -1 para imprimir os numeros em ordem crescente,\nsem repetir ");
    printf("e encerrar o programa\n\n");

    //while True, run
    while(1){

        //number input
        scanf("%d", &num);
        
        //number condition verification
        if(num >= 0 && num <= 5000){
            //finding the bit locale and bit index with the remainder by 32 and division by 32 (respectively)
            bit_locale = num % 32; bit_index = num / 32;

            //snapping the bits in the correct place with bitwise operators
            vetor[bit_index] = (1 << bit_locale) | vetor[bit_index];

        //condition to quit and print
        }else if(num == -1){
            //print "printing"
            printf("\nImprimindo...\n\n");
            break;

        }else{
            //message error
            printf("\n\nValor invalido, irmao :/\npor favor, tente novamente\n\n");
        }
    }

    //finding and fitting the correct bit vector(index)
    for(i = 0; i < 200; i++){
        for(j = 0; j < 32; j++){
            if((vetor[i] >> j) & 1){
                printf("%d\n", j + i * 32);
            }
        }
    }
   	
   	//#########################
   
	return 0;  
}