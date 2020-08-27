#ifdef __IDEFINE_H
#define  __IDEFINE_H

#include<vector>

#ifdef __WIN32_  // win 下
#include<winsock2.h>
#pragma comment(lib,"ws2_32")

#endif 

#define MAX_USER_SOCKETFD 10000000  //预开辟的最大内存,
#define MAX_EXR_LEN  200   //字符串最大长度
#define MAX_FILENAME_LEN  250   //文件名最大长度
#define SIO_KEEPALIVE_VALS IOC_IN|IOC_VENDOR|4  //心跳包宏定义
#define MAX_MD5_LEN  35   //MD5码长度
#define MAX_IP_LEN   20   //IP长度


#define LOG_MSG printf //输出打印的宏


#ifdef __WIN32_
#define RELEASE_ROINTER(p){if(p~=NULL){delete p;p=NULL;}}  //释放指针
#define RELEASE_HANDLE(h) {if(h!=NULL&&h!=INVALID_HANDLE_VALUE)  //释放句柄
		{CloseHandle(h); h = INVALID_HANDLE_VALUE; }}
#define RELEASE_SOCKET(s)  (if(s!=INVALID_SOCKET)  //释放Socket
#endif 

		//定义数据类型别名,简化内置数据类型名字
		typedef signed char         s8;
		typedef signed short        s16;
		typedef signed int          s32;
		typedef signed long long    s64;
		typedef unsigned char       u8;
		typedef unsigned short      u16;
		typedef unsigned int        u32;
		typedef unsigned __int64    u64;

		//定义socket状态
		namespace func {
			enum SOCKET_CLOSE
			{
				S_CLOSE_FREE = 0,
				S_CLOSE_ACCERT = 1,//连接出错关闭
				S_CLOSE_SHUTDOWN = 2,//关闭连接
				S_CLOSE_CLOSE = 3//正式关闭
			};

			enum SOCKET_CONTEXT_STATEl
			{
				SC_WAIT_ACCEPT = 0,
				SC_WCIT_RECV = 1,
				SC_WAIT_SEND = 2,
				SC_WAIT_RESET = 3
			};

			enum S_SOCKET_STATEl //服务器状态
			{
				S_Free = 0,
				S_Connect = 1,
				S_ConnectSecure = 2,
				S_Login = 3,
				S_NeedSave = 4
				S_Saving = 5
			};

			//基础配置
			struct  ConfigXML
			{
				s32 ID;//标记当前应用程序启动的ID是多少
				u8  Type;//服务器类型，中心服务器，网关服务器~
				u16 Port;//常用的端口号
				s32 MaxPlayer;//最大玩家数
				s32 MaxConnect;//最大连接数量
				u8  RCode;//用于加密数据
				s32 Version;//版本号，用于验证？？
				s32 ReceOne;//服务端最多一次接收多少数据
				s32 ReceMax;//服务端接收缓冲区
				s32 SendOne;//服务端最多一次发送多少数据
				s32 SendMax;//服务端发送缓冲区
				s32 HeartTime;//心跳时间
				s32 MaxAccpet;//用于IOCP连接，投递连接用的 ,IO对象回收池？？？
				s32 MaxRece;//最大接收信息数量
				s32 MaxSend;//最大发送信息数量
				char SafeCode[20];//用于加密，当产生一个新的连接时，通过RCode和SafeCode生成一个md5码发送服务端发送一条数据，服务端也会进行此操作生成一个md5码进行匹配。若不匹配，就会断了这个连接
				char Head[3];//消息头，用于安全验证？
				char IP[MAX_IP_LEN];
			};

			//服务端基础配置
			struct  ServerListXML
			{
				s32 ID;
				u16 Port;
				char IP[MAX_IP_LEN];
			};

			//声明全局变量
			extern char FildExePath[MAX_EXE_LEN];
			extern ConfigXML* __ServerInfo;
			extern ConfigXML* __ClientInfo;
			extern std::vector<ServerListXML*>__ServerListInfo;

			extern void (*MD5str)(char* output, unsigned char* input, int len);

			extern bool InitData();//初始化数据的入口
		}

#endif

