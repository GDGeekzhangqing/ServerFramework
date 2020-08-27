#ifdef __IDEFINE_H
#define  __IDEFINE_H

#include<vector>

#ifdef __WIN32_  // win ��
#include<winsock2.h>
#pragma comment(lib,"ws2_32")

#endif 

#define MAX_USER_SOCKETFD 10000000  //Ԥ���ٵ�����ڴ�,
#define MAX_EXR_LEN  200   //�ַ�����󳤶�
#define MAX_FILENAME_LEN  250   //�ļ�����󳤶�
#define SIO_KEEPALIVE_VALS IOC_IN|IOC_VENDOR|4  //�������궨��
#define MAX_MD5_LEN  35   //MD5�볤��
#define MAX_IP_LEN   20   //IP����


#define LOG_MSG printf //�����ӡ�ĺ�


#ifdef __WIN32_
#define RELEASE_ROINTER(p){if(p~=NULL){delete p;p=NULL;}}  //�ͷ�ָ��
#define RELEASE_HANDLE(h) {if(h!=NULL&&h!=INVALID_HANDLE_VALUE)  //�ͷž��
		{CloseHandle(h); h = INVALID_HANDLE_VALUE; }}
#define RELEASE_SOCKET(s)  (if(s!=INVALID_SOCKET)  //�ͷ�Socket
#endif 

		//�����������ͱ���,������������������
		typedef signed char         s8;
		typedef signed short        s16;
		typedef signed int          s32;
		typedef signed long long    s64;
		typedef unsigned char       u8;
		typedef unsigned short      u16;
		typedef unsigned int        u32;
		typedef unsigned __int64    u64;

		//����socket״̬
		namespace func {
			enum SOCKET_CLOSE
			{
				S_CLOSE_FREE = 0,
				S_CLOSE_ACCERT = 1,//���ӳ���ر�
				S_CLOSE_SHUTDOWN = 2,//�ر�����
				S_CLOSE_CLOSE = 3//��ʽ�ر�
			};

			enum SOCKET_CONTEXT_STATEl
			{
				SC_WAIT_ACCEPT = 0,
				SC_WCIT_RECV = 1,
				SC_WAIT_SEND = 2,
				SC_WAIT_RESET = 3
			};

			enum S_SOCKET_STATEl //������״̬
			{
				S_Free = 0,
				S_Connect = 1,
				S_ConnectSecure = 2,
				S_Login = 3,
				S_NeedSave = 4
				S_Saving = 5
			};

			//��������
			struct  ConfigXML
			{
				s32 ID;//��ǵ�ǰӦ�ó���������ID�Ƕ���
				u8  Type;//���������ͣ����ķ����������ط�����~
				u16 Port;//���õĶ˿ں�
				s32 MaxPlayer;//��������
				s32 MaxConnect;//�����������
				u8  RCode;//���ڼ�������
				s32 Version;//�汾�ţ�������֤����
				s32 ReceOne;//��������һ�ν��ն�������
				s32 ReceMax;//����˽��ջ�����
				s32 SendOne;//��������һ�η��Ͷ�������
				s32 SendMax;//����˷��ͻ�����
				s32 HeartTime;//����ʱ��
				s32 MaxAccpet;//����IOCP���ӣ�Ͷ�������õ� ,IO������ճأ�����
				s32 MaxRece;//��������Ϣ����
				s32 MaxSend;//�������Ϣ����
				char SafeCode[20];//���ڼ��ܣ�������һ���µ�����ʱ��ͨ��RCode��SafeCode����һ��md5�뷢�ͷ���˷���һ�����ݣ������Ҳ����д˲�������һ��md5�����ƥ�䡣����ƥ�䣬�ͻ�����������
				char Head[3];//��Ϣͷ�����ڰ�ȫ��֤��
				char IP[MAX_IP_LEN];
			};

			//����˻�������
			struct  ServerListXML
			{
				s32 ID;
				u16 Port;
				char IP[MAX_IP_LEN];
			};

			//����ȫ�ֱ���
			extern char FildExePath[MAX_EXE_LEN];
			extern ConfigXML* __ServerInfo;
			extern ConfigXML* __ClientInfo;
			extern std::vector<ServerListXML*>__ServerListInfo;

			extern void (*MD5str)(char* output, unsigned char* input, int len);

			extern bool InitData();//��ʼ�����ݵ����
		}

#endif

