#ifndef IOCP_H
#define IOCP_H

#include<WinSock2.h>
#include<winsock.h>
#include<Windows.h>
#include<process.h>
#include<iostream>
#include<vector>
#include "WorkerThread.h"
#include "ClientController.h"
#include "Client.h"

#pragma comment(lib,"Ws2_32.lib")

using namespace std;

#define PORT 22222

class IOCP{

private:

	WSADATA wsadata;
	HANDLE completionPort; // cp
	//vector<SockData*> sockVectors; // clinetSock 정보 담는곳
	SOCKET serverSock;
	SOCKADDR_IN serverAddr;
	ClientController* clientController;

public:
	IOCP();
	IOCP(ClientController* clientController){
		this->clientController = clientController;
	}
	int run();
	int acceptClient();
	int setServerPort();
	IoData* createIoData();
};


#endif