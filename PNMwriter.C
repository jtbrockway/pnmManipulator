#include <PNMwriter.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void PNMwriter::Write(char *filename){
	char *file = new char[strlen(filename) + 1];
	int i;
	for(i = 0; i <= strlen(filename); i++){
		file[i] = filename[i];
	}

	Image *image = GetInput();

	FILE *writePic = fopen(file, "w");
	fprintf(writePic, "P6\n");
	
	fprintf(writePic, "%d %d\n", image->getWidth(), image->getHeight());
	fprintf(writePic, "255\n");

	fwrite(image->getData(), sizeof(Pixel), image->getWidth() * image->getHeight(), writePic);

	fclose(writePic);
	delete[] file;
}
