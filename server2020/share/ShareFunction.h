#ifndef  ____SHAREFUNCTION_H
#define  ____SHAREFUNCTION_H 

#define CMD_REIGSTER      100
#define CMD_UPDATELOGIN   200
#define CMD_CREATEROLE    300

#define CMD_LOGIN      1000
#define CMD_MOVE       2000
#define CMD_PLAYERDATA 3000
#define CMD_LEAVE      4000

#define USER_MAX_MEMBER 20


#include "IDefine.h"

namespace share
{
	enum E_MEMBER_STATE
	{
		M_FREE = 0x00,	//ʹ��-����
		M_REQUESTING,   //��������������
		M_LOGIN,		//ʹ��-��¼��
		M_SAVING,       //������
		M_LIMIT 		//����		
	};


#pragma pack(push,packing)
#pragma pack(1)
	struct S_VECTOR
	{
		f32 x;
		f32 y;
		f32 z;
	};
	struct  S_PLAYER_BASE
	{
		s32  memid;
		s32  socketfd;
		s32  state;
		s32  curhp;
		s32  maxhp;
		f32  speed;
		S_VECTOR   pos;
		S_VECTOR   rot;
		char  nick[20];
		inline void init()
		{
			memset(this, 0, sizeof(S_PLAYER_BASE));
		}
	};


	//�˺���Ϣ
	struct S_USER_MEMBER_BASE
	{
		inline bool IsT() const { return ID > 0; }
		inline bool IsT_ID(const __int64 id) { return (ID == id); }
		inline bool IsT_Name(const char* fname) { return (stricmp(name, fname) == 0); };

		E_MEMBER_STATE			state;      //�˺�״̬
		int					    ID;         //�˺�Ψһ��� 
		char					name[USER_MAX_MEMBER];   //�˺� 
		char                    password[USER_MAX_MEMBER];//����
		int						timeCreate;//�˺Ŵ���ʱ��
		int						timeLastLogin;//�ϴε�¼ʱ��
	};



	struct S_REGISTER_BASE
	{
		int         socketfd;
		int		    ID;
		char name[USER_MAX_MEMBER];
		char password[USER_MAX_MEMBER];
	};

	struct S_LOGIN_BASE
	{
		int         socketfd;
		int64_t		ID;
	};

	

#pragma pack(pop, packing)

	extern bool InitData();

}


#endif