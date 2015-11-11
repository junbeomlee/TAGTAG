#ifndef CLIENT_CONTROLLER
#define CLIENT_CONTROLLER

#include <WinSock2.h>
#include <winsock.h>
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <process.h>
#include <vector>
#include "Subject.h"

#define MESSAGE_OPTION 2

using namespace std;

class ClientController : public Subject{

private:

	ClientController(){}
	static ClientController* ClientController::clientControllerInstance;
	vector<Observer*> clientObserver;
	IoData* newIoData;

public:

	~ClientController(){
		free(ClientController::clientControllerInstance);
		for (int i = 0; i < this->clientObserver.size(); i++){
			free(this->clientObserver.at(i));
		}
	}

	static ClientController* getInstance();

	void removeBySock(SockData* sockData);
	virtual void add(Observer* newObsever);
	virtual void remove(Observer* delObserver);
	virtual void notify(IoData* ioData, SockData* newSockData);
};

#endif