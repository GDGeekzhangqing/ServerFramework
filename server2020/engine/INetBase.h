#ifndef  __INETBASE_H

#define __INETBASE_H

#include "IDefine.h"

namespace net {
#pragma pack(push,packing)
#pragma pack(1)//һ�ֽڶ���
	//�ͻ���������������
	struct  S_CLIENT_BASE_INDEX
	{
		s32 index;
		inline void Reset() { index = -1; }
	};

	//�ͻ�����������
	struct  S_CLIENT_BASE
	{
#ifdef __WIN32_
		SOCKET socketfd;
#else
		int  socketfd;
#endif 
		s8 state;
		s8 closeState;
		char ip[MAX_IP_LEN];
		u16 port;
		s32 ID;//��ǰ��������ID Ҳ�������±�
		u8 rCode;//��򣬻������룿
		s32 ClientID;
		u8 ClientType;
		//��������
		bool is_RecvCompleted;
		char* recvBuf;
		char* recvBuf_Temp;//һ�ο��Խ��ն�������
		s32 recv_Head;//���recv_Head����recv_Tail˵�����ݷ������
		s32 recv_TempTail;
		s32 recv_TempHead;
		s32 recv_TempTail;

		//��������
		bool is_Sending;
		bool is_SendCompleted;
		char* sendBuf;//���ͻ�����
		s32  send_Head;//���send_Head����send_Tail˵�����ݷ������
		s32  send_Tail;
		s32  send_TempTail;

		//ʱ����
		s32 time_Connect;
		s32 time_Heart;
		s32 time_Close;
		u8  threadID;
		s32 shutdown_kind;
		char md5[MAX_MD5_LEN];

		void Init();
		void Reset();

#ifdef __WIN32_
		inline bool isT(SOCKET fd)
		{
			if (socketfd == fd) return true;
			return false;
		}
#else
		inline bool isT(int fd)
		{
			if (socketfd == fd)
				return true;
			return false;
		}
#endif 
	};

#pragma pack(pop,packing)   

	class  ITcpServer;
	typedef bool(*TCPSERVERNOTIFY_EVENT)(ITcpServer *tcp,S_CLIENT_BASE*c,const s32 code);
    

	class ITcpServer {
	public:
		virtual ~ITcpServer() {	}
		virtual void runServer(int num) = 0;
#ifdef __WIN32_
		virtual S_CLIENT_BASE* client(SOCKET fd, bool issecurity) = 0;
#else  //Linuxƽ̨��
		virtual S_CLIENT_BASE* client(int fd, bool issecurity) = 0;

#endif
		virtual S_CLIENT_BASE* client(int index) = 0;
	};



	extern ITcpServer* NewTcpServer();

}

#endif

