#include <iostream>
#include "CustomMdSpi.h"

void CustomMdSpi::OnFrontConnected()
{
	std::cout << "=====建立连接成功=====" << std::endl;
}

void CustomMdSpi::OnFrontDisconnected(int nReason)
{
	std::cerr << "=====网络连接断开，错误码： " << nReason << "=====" << std::endl;
}

void CustomMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
	std::cerr << "=====网络心跳超时，距上次连接时间： " << nTimeLapse << "=====" << std::endl;
}

void CustomMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{

}