#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	unsigned char r,g,b; //struct dos pixels em RGB;
}pixel;

int main(){
	git remote add origin https://github.com/RafaeloXIII/1.git
git push -u origin master
	FILE *image;
	FILE *newImage;


	char key[5];
	int i,j, larg, alt, max;

	image = fopen("02.ppm", "rb");
	if(image == NULL)
	{
		printf("Erro na abertura do arquivo \n");
		return 0;
	}


	fscanf(image, "%s", key);


	fscanf(image, "%d %d\n%d\n", &larg, &alt, &max);
	printf("larg =%d alt=%d key=%s max=%d\n",larg, alt, key,max );

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
		   
			fscanf(image, "%c", &RGB[i][j].g );
		
			fscanf(image, "%c", &RGB[i][j].b );
			if((RGB[i][j].r == 255)&&( RGB[i][j].g == 255)&&( RGB[i][j].b == 255)){
		   	printf(" ");
		   }
		   else{
		   	printf("/");
		   }
			
		}
	}
	

	fprintf(newImage, "P6\n%d %d\n%d\n",larg,alt,max);
	for(i=0;i<larg;i++){
		for(j=0;j<alt; j++){
			fprintf(newImage, "%c%c%c", RGB[i][j].r, RGB[i][j].g, RGB[i][j].b );
			
		}
	} 
	fclose(image);
	fclose(newImage);
return 0;
}
