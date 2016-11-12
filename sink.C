#include <sink.h>
#include <stdio.h>

Sink::Sink(){
	this->img1 = NULL;
	this->img2 = NULL;
}

void Sink::SetInput(Image *in){
	this->img1 = in;
}

void Sink::SetInput2(Image *in){
	this->img2 = in;
}

Image *Sink::GetInput(){
	return this->img1;
}

Image *Sink::GetInput2(){
	return this->img2;
}
