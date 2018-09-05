#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXI 10000
typedef struct{
	int Item[MAXI];
	int top;
}pilha;
 
 void i_pilha (pilha *p)
{
     p->top = -1;
}
int pilha_vazia (pilha *p)
{
    if (p->top == -1)
    {
         printf ("nada aqui amigao");
         return 1;
    }
    else
     return 0;
}
void push (pilha *p , int x){
	p->top++;
	p->Item[p->top] = x ;
}
char pop (pilha *p){
	int aux;
	if(pilha_vazia(p)== 1){
		printf ("nada aqui amigao");
	}
	else{
		aux = p->Item[p->top];
		p->top--;
		return aux;
	}
}

typedef struct{
	unsigned char r,g,b; 
}pixel;

int main(){
	int k;
	int obj = 0;
	unsigned char r0, g0, b0;
	int** dados;
	pilha *p = (pilha*)malloc(sizeof(pilha));
	i_pilha(p);

	FILE *image;
	FILE *newImage;

	char key[5];
	int i,j, larg, alt, max;

	image = fopen("01.ppm", "rb");
	if(image == NULL)
	{
		printf("Arquivo nao abriu :( \n");
		return 0;
	}


	fscanf(image, "%s", key);


	fscanf(image, "%d %d\n%d\n", &larg, &alt, &max);
	printf("larg =%d alt=%d max=%d\n",larg, alt,max );

	newImage = fopen("arquivo.txt","wb+"); 
	if(newImage == NULL){
		printf("ERRO AO ABRIR NEWIMAGE");
		return 0;
	}
	
	pixel **RGB =(pixel**)malloc(larg*sizeof(pixel*));
	for(i=0;i<larg;i++){						
		RGB[i] = (pixel*)malloc(alt*sizeof(pixel));

	}
		
		dados = (int**)malloc(alt*sizeof(int*));
	for(i=0;i<alt;i++){						
		dados[i] = (int*)malloc(larg*sizeof(int));
		for(j = 0; j<larg; j++ ){
		dados[i][j];
		}
   }

	for(i=0; i<larg;i++){ 
		for(j=0;j<alt;j++){
			fscanf(image, "%c", &RGB[i][j].r );
			
            fscanf(image, "%c", &RGB[i][j].g );
            
	       	fscanf(image, "%c", &RGB[i][j].b );
	       	
		}
	}
		r0 = RGB[0][0].r ;
			g0 = RGB[0][0].g ;
            b0 = RGB[0][0].b ; 
	for(i=0; i<larg;i++){ 
		for(j=0;j<alt;j++){
				
		if((RGB[i][j].r == r0)&&( RGB[i][j].g == g0)&&( RGB[i][j].b ==b0)){
			dados[i][j] = 0;
 		if(j == larg-1){
				
				printf(" \n");
				
			}
			else{
			
		   	printf(" ");
		    }
		    }
		else{
			 dados[i][j] = 1;
				if(j == larg-1){
				printf("|\n");
			}
			else{
			
		   	printf("|");
		    }
		    }
			
	    }
	}
	for(i=0; i<alt;i++){ 
		for(j=0;j<larg;j++){
			if(dados[i][j] == 1){
				dados[i][j] == 3;
				while(1){
					if(dados[i+1][j] == 1){
						dados[i+1][j] = 3;
						push(p , dados[i+1][j]);
					}
					if(dados[i-1][j] == 1){
						dados[i-1][j] = 3;
						push(p , dados[i-1][j]);
					}
					if(dados[i][j+1] == 1){
						dados[i][j+1] = 3;
						push(p , dados[i][j+1]);
					}
					if(dados[i][j-1] == 1){
						dados[i][j-1] = 3;
						push(p , dados[i][j-1]);
					}
				k = pilha_vazia(p);
					if(k == 0){
						pop(p);
						k = pilha_vazia(p);
					}
					else{
						break;
					}
				}
				
				
			
			 
			}
				   
		 }
		}
	printf("%d", obj);
	

	fprintf(newImage, "P6\n %d %d \n %d \n",larg,alt,max);
	for(i=0;i<larg;i++){
		for(j=0;j<alt; j++){
			fprintf(newImage, "%c%c%c", RGB[i][j].r, RGB[i][j].g, RGB[i][j].b );
			
		}
	} 
	fclose(image);
	fclose(newImage);
return 0;
}
