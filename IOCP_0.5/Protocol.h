#ifndef PROTOCOL_
#define PROTOCOL_


//HEADER�� type,size ����
#define PACKET_TYPE_GAME_MOVE 103
struct{
	int userIndex;
	float x;
	float y;
	float z;
}PACKET_MOVE_MSG;

#define PACKET_TYPE_GAME_TOUCH 104
struct{
	int userIndex; //-> ������ ���� user
}PACKET_GAME_TOUCH_MSG;


#define PACKET_TYPE_GAME_START 102//->������ ������� �����ѹ� �ֱ� clientController�� �������ִ� client index�ֱ�
struct{
	int userIndex; //��� �������� ->������ ���� index �ֱ� 
}PACKET_GAME_START_MSG;



#define PACKET_TYPE_GAME_END 105
struct{
	int userIndex; //-> ���� index�ֱ�
}PACKET_GAME_END_MSG;


#define PACKET_TYPE_CONNECT 101
struct{
	int userIndex; //->�������� index��ȣ �˷��ֱ�
}PACKET_CONNECT_MSG;

#endif