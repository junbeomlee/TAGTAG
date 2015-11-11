#ifndef CLIENT_
#define CLIENT_


#include "Observer.h"

#include <iostream>

using namespace std;

class Client : public Observer{

private:
	
public:
	Client();
	Client(SockData* sockData,IoData* ioData){
		this->mySockData = sockData;
		this->myIoData = ioData;
	}
	void virtual update(IoData* ioData, int option);
};

#endif