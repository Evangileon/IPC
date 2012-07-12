#include "StdAfx.h"
#include "Station.h"
#include "CANCenter.h"
#include "IPC_release.h"


CStation::CStation(void)
{
	m_nX = 0;
	m_nY = 0; 
	m_nZ = 0;       //各轴坐标信息
	m_nVx = 0;
	m_nVy = 0; 
	m_nVz = 0; 
	m_Status = STATUS_OFFLINE;
}


CStation::~CStation(void)
{
}

CStation::CStation(int nID)
{
	m_nID = nID;
	m_nX = 0;
	m_nY = 0; 
	m_nZ = 0;       //各轴坐标信息
	m_nVx = 0;
	m_nVy = 0; 
	m_nVz = 0; 
	m_Status = STATUS_OFFLINE;
}


void CStation::SetStatus(int m_status)
{
	CString str;
	switch(m_Status)
	{
	case ID_COLOR_RED:
		str.Format(_T("ID = %d, Status = %s"), m_nID, L"Red");
		break;
	case ID_COLOR_GREEN:
		str.Format(_T("ID = %d, Status = %s"), m_nID, L"Green");
		break;
	case ID_COLOR_BLUE:
		str.Format(_T("ID = %d, Status = %s"), m_nID, L"Blue");
		break;
	case ID_COLOR_YELLOW:
		str.Format(_T("ID = %d, Status = %s"), m_nID, L"Yellow");
		break;
	case ID_COLOR_GRAY:
		str.Format(_T("ID = %d, Status = %s"), m_nID, L"Gray");
		break;
	default:
		break;
	}
	this->m_Status = m_status;
	theApp.Log(str);
}


void CStation::Position(LONGLONG X, LONGLONG Y, LONGLONG Z)
{
	m_nX = X;
	m_nY = Y;
	m_nZ = Z;
}


void CStation::PosX(LONGLONG X)
{
	m_nX = X;
}


void CStation::PosY(LONGLONG Y)
{
	m_nY = Y;
}


void CStation::PosZ(LONGLONG Z)
{
	m_nZ = Z;
}


void CStation::SetHand(BOOL hand)
{
	m_Hand = hand;
}


void CStation::VelX(int m_Vx)
{
	this->m_nVx = m_Vx;
}

void CStation::VelY(int m_Vy)
{
	this->m_nVy = m_Vy;
}

void CStation::VelZ(int m_Vz)
{
	this->m_nVz = m_Vz;
}

CStation& CStation::operator= (const CStation& station)
{
	if(&station == this) 
	{ 
		return *this; 
	} 
	this->m_Hand = station.m_Hand;
	this->m_nID = station.m_nID;
	this->m_nX = station.m_nX;
	this->m_nY = station.m_nY;
	this->m_nZ = station.m_nZ;
	this->m_nVx = station.m_nVx;
	this->m_nVy = station.m_nVy;
	this->m_nVz = station.m_nVz;
	this->m_Status = station.m_Status;
	return *this;
}

CStation::CStation(const CStation& station)
{
	this->m_Hand = station.m_Hand;
	this->m_nID = station.m_nID;
	this->m_nX = station.m_nX;
	this->m_nY = station.m_nY;
	this->m_nZ = station.m_nZ;
	this->m_nVx = station.m_nVx;
	this->m_nVy = station.m_nVy;
	this->m_nVz = station.m_nVz;
	this->m_Status = station.m_Status;
}