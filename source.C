#include <source.h>


Image *Source::GetOutput(){
	return &(this->img);
}

void Source::Update(){
	Execute();
}
