#ifndef SUBJECT_
#define SUBJECT_

#include "Observer.h"

class Subject{

public:
	virtual void add(Observer* newObserver) = 0;
	virtual void remove(Observer* delObserver) = 0;
	virtual void notify(IoData* IoData, SockData* newSockData) = 0;
};

#endif