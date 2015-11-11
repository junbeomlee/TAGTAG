#include "WorkerThread.h"

unsigned WINAPI WorkerThread::ThreadMain(LPVOID thread){

	WorkerThread* workerThread = (WorkerThread*)thread;
	workerThread->run();
	return 0;

}
void WorkerThread::createThread(){

	_beginthreadex(NULL, 0, &WorkerThread::ThreadMain, (LPVOID)this, 0, NULL);

}

void WorkerThread::run(){

	SOCKET sock;
	DWORD bytesTrans;
	IoData* newIoData;
	SockData* newSockData;

	while (1){

		GetQueuedCompletionStatus(this->completionPort, &bytesTrans, (LPDWORD)&newSockData, (LPOVERLAPPED*)&newIoData, INFINITE);

		if (bytesTrans == 0){ //->socket close
			this->clientController->removeBySock(newSockData);
			continue;
		}

		if (newIoData->rwMode == READ){

			///head-> type이랑 size만빼서 확인 하고 type에 따라서 구조체에 memcpy하고 구조체를 넘겨서 처리

			puts("message received");
			memset(&(newIoData->overlapped), 0, sizeof(OVERLAPPED));
			newIoData->wasBuf.len = bytesTrans;
			newIoData->rwMode = WRITE;
			this->clientController->notify(newIoData, newSockData);
		}else{
			cout << "message sent";
		}
	}
}
void WorkerThread::setSockData(SockData* sockData){
	this->sockData.clientAddr = sockData->clientAddr;
	this->sockData.clientSock = sockData->clientSock;
}

void WorkerThread::setCP(HANDLE completionPort){
	this->completionPort = completionPort;
}