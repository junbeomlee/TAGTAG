#include "ClientController.h"

ClientController* ClientController::clientControllerInstance;

ClientController* ClientController::getInstance(){

	if (clientControllerInstance == nullptr){
		clientControllerInstance = new ClientController();

	}

	return clientControllerInstance;
}


void ClientController::add(Observer* newObserver){
	this->clientObserver.push_back(newObserver);
}

void ClientController::remove(Observer* delObserver){
	for (int i = 0; i < this->clientObserver.size(); i++){
		if (this->clientObserver.at(i) == delObserver){
			this->clientObserver.erase(this->clientObserver.begin() + i);
		}
	}
}

void ClientController::notify(IoData* ioData,SockData* newSockData){
	for (int i = 0; i < this->clientObserver.size(); i++){
		int sendMessage = 1;
		
		if (ioData->buffer == 0){
			this->remove(this->clientObserver.at(i)); //Á¾·á
		}
		else{
			this->clientObserver.at(i)->update(ioData, sendMessage);
		}
	}
}