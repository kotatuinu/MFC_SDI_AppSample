
// MFCApplication4.h : MFCApplication4 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル
#include <vector>

// CMFCApplication4App:
// このクラスの実装については、MFCApplication4.cpp を参照してください。
//

class CMFCApplication4App : public CWinAppEx
{
public :
	std::vector<CSingleDocTemplate*> m_viewArray;

public:
	CMFCApplication4App();
	~CMFCApplication4App();

// オーバーライド
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 実装
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	//afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication4App theApp;
