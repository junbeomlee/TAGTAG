#include<stdio.h>
#include"IOCP.h"

int main(){
	
	ClientController* clientController = ClientController::getInstance();
	IOCP IOCP(clientController);
	IOCP.run();
	return 0;
}