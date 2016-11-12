#ifndef IMAGE_H
#define IMAGE_H

#include <stdlib.h>

struct Pixel{
	unsigned char red, green, blue;
};

class Source;

class Image
{
	private:
		int xPix;
		int yPix;

		Pixel *data;
		Source *source;


	public:
		Image(void);
		Image(int, int, Pixel *); 
		Image(Image &);
		~Image(){if(data!=NULL)free(this->data);};

		void ResetSize(int, int);
		void SetSize(int, int);

		virtual void Update();
		void SetSource(Source *);

		void setData(int, int);
		int getWidth();
		int getHeight();
		Pixel *getData();
};

#endif
