#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXI 10000
typedef struct{
	char Item[MAXI];
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
void push (pilha *p , char x){
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

	for(i=0; i<larg;i++){ 
		for(j=0;j<alt;j++){
			fscanf(image, "%c", &RGB[i][j].r );
			push(p , &RGB[i][j].r);
            fscanf(image, "%c", &RGB[i][j].g );
            push(p , &RGB[i][j].r);
	       	fscanf(image, "%c", &RGB[i][j].b );
	       	push(p , &RGB[i][j].r);
		}
	}
	for(i=0; i<larg;i++){ 
		for(j=0;j<alt;j++){
			
		if((RGB[i][j].r == RGB[1][1].r)&&( RGB[i][j].g == RGB[1][1].g)&&( RGB[i][j].b == RGB[1][1].b)){
			if(j == larg-1){
				printf(" \n");
			}
			else{
			
		   	printf(" ");
		    }
		    }
		else{
				if(j == larg-1){
				printf("|\n");
			}
			else{
			
		   	printf("|");
		    }
		    }
			
	    }
	}
	
	

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
