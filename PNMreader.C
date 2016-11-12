#include <PNMreader.h>
#include <string.h>
#include <stdio.h>

PNMreader::PNMreader(char *filename){
	file = new char[strlen(filename) + 1];
	int i;
	for(i = 0; i <= strlen(filename); i++){
		file[i] = filename[i];
	}
}

void PNMreader::Execute(){
	FILE *pic = fopen(file, "rb");
	Image *image = GetOutput();

	int width, height;
	
	fscanf(pic, "P6\n%d %d\n 255\n", &(width), &(height));
	
	image->SetSize(width, height);
	image->setData(width, height);
	Pixel *buffer = image->getData();

	fread(buffer, sizeof(Pixel), width * height, pic);

	fclose(pic);
}

PNMreader::~PNMreader(){
	delete[] file;
	delete[] image;
}
