#ifndef COMMON
#define COMMON

#define READ 3
#define WRITE 5
#define BUF_SIZE 1024

typedef struct{
	SOCKET clientSock;
	SOCKADDR_IN clientAddr;
}SockData;

typedef struct{
	OVERLAPPED overlapped;
	WSABUF wasBuf;
	char buffer[BUF_SIZE];
	int rwMode;
}IoData;

typedef struct {
	int size;
	int type;
}Header;

typedef struct {
	Header header;
	char buffer[1024];
}Packet;

///-> wasbuf에 압축해서 보내기

#endif