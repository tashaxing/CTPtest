#pragma once
// ---- 简单策略交易的类 ---- //
#include <string>
#include <unordered_map>
#include "CTP_API/ThostFtdcUserApiStruct.h"
#include "TickToKlineHelper.h"

typedef void(*reqOrderInsertFun)(
	TThostFtdcInstrumentIDType instrumentID,
	TThostFtdcPriceType price,
	TThostFtdcVolumeType volume,
	TThostFtdcDirectionType direction);

void StrategyCheckAndTrade(std::unordered_map<std::string, TickToKlineHelper> &instrumentRecord, reqOrderInsertFun reqFun);
