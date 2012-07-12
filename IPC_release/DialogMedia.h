#pragma once

#include "LED.h"
// CDialogMedia 对话框

class CDialogMedia : public CDialog
{
	DECLARE_DYNAMIC(CDialogMedia)

public:
	CDialogMedia(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogMedia();

// 对话框数据
	enum { IDD = IDD_DIALOG_MEDIA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editCaption;
	CEdit m_editX;
	CEdit m_editY;
	CEdit m_editZ;

	
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void Set_X(int x);
	void Set_Y(int y);
	void Set_Z(int z);

	void SetCordinate(int x, int y, int z);
	void SetLEDColor(UINT nIDColor);
	CEdit m_editCap_10;
	CEdit m_editCap_11;
	CEdit m_editCap_12;
	CEdit m_editCap_13;
	CEdit m_editCap_14;
	CEdit m_editCap_15;
	CEdit m_editCap_16;
	CEdit m_editCap_17;
	CEdit m_editCap_18;
	CEdit m_editCap_19;
	CEdit m_editCap_2;
	CEdit m_editCap_20;
	CEdit m_editCap_21;
	CEdit m_editCap_22;
	CEdit m_editCap_23;
	CEdit m_editCap_24;
	CEdit m_editCap_25;
	CEdit m_editCap_26;
	CEdit m_editCap_27;
	CEdit m_editCap_28;
	CEdit m_editCap_29;
	CEdit m_editCap_3;
	CEdit m_editCap_30;
	CEdit m_editCap_4;
	CEdit m_editCap_5;
	CEdit m_editCap_6;
	CEdit m_editCap_7;
	CEdit m_editCap_8;
	CEdit m_editCap_9;
	CEdit m_edit_X_10;
	CEdit m__edit_X_11;
	CEdit m__edit_X_12;
	CEdit m__edit_X_13;
	CEdit m__edit_X_14;
	CEdit m__edit_X_15;
	CEdit m__edit_X_16;
	CEdit m__edit_X_17;
	CEdit m__edit_X_18;
	CEdit m__edit_X_19;
	CEdit m__edit_X_2;
	CEdit m__edit_X_20;
	CEdit m__edit_X_21;
	CEdit m__edit_X_22;
	CEdit m__edit_X_23;
	CEdit m__edit_X_24;
	CEdit m__edit_X_25;
	CEdit m__edit_X_26;
	CEdit m__edit_X_27;
	CEdit m__edit_X_28;
	CEdit m__edit_X_29;
	CEdit m__edit_X_3;
	CEdit m__edit_X_30;
	CEdit m__edit_X_4;
	CEdit m__edit_X_5;
	CEdit m__edit_X_6;
	CEdit m__edit_X_7;
	CEdit m__edit_X_8;
	CEdit m__edit_X_9;
	CEdit m_edit_Y_10;
	CEdit m__edit_Y_11;
	CEdit m__edit_Y_12;
	CEdit m__edit_Y_13;
	CEdit m__edit_Y_14;
	CEdit m__edit_Y_15;
	CEdit m__edit_Y_16;
	CEdit m__edit_Y_17;
	CEdit m__edit_Y_18;
	CEdit m__edit_Y_19;
	CEdit m__edit_Y_2;
	CEdit m__edit_Y_20;
	CEdit m__edit_Y_21;
	CEdit m__edit_Y_22;
	CEdit m__edit_Y_23;
	CEdit m__edit_Y_24;
	CEdit m__edit_Y_25;
	CEdit m__edit_Y_26;
	CEdit m__edit_Y_27;
	CEdit m__edit_Y_28;
	CEdit m__edit_Y_29;
	CEdit m__edit_Y_3;
	CEdit m__edit_Y_30;
	CEdit m__edit_Y_4;
	CEdit m__edit_Y_5;
	CEdit m__edit_Y_6;
	CEdit m__edit_Y_7;
	CEdit m__edit_Y_8;
	CEdit m__edit_Y_9;
	CEdit m__edit_Z_10;
	CEdit m__edit_Z_11;
	CEdit m__edit_Z_12;
	CEdit m__edit_Z_13;
	CEdit m__edit_Z_14;
	CEdit m__edit_Z_15;
	CEdit m__edit_Z_16;
	CEdit m__edit_Z_17;
	CEdit m__edit_Z_18;
	CEdit m__edit_Z_19;
	CEdit m__edit_Z_2;
	CEdit m__edit_Z_20;
	CEdit m__edit_Z_21;
	CEdit m__edit_Z_22;
	CEdit m__edit_Z_23;
	CEdit m__edit_Z_24;
	CEdit m__edit_Z_25;
	CEdit m__edit_Z_26;
	CEdit m__edit_Z_27;
	CEdit m__edit_Z_28;
	CEdit m__edit_Z_29;
	CEdit m__edit_Z_3;
	CEdit m__edit_Z_30;
	CEdit m__edit_Z_4;
	CEdit m__edit_Z_5;
	CEdit m__edit_Z_6;
	CEdit m__edit_Z_7;
	CEdit m__edit_Z_8;
	CEdit m__edit_Z_9;

	CLED m_LED;
	CLED m_LED_2;
	CLED m_LED_3;
	CLED m_LED_4;
	CLED m_LED_5;
	CLED m_LED_6;
	CLED m_LED_7;
	CLED m_LED_8;
	CLED m_LED_9;
	CLED m_LED_10;
	CLED m_LED_11;
	CLED m_LED_12;
	CLED m_LED_13;
	CLED m_LED_14;
	CLED m_LED_15;
	CLED m_LED_16;
	CLED m_LED_17;
	CLED m_LED_18;
	CLED m_LED_19;
	CLED m_LED_20;
	CLED m_LED_21;
	CLED m_LED_22;
	CLED m_LED_23;
	CLED m_LED_24;
	CLED m_LED_25;
	CLED m_LED_26;
	CLED m_LED_27;
	CLED m_LED_28;
	CLED m_LED_29;
	CLED m_LED_30;
	//CLED m_LED_31;

	CLED *pLEDs[31];
	CEdit *pEdit_X[31];
	CEdit *pEdit_Y[31];
	CEdit *pEdit_Z[31];
	CEdit *pEdit_CAP[31];
};
