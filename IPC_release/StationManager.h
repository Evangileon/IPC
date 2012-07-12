#pragma once

#include <vector>
#include "Station.h"

using namespace std;

//用于管理所有工位的信息
class CStationManager
{
public:
	CStationManager(void);
	~CStationManager(void);
	CStationManager(int m_NBR);
	CStationManager(const CStationManager& stationMngr);
	CStationManager& operator= (const CStationManager& stationMngr);

	vector<CStation> *pStationList;
	int m_StationNBR;
private:
	void SetStationID(int m_NBR);
public:
	void SetStationStatus(int m_ID, int m_Status);
	void SetPosX(int m_ID, LONGLONG m_X);
	void SetPosY(int m_ID, LONGLONG m_Y);
	void SetPosZ(int m_ID, LONGLONG m_Z);
	void SetVelX(int m_ID, int m_VX);
	void SetVelY(int m_ID, int m_VY);
	void SetVelZ(int m_ID, int m_VZ);
	CStation& GetStationByID(int m_ID);
	void SetHand(int m_ID, BOOL m_Hand);

};

