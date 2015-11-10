#include "Client.h"


void Client::setSock(SockData* sockData){
	this->mySockData = sockData;
}

void Client::update(IoData* ioData, int option){
	/// 넘어온 ioData에 따라 operation처리
	//cout << this->mySockData->clientAddr.sin_addr.S_un.S_addr;
	//cout << ioData->wasBuf.buf;
	
	WSASend(this->mySockData->clientSock, &(ioData->wasBuf), 1, NULL, 0, &(ioData->overlapped), NULL);


	ioData = new IoData();
	memset(&(ioData->overlapped), 0, sizeof(OVERLAPPED));
	ioData->wasBuf.len = BUF_SIZE;
	ioData->wasBuf.buf = ioData->buffer;
	ioData->rwMode = READ;
	int flags = 0;
	WSARecv(this->mySockData->clientSock, &(ioData->wasBuf), 1, NULL, (LPDWORD)&flags, &(ioData->overlapped), NULL);
}