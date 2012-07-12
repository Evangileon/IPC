#include "StdAfx.h"
#include "StationManager.h"


CStationManager::CStationManager(void)
{
	m_StationNBR = 0;
	pStationList = new vector<CStation>();
}


CStationManager::~CStationManager(void)
{
	/*for(vector<CStation>::iterator it1 = pStationList->begin();it1!=pStationList->end(); it1++)  
	{  
		 pStationList->erase(it1);
		 
		 //StationList->
	} */ 
	pStationList->clear(); 
	delete pStationList;
	//delete pStationList;
}

CStationManager::CStationManager(int m_NBR)
{
	m_StationNBR = m_NBR;
	pStationList = new vector<CStation>(m_NBR);
	SetStationID(m_NBR);
}


void CStationManager::SetStationID(int m_NBR)
{
	/*for(int i = 0; i < pStationList->capacity(); i++)
	{
		pStationList->at(i).m_nID = i + 1;
	}*/

	int index = 1;
	
	for(vector<CStation>::iterator iter = pStationList->begin(); 
		iter!=pStationList->end(); iter++)
	{
		iter->m_nID = index++;
	}
}


void CStationManager::SetStationStatus(int m_ID, int m_Status)
{
	pStationList->at(m_ID - 1).SetStatus(m_Status);
}



void CStationManager::SetPosX(int m_ID, LONGLONG m_X)
{
	pStationList->at(m_ID - 1).PosX(m_X);
}

void CStationManager::SetPosY(int m_ID, LONGLONG m_Y)
{
	pStationList->at(m_ID - 1).PosY(m_Y);
}

void CStationManager::SetPosZ(int m_ID, LONGLONG m_Z)
{
	pStationList->at(m_ID - 1).PosZ(m_Z);
}

void CStationManager::SetVelX(int m_ID, int m_Vx)
{
	pStationList->at(m_ID - 1).VelX(m_Vx);
}

void CStationManager::SetVelY(int m_ID, int m_Vy)
{
	pStationList->at(m_ID - 1).VelY(m_Vy);
}

void CStationManager::SetVelZ(int m_ID, int m_Vz)
{
	pStationList->at(m_ID - 1).VelZ(m_Vz);
}

CStation& CStationManager::GetStationByID(int m_ID)
{
	return pStationList->at(m_ID - 1);
}


void CStationManager::SetHand(int m_ID, int m_Hand)
{
	pStationList->at(m_ID - 1).SetHand(!(!m_Hand));
}

CStationManager& CStationManager::operator= (const CStationManager& stationMngr)
{
	if(&stationMngr == this)
		return *this;

	this->m_StationNBR = stationMngr.m_StationNBR;
	this->pStationList = stationMngr.pStationList;
	return *this;
}

CStationManager::CStationManager(const CStationManager& stationMngr)
{
	this->m_StationNBR = stationMngr.m_StationNBR;
	this->pStationList = stationMngr.pStationList;
}