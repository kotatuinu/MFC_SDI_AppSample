
// MFCApplication4View.h : CMFCApplication4View �N���X�̃C���^�[�t�F�C�X
//

#pragma once


class CMFCApplication4View : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CMFCApplication4View();
	DECLARE_DYNCREATE(CMFCApplication4View)

// ����
public:
	CMFCApplication4Doc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����
public:
	virtual ~CMFCApplication4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication4View.cpp �̃f�o�b�O �o�[�W����
inline CMFCApplication4Doc* CMFCApplication4View::GetDocument() const
   { return reinterpret_cast<CMFCApplication4Doc*>(m_pDocument); }
#endif

