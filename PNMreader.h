#ifndef PNMreader_H
#define PNMreader_H
#include <source.h>

class PNMreader:public Source{
	
	private:
		char *file;

	public:
		PNMreader(char *);
		~PNMreader();

		void Execute();
};

#endif
