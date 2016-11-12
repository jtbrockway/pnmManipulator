#include <filters.h>
#include <stdio.h>
#include <stdlib.h>

void filters::Update(){
	
	if(img1 != NULL){
		img1->Update();
	}
	
	if(img2 != NULL){
		img2->Update();
	}

	Execute();
}

void Shrinker::Execute(){
	Image *image = GetInput();
	Image *writeImage = GetOutput();

	writeImage->SetSize(image->getWidth()/2, image->getHeight()/2);
	writeImage->setData(writeImage->getWidth(),writeImage->getHeight());

	int i,j;

	for(i = 0; i < writeImage->getHeight(); i++){
		for(j = 0; j < writeImage->getWidth(); j++){
			writeImage->getData()[i * writeImage->getWidth() + j] = image->getData()[4 * i * writeImage->getWidth() + (2*j)];
		}
	}
}

void LRConcat::Execute(){
	Image *img1 = GetInput();
	Image *img2 = GetInput2();

	Image *writeImage = GetOutput();

	writeImage->SetSize((img1->getWidth() + img2->getWidth()), img2->getHeight());
	writeImage->setData(writeImage->getWidth(), writeImage->getHeight());

	int i,j;

	for(i = 0; i < writeImage->getHeight(); i++){
		for(j = 0; j < writeImage->getWidth(); j++){
			if( j < img1->getWidth()){
				writeImage->getData()[i * writeImage->getWidth() + j] = img1->getData()[i * img1->getWidth() + j];
			}else{
				writeImage->getData()[i * writeImage->getWidth() + j] = img2->getData()[i * img2->getWidth() + (j - img1->getWidth())];
			}
		}
	}
}

void TBConcat::Execute(){
	Image *img1 = GetInput();
	Image *img2 = GetInput2();

	Image *writeImage = GetOutput();

	writeImage->SetSize(img1->getWidth(), (img1->getHeight() + img2->getHeight()));
	writeImage->setData(writeImage->getWidth(), writeImage->getHeight());

	int i,j;

	for(i = 0; i < writeImage->getHeight(); i++){
		for(j = 0; j < writeImage->getWidth(); j++){
			if( i < img1->getHeight()){
				writeImage->getData()[i * writeImage->getWidth() + j] = img1->getData()[i * img1->getWidth() + j];
			}else{
				writeImage->getData()[i * writeImage->getWidth() + j] = img2->getData()[(i - img1->getHeight()) * img2->getWidth() + j];
			}
		}
	}
}

void Blender::SetFactor(float factor){
	this->factor = factor;
}

float Blender::getFactor(){
	return this->factor;
}

void Blender::Execute(){
	float factor = getFactor();
	float factor2 = 1- getFactor();

	Image *img1 = GetInput();
	Image *img2 = GetInput2();

	Image *writeImage = GetOutput();

	writeImage->SetSize(img1->getWidth(), img1->getHeight());
	writeImage->setData(writeImage->getWidth(), writeImage->getHeight());

	int i,j;

	for(i = 0; i < writeImage->getHeight(); i++){
		for(j = 0; j < writeImage->getWidth(); j++){
			int index = i * writeImage->getWidth() + j;
			writeImage->getData()[index].red = img1->getData()[index].red * factor + (img2->getData()[index].red * factor2);
			writeImage->getData()[index].green = img1->getData()[index].green * factor + img2->getData()[index].green * factor2;
			writeImage->getData()[index].blue = img1->getData()[index].blue * factor + img2->getData()[index].blue * factor2;
		}
	}
}

