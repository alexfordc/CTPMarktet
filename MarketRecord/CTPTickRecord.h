#pragma once
#include "ThostFtdcMdApi.h"
#include <cstring>
class CTPTickRecord
{
public:
	///������
	char TradingDay[9];
	///��Լ����
	char InstrumentID[31];
	///����������
	char ExchangeID[9];
	///��Լ�ڽ������Ĵ���
	char ExchangeInstID[31];
	///���¼�
	double	LastPrice;
	///�ϴν����
	double	PreSettlementPrice;
	///������
	double PreClosePrice;
	///��ֲ���
	double PreOpenInterest;
	///����
	double OpenPrice;
	///��߼�
	double HighestPrice;
	///��ͼ�
	double LowestPrice;
	///����
	int Volume;
	///�ɽ����
	double Turnover;
	///�ֲ���
	double OpenInterest;
	///������
	double ClosePrice;
	///���ν����
	double SettlementPrice;
	///��ͣ���
	double UpperLimitPrice;
	///��ͣ���
	double LowerLimitPrice;
	///����ʵ��
	double PreDelta;
	///����ʵ��
	double CurrDelta;
	///����޸�ʱ��
	char UpdateTime[9];
	///����޸ĺ���
	int UpdateMillisec;
	///�����һ
	double BidPrice1;
	///������һ
	int	BidVolume1;
	///������һ
	double	AskPrice1;
	///������һ
	int	AskVolume1;
	///����۶�
	double BidPrice2;
	///��������
	int	BidVolume2;
	///�����۶�
	double	AskPrice2;
	///��������
	int	AskVolume2;
	///�������
	double	BidPrice3;
	///��������
	int	BidVolume3;
	///��������
	double	AskPrice3;
	///��������
	int	AskVolume3;
	///�������
	double	BidPrice4;
	///��������
	int	BidVolume4;
	///��������
	double	AskPrice4;
	///��������
	int	AskVolume4;
	///�������
	double	BidPrice5;
	///��������
	int	BidVolume5;
	///��������
	double	AskPrice5;
	///��������
	int	AskVolume5;
	///���վ���
	double	AveragePrice;
public:
	CTPTickRecord(CThostFtdcDepthMarketDataField* pMarketData)
	{
		strncpy(this->TradingDay, pMarketData->TradingDay, 9);
		strncpy(this->InstrumentID, pMarketData->InstrumentID, 31);
		strncpy(this->ExchangeID, pMarketData->ExchangeID, 9);
		strncpy(this->ExchangeInstID, pMarketData->ExchangeInstID, 31);
		this->LastPrice = pMarketData->LastPrice;
		this->PreSettlementPrice = pMarketData->PreSettlementPrice;
		this->PreClosePrice = pMarketData->PreClosePrice;
		this->PreOpenInterest = pMarketData->PreOpenInterest;
		this->OpenPrice = pMarketData->OpenPrice;
		this->HighestPrice = pMarketData->HighestPrice;
		this->LowestPrice = pMarketData->LowestPrice;
		this->Volume = pMarketData->Volume;
		this->Turnover = pMarketData->Turnover;
		this->OpenInterest = pMarketData->OpenInterest;
		this->ClosePrice = pMarketData->ClosePrice;
		this->SettlementPrice = pMarketData->SettlementPrice;
		this->UpperLimitPrice = pMarketData->UpperLimitPrice;
		this->LowerLimitPrice = pMarketData->LowerLimitPrice;
		this->PreDelta = pMarketData->PreDelta;
		this->CurrDelta = pMarketData->CurrDelta;
		strncpy(this->UpdateTime, pMarketData->UpdateTime, 9);
		this->UpdateMillisec = pMarketData->UpdateMillisec;
		this->BidPrice1 = pMarketData->BidPrice1;
		this->BidVolume1 = pMarketData->BidVolume1;
		this->AskPrice1 = pMarketData->AskPrice1;
		this->AskVolume1 = pMarketData->AskVolume1;
		this->BidPrice2 = pMarketData->BidPrice2;
		this->BidVolume2 = pMarketData->BidVolume2;
		this->AskPrice2 = pMarketData->AskPrice2;
		this->AskVolume2 = pMarketData->AskVolume2;
		this->BidPrice3 = pMarketData->BidPrice3;
		this->BidVolume3 = pMarketData->BidVolume3;
		this->AskPrice3 = pMarketData->AskPrice3;
		this->AskVolume3 = pMarketData->AskVolume3;
		this->BidPrice4 = pMarketData->BidPrice4;
		this->BidVolume4 = pMarketData->BidVolume4;
		this->AskPrice4 = pMarketData->AskPrice4;
		this->AskVolume4 = pMarketData->AskVolume4;
		this->BidPrice5 = pMarketData->BidPrice5;
		this->BidVolume5 = pMarketData->BidVolume5;
		this->AskPrice5 = pMarketData->AskPrice5;
		this->AskVolume5 = pMarketData->AskVolume5;
		this->AveragePrice = pMarketData->AveragePrice;
	}
};