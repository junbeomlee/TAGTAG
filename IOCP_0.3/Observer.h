#ifndef OBSERVER_
#define OBSERVER_

#include <WinSock2.h>
#include <winsock.h>
#include <Windows.h>


#include <iostream>
#include <stdlib.h>
#include <process.h>
#include <vector>
#include "Protocol.h"
#include "Common.h" 

class Observer{
public:
	virtual void update(IoData* ioData, int option) = 0;
};

#endif