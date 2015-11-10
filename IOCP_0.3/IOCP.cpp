#include "IOCP.h"

int IOCP::run(){

	SYSTEM_INFO sysInfo;
	if (WSAStartup(MAKEWORD(2, 2), &this->wsadata) != 0){
		cout << " error WSAStartUp";
		return 1;
	}
	this->completionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);

	GetSystemInfo(&sysInfo);

	for (int i = 0; i < sysInfo.dwNumberOfProcessors; i++){

		WorkerThread newThread(this->clientController);// thread가 ClientController 알고 있다.
		newThread.setCP(this->completionPort);
		newThread.createThread();

	}

	this->setServerPort();

	while (1){
		//this->acceptClient();
		int recvBytes = 0;
		int flags = 0;
		SOCKET clientSock;
		SOCKADDR_IN clientSockAddr;
		int addrLen = sizeof(clientSockAddr);

		clientSock = accept(this->serverSock, (SOCKADDR*)& clientSockAddr, &addrLen);
		
		if (clientSock == INVALID_SOCKET){
			cout << GetLastError();
			return 0;
		}
		/// client에 sock 저장
		



		SockData* newSock = new SockData();
		newSock->clientSock = clientSock;
		memcpy(&(newSock->clientAddr), &clientSockAddr, addrLen);

		Client* newClient = new Client(newSock);
		this->clientController->add(newClient);

		//this->clientController->addSock(newSock);

		CreateIoCompletionPort((HANDLE)newSock->clientSock, this->completionPort, (DWORD)newSock, 0);//->cp랑 clinetSock이랑 연결

		IoData* newIoData = this->createIoData();
		WSARecv(newSock->clientSock, &(newIoData->wasBuf), 1, (LPDWORD)&recvBytes, (LPDWORD)&flags, &(newIoData->overlapped), NULL);// ->recv를 기다린다
		//this->sockVectors.push_back(newSock);// cLIENT에 대한 소켓 정보 저장
	}

	return 0;
}
int IOCP::setServerPort(){

	this->serverSock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	memset(&this->serverAddr, 0, sizeof(serverAddr));
	this->serverAddr.sin_family = AF_INET;
	this->serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	this->serverAddr.sin_port = htons(PORT);
	bind(this->serverSock, (SOCKADDR*)&this->serverAddr, sizeof(this->serverAddr));
	listen(this->serverSock, 5);

	return 0;
}

IoData* IOCP::createIoData(){

	IoData* tempIoData = new IoData();
	memset(&(tempIoData->overlapped), 0, sizeof(OVERLAPPED));
	tempIoData->wasBuf.len = BUF_SIZE;
	tempIoData->wasBuf.buf = tempIoData->buffer;
	tempIoData->rwMode = READ;

	return tempIoData;
}