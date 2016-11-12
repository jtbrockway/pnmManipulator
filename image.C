#include <image.h>
#include <stdlib.h>
#include <stdio.h>
#include <source.h>

void Image::SetSource(Source *src){
	this->source = src;
}

void Image::Update(){
	this->source->Update();
}

Image::Image(void){
	this->xPix = 0;
	this->yPix = 0;
	this->data = NULL;
}

Image::Image(int width, int height, Pixel *pixels){
	this->xPix = width;
	this->yPix = height;
	this->data = pixels;
	fprintf(stderr, "Here\n");
}

Image::Image(Image &img){
	this->xPix = img.xPix;
	this->yPix = img.yPix;
	this->data = (Pixel *)malloc(xPix * yPix * sizeof(Pixel));

	for(int i = 0; i < xPix * yPix; i++){
		this->data[i] = img.data[i];
	}
}

void Image::ResetSize(int width, int height){
	this->xPix = width;
	this->yPix = height;
}

void Image::SetSize(int width, int height){
	this->xPix = width;
	this->yPix = height;
}

void Image::setData(int width, int height){
	if(this->data != NULL){
		free(this->data);
	}
	data = (Pixel *)malloc(sizeof(Pixel) * width * height);

}

int Image::getWidth(){
	return this->xPix;
}

int Image::getHeight(){
	return this->yPix;
}

Pixel * Image::getData(){
	return this->data;
}

