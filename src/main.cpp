#include <iostream>
#include <string>
#include "CustomMdSpi.h"
#include "CustomTradeSpi.h"

using namespace std;

// 链接库
#pragma comment (lib, "thostmduserapi.lib")
#pragma comment (lib, "thosttraderapi.lib")

// ---- 全局变量 ---- //
// 公共参数
TThostFtdcBrokerIDType gBrokerID = "9999";                         // 模拟经纪商代码
TThostFtdcInvestorIDType gInvesterID = "081097";                   // 投资者账户名
TThostFtdcPasswordType gInvesterPassword = "asdfqwer";             // 投资者密码
// 行情参数
CThostFtdcMdApi *g_pMdUserApi = nullptr;                           // 行情指针
char gMdFrontAddr[] = "tcp://180.168.146.187:10010";               // 模拟行情前置地址
char *g_pInstrumentID[] = {"TF1706", "al1712", "cs1801", "CF705"}; // 行情合约代码列表，中、上、大、郑交易所各选一种
int instrumentNum = 4;                                             // 行情合约订阅数量
// 交易参数
CThostFtdcTraderApi *g_pTradeUserApi = nullptr;                    // 交易指针
char gTradeFrontAddr[] = "tcp://180.168.146.187:10000";            // 模拟交易前置地址
TThostFtdcInstrumentIDType g_pTradeInstrumentID = "zn1705";        // 所交易的合约代码
TThostFtdcDirectionType gTradeDirection = THOST_FTDC_D_Sell;       // 买卖方向
TThostFtdcPriceType gLimitPrice = 23135;                            // 交易价格

int main()
{
	//cout << "初始化行情..." << endl;
	//// 初始化行情
	//g_pMdUserApi = CThostFtdcMdApi::CreateFtdcMdApi();   // 创建行情实例
	//CThostFtdcMdSpi *pMdUserSpi = new CustomMdSpi;       // 创建行情回调实例
	//g_pMdUserApi->RegisterSpi(pMdUserSpi);               // 注册事件类
	//g_pMdUserApi->RegisterFront(gMdFrontAddr);           // 设置行情前置地址
	//g_pMdUserApi->Init();                                // 连接
	//
	//// 等到线程退出
	//g_pMdUserApi->Join();
	//delete pMdUserSpi;
	//g_pMdUserApi->Release();

	cout << "初始化交易..." << endl;
	g_pTradeUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
	CThostFtdcTraderSpi *pTradeSpi = new CustomTradeSpi;
	g_pTradeUserApi->RegisterSpi(pTradeSpi);
	g_pTradeUserApi->SubscribePublicTopic(THOST_TERT_RESTART);
	g_pTradeUserApi->SubscribePrivateTopic(THOST_TERT_RESTART);
	g_pTradeUserApi->RegisterFront(gTradeFrontAddr);
	g_pTradeUserApi->Init();

	g_pTradeUserApi->Join();
	delete pTradeSpi;
	g_pTradeUserApi->Release();
	

	getchar();
	return 0;
}