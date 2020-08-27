#include "INetBase.h"

#include<time.h>
#include<string>

#ifdef __WIN32_

#else
#include<limits.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h> //这里为啥没有自动提示
#endif // __WIN32_


namespace func {
	//声明全局变量
	char FildExePath[MAX_EXE_LEN];
	ConfigXML* __ServerInfo = NULL;
	ConfigXML* __ClientInfo = NULL;
	std::vector<ServerListXML*>__ServerListInfo;

	void (*MD5str)(char* output, unsigned char* input, int len) = NULL;

	bool InitData() //初始化数据的入口
	{
		return false;
	}

}


namespace net {

	void net::S_CLIENT_BASE::Init()
	{
		//开辟内存空间
		recvBuf = new char[func::__ServerInfo->ReceMax];
		sendBuf = new char[func::__ServerInfo->SendMax];
		Reset();
	}

	void net::S_CLIENT_BASE::Reset()
	{
#ifdef  __WIN32_
		socketfd = INVALID_SOCKET;
#else
		socketfd = -1;
#endif //  __WIN32_
		port = 0;
		ID = -1;
		rCode = func::__ServerInfo->RCode;
		//接收数据的初始化
		recv_Head = 0;
		recv_Tail= 0;
		recv_TempHead = 0;
		recv_TempTail = 0;
		is_RecvCompleted = false;
		
		//发送数据初始化
		send_Head = 0;
		send_Tail = 0;
		send_TempTail = 0;
		is_Sending = false;
		is_SendCompleted = true;
		//时间类
		threadID = 0;
		time_Connect = (int)time(NULL);
		time_Heart = (int)time(NULL);
		time_Close = (int)time(NULL);

		//设置recvBuf和sendBuf,ip
		memset(recvBuf, 0, func::__ServerInfo->ReceMax);
		memset(sendBuf, 0, func::__ServerInfo->ReceMax);
		memset(ip, 0, MAX_IP_LEG);

		closeState = 0;
		state = func::S_Free;
	}

}


