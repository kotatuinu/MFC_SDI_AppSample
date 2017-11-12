
// MFCApplication4Doc.cpp : CMFCApplication4Doc �N���X�̎���
//

#include "stdafx.h"
// SHARED_HANDLERS �́A�v���r���[�A�k���ŁA����ь����t�B���^�[ �n���h���[���������Ă��� ATL �v���W�F�N�g�Œ�`�ł��A
// ���̃v���W�F�N�g�Ƃ̃h�L�������g �R�[�h�̋��L���\�ɂ��܂��B
#ifndef SHARED_HANDLERS
#include "MFCApplication4.h"
#endif

#include "MFCApplication4Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication4Doc

IMPLEMENT_DYNCREATE(CMFCApplication4Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication4Doc, CDocument)
	ON_COMMAND(ID_FORMVIEW_CHANGE, &CMFCApplication4Doc::OnFormviewChange)
END_MESSAGE_MAP()


// CMFCApplication4Doc �R���X�g���N�V����/�f�X�g���N�V����

CMFCApplication4Doc::CMFCApplication4Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CMFCApplication4Doc::~CMFCApplication4Doc()
{
}

BOOL CMFCApplication4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B

	return TRUE;
}




// CMFCApplication4Doc �V���A����

void CMFCApplication4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �i�[����R�[�h�������ɒǉ����Ă��������B
	}
	else
	{
		// TODO: �ǂݍ��ރR�[�h�������ɒǉ����Ă��������B
	}
}

#ifdef SHARED_HANDLERS

//�k���ł̃T�|�[�g
void CMFCApplication4Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ���̃R�[�h��ύX���ăh�L�������g�̃f�[�^��`�悵�܂�
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �����n���h���[�̃T�|�[�g
void CMFCApplication4Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// �h�L�������g�̃f�[�^���猟���R���e���c��ݒ肵�܂��B
	// �R���e���c�̊e������ ";" �ŋ�؂�K�v������܂�

	// ��:      strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCApplication4Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCApplication4Doc �f�f

#ifdef _DEBUG
void CMFCApplication4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCApplication4Doc �R�}���h


void CMFCApplication4Doc::OnFormviewChange()
{
	// TODO: �����ɃR�}���h �n���h���[ �R�[�h��ǉ����܂��B
	CMFCApplication4App*  pApp = (CMFCApplication4App*)AfxGetApp();
	CSingleDocTemplate* p1 = pApp->m_viewArray[1];

	p1->InitialUpdateFrame(p1->CreateNewFrame(this, 0), 0);
}
