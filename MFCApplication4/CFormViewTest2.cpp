// CFormViewTest2.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "CFormViewTest2.h"
#include "CFormDocTest2.h"


// CFormViewTest2

IMPLEMENT_DYNCREATE(CFormViewTest2, CFormView)

CFormViewTest2::CFormViewTest2()
	: CFormView(IDD_FORMVIEW1)
{

}

CFormViewTest2::~CFormViewTest2()
{
}

void CFormViewTest2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormViewTest2, CFormView)
END_MESSAGE_MAP()

BOOL CFormViewTest2::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View �`��

void CFormViewTest2::OnDraw(CDC* /*pDC*/)
{
	CFormDocTest2* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}

// CFormViewTest2 �f�f

#ifdef _DEBUG
void CFormViewTest2::AssertValid() const
{
	CFormView::AssertValid();
}
#ifndef _WIN32_WCE
void CFormViewTest2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormViewTest2 ���b�Z�[�W �n���h���[
