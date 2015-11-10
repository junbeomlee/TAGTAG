#ifndef WORKER_THREAD_H
#define WORKER_THREAD_H

#include <WinSock2.h>
#include <winsock.h>
#include <iostream>
#include <process.h>
#include <Windows.h>
#include <stdlib.h>
#include "ClientController.h"

#pragma comment(lib,"Ws2_32.lib")

using namespace std;

class WorkerThread{

private:
	HANDLE completionPort;
	SockData sockData;
	ClientController* clientController;
public:

	WorkerThread();
	WorkerThread(ClientController* clientController){
		this->clientController = clientController;
	};

	void createThread();
	void run();
	void setSockData(SockData* sockData);
	static unsigned WINAPI ThreadMain(LPVOID thread);
	void setCP(HANDLE completionPort);
};

#endif