#include "Client.h"


void Client::update(IoData* ioData, int option){
	/// 넘어온 ioData에 따라 operation처리
	//cout << this->mySockData->clientAddr.sin_addr.S_un.S_addr;
	//cout << ioData->wasBuf.buf;
	
	WSASend(this->mySockData->clientSock, &(ioData->wasBuf), 1, NULL, 0, &(ioData->overlapped), NULL);

	//delete this->myIoData;

	this->myIoData = new IoData();
	memset(&(this->myIoData->overlapped), 0, sizeof(OVERLAPPED));
	this->myIoData->wasBuf.len = BUF_SIZE;
	this->myIoData->wasBuf.buf = this->myIoData->buffer;
	this->myIoData->rwMode = READ;
	int flags = 0;

	WSARecv(this->mySockData->clientSock, &(this->myIoData->wasBuf), 1, NULL, (LPDWORD)&flags, &(this->myIoData->overlapped), NULL);
}