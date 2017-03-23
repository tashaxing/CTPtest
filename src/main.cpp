#include <iostream>
#include <string>
#include "CustomMdSpi.h"

using namespace std;

// 链接库
#pragma comment (lib, "thostmduserapi.lib")
#pragma comment (lib, "thosttraderapi.lib")

// ---- 全局变量 ---- //
CThostFtdcMdApi *g_pUserApi = nullptr;                             // 行情指针
char gFontAddr[] = "tcp://180.168.146.187:10010";                  // 模拟行情前置地址
TThostFtdcBrokerIDType gBrokerID = "9999";                         // 模拟经纪商代码
TThostFtdcInvestorIDType gInvesterID = "081097";                   // 投资者账户名
TThostFtdcPasswordType gInvesterPassword = "asdfqwer";             // 投资者密码
//char *g_pInstrumentID[] = {"TF1706", "al1712", "cs1801", "CF705"}; // 行情合约代码列表，中、上、大、郑交易所各选一种
char *g_pInstrumentID[] = {"ni1701", "rb1701"};
int instrumentNum = 4;                                             // 行情合约订阅数量

int main()
{
	cout << "初始化行情..." << endl;
	// 初始化行情
	g_pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();   // 创建行情实例
	CThostFtdcMdSpi *pUserSpi = new CustomMdSpi;       // 创建行情回调实例
	g_pUserApi->RegisterSpi(pUserSpi);                 // 注册事件类
	g_pUserApi->RegisterFront(gFontAddr);              // 设置行情前置地址
	g_pUserApi->Init();                                // 连接
	
	// 等到线程退出
	g_pUserApi->Join();
	delete pUserSpi;
	g_pUserApi->Release();

	getchar();
	return 0;
}