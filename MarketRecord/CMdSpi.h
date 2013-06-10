#pragma once
#include "ThostFtdcMdApi.h"
#include "CTPConfiguration.h"
#include "MarketDataRecorder.h"
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <queue>
#include <string>
#include <set>

class CMdSpi : public CThostFtdcMdSpi
{
private:
	CThostFtdcMdApi* mUserApiPtr;
	CTPConfiguration* mConf;
	MarketDataRecorder mRecorder;
	std::queue<std::string> mSubscribeQueue;
	boost::mutex mQueueMutex;
	std::set<std::string> mSubscribedInstrumentSet;
	boost::thread* mSubscribeInstrumentThread;
public:
	CMdSpi(CThostFtdcMdApi* userApiPtr):
	  mUserApiPtr(userApiPtr), 
	  mConf(CTPConfiguration::Instance()),
	  mSubscribeInstrumentThread(NULL)
	{
	}
	  ~CMdSpi()
	  {
		  if(mSubscribeInstrumentThread != NULL)
		  {
			  delete mSubscribeInstrumentThread;
		  }
	  }
public:
	///����Ӧ��
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo,
		int nRequestID, bool bIsLast);

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason);
		
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse);

	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();
	
	///��¼������Ӧ
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��������Ӧ��
	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ȡ����������Ӧ��
	virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

public:
	void AddSubscribeInstrument(char* instrumentID);
private:
	void ReqUserLogin();
	void SuscribeInstrumentThread(void);
	bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
};