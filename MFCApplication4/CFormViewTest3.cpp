// CFormViewTest3.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MFCApplication4.h"

#include "CFormViewTest3.h"
#include "CFormDocTest2.h"


// CFormViewTest3

IMPLEMENT_DYNCREATE(CFormViewTest3, CFormView)

CFormViewTest3::CFormViewTest3()
	: CFormView(IDD_FORMVIEW2)
{

}

CFormViewTest3::~CFormViewTest3()
{
}

void CFormViewTest3::setSDIViewChanger(CSDIViewChanger* pSDIViewChanger)
{
	pSDIViewChanger->addView(this);
}

void CFormViewTest3::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormViewTest3, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CFormViewTest3::OnBnClickedButton1)
END_MESSAGE_MAP()

BOOL CFormViewTest3::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View �`��

void CFormViewTest3::OnDraw(CDC* /*pDC*/)
{
	CFormDocTest3* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}

// CFormViewTest3 �f�f

#ifdef _DEBUG
void CFormViewTest3::AssertValid() const
{
	CFormView::AssertValid();
}
#ifndef _WIN32_WCE
void CFormViewTest3::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormViewTest3 ���b�Z�[�W �n���h���[


void CFormViewTest3::OnBnClickedButton1()
{
	CSDIViewChanger *pSDIViewChanger = NULL;
	pSDIViewChanger->SwitchView(0UL);
}
