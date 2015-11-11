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
protected:
	SockData* mySockData;
	IoData* myIoData;
public:
	virtual void update(IoData* ioData, int option) = 0;

	void setSock(SockData* newSock){
		this->mySockData = newSock;
	};

	SockData* getSock(){
		return this->mySockData;
	};
	~Observer(){
		delete mySockData;
		delete myIoData;
	};
	Observer(){

	}
};

#endif