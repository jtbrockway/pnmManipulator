#ifndef FILTERS_H
#define FILTERS_H
#include <source.h>
#include <sink.h>
#include <image.h>

class filters:public Source, public Sink{
	public:
		virtual void Update();
};

class Shrinker:public filters{

	public:
		void Execute();
};

class LRConcat:public filters{

	public:
		void Execute();
};

class TBConcat:public filters{

	public:
		void Execute();
};

class Blender:public filters{
	private:
		float factor;

	public:
		void SetFactor(float);
		float getFactor();
		void Execute();
};

#endif
