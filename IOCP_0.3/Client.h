#ifndef CLIENT_
#define CLIENT_


#include "Observer.h"

#include <iostream>

using namespace std;

class Client : public Observer{

private:
	SockData* mySockData;
public:
	Client();
	Client(SockData* SockData){
		this->mySockData = SockData;
	}
	void virtual update(IoData* ioData, int option);
	void setSock(SockData* newSock);
};

#endif