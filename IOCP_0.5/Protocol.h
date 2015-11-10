#ifndef PROTOCOL_
#define PROTOCOL_


//HEADER인 type,size 빼고
#define PACKET_TYPE_GAME_MOVE 103
struct{
	int userIndex;
	float x;
	float y;
	float z;
}PACKET_MOVE_MSG;

#define PACKET_TYPE_GAME_TOUCH 104
struct{
	int userIndex; //-> 동물로 만들 user
}PACKET_GAME_TOUCH_MSG;


#define PACKET_TYPE_GAME_START 102//->접속한 순서대로 고유넘버 주기 clientController가 가지고있는 client index주기
struct{
	int userIndex; //모든 유저에게 ->동물로 변할 index 주기 
}PACKET_GAME_START_MSG;



#define PACKET_TYPE_GAME_END 105
struct{
	int userIndex; //-> 동물 index주기
}PACKET_GAME_END_MSG;


#define PACKET_TYPE_CONNECT 101
struct{
	int userIndex; //->유저한테 index번호 알려주기
}PACKET_CONNECT_MSG;

#endif