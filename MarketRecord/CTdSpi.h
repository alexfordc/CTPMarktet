#pragma once
#include "CTPConfiguration.h"
#include "CMdSpi.h"
#include "ThostFtdcTraderApi.h"
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
class CTdSpi :
	public CThostFtdcTraderSpi
{
private:
	CTPConfiguration* mConf;
	CThostFtdcTraderApi* mUserApiPtr;
	CMdSpi* mMdSpiPtr;
public:
	CTdSpi(CThostFtdcTraderApi *pUserApi, CMdSpi* mdSpiPtr);
	virtual ~CTdSpi(void);
public:
	///����Ӧ��
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo,
		int nRequestID, bool bIsLast);
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse);
	// ���ͻ����뽻���й�ϵͳ������ͨ�����ӣ��ͻ�����Ҫ���е�¼
	virtual void OnFrontConnected();
	// ���ͻ����뽻���й�ϵͳͨ�����ӶϿ�ʱ���÷���������
	virtual void OnFrontDisconnected(int nReason);
	// ���ͻ��˷�����¼����֮�󣬸÷����ᱻ���ã�֪ͨ�ͻ��˵�¼�Ƿ�ɹ�
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField
		*pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool
		bIsLast);
	//�����Լ��ϢӦ��
	virtual void OnRspQryInstrument(
		CThostFtdcInstrumentField *pInstrument,
		CThostFtdcRspInfoField *pRspInfo,
		int nRequestID,
		bool bIsLast); 

private:
	void ReqUserLogin();
	bool CTdSpi::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
	void QueryInstrumentThread(void);
};

