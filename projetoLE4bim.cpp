#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
 int b, a;
 char nomes[3];
 float totalpontosano[3], notasAUX[3], notexa, mediasbimestrais[3][4], tudo[3];
 
 void dici(){
 	for(b=0; b<=2; b++){
 		printf("Digite a diciplina do técnico:\n");
 		scanf("%s",&nomes[b]);
 	}
 }
 
 void notas(char nome[1], int ind){
	for(a=0; a<=3; a++){
		printf("digite a %d nota da diciplina %c\n", a+1, nome[ind]);
		scanf("%f", &mediasbimestrais[ind][a]);
		while((mediasbimestrais[ind][a]<0.0)||(mediasbimestrais[ind][a]>10.0)) {
			printf("Nota inválida! Redigite:\n");
			scanf("%f", &mediasbimestrais[ind][a]);
			fflush(stdin);
		}
	}
 }
 
 float soma(int ip){
 	float r;
 		r=0;
		for(a=0; a<=3; a++){
			r=r+mediasbimestrais[ip][a];
		}
 	return r;
 }
 
 void exame(float &l, int fr){
 	float lk;
 	lk=totalpontosano[fr];
 	lk=10-(lk/4);
 	l=lk;
 }

main(){
	setlocale(LC_ALL, "Portuguese");
	
	dici();	
	
	for(b=0; b<=2; b++){
		notas(nomes, b);
	}
	
	for(b=0; b<=2; b++){
		totalpontosano[b]=soma(b);
	}
	
	system("cls");
	
	printf("Pontuação:\n");
	
	for(b=0; b<=2; b++){
		printf("%c: %f pontos\n",nomes[b], totalpontosano[b]);	
	}
	
	printf("\n");
	
	for(b=0; b<=2; b++){
		if(totalpontosano[b]>=24.0){
			printf("Aprovado em %c\n", nomes[b]);
			printf("\n");	
		}else{
			if(totalpontosano[b]<15.0){
				printf("Reprovado em %c\n", nomes[b]);
				printf("\n");	
			}else{
				printf("EXAME FINAL em %c\n", nomes[b]);
				
				exame(totalpontosano[b], b);
				
				printf("Nota necessária é %f\n", totalpontosano[b]);
				printf("Digite sua nota no Exame:\n");
				scanf("%f", &notexa);
				
				while((notexa<0)||(notexa>10)){
					printf("Nota inválida! Redigite:\n");
					scanf("%f",&notexa);
					fflush(stdin);
				}
				if(notexa>=totalpontosano[b]){
					printf("RESULTADO APÓS EXAME: APROVADO em %c\n", nomes[b]);
					printf("\n");	
				}else{
					printf("RESULTADO APÓS EXAME: REPROVADO em %c\n", nomes[b]);
					printf("\n");
				}
			}
		}
	}
}
