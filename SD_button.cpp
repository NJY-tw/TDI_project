#include "SD_button.h"


BEGIN_EVENT_TABLE(wxBitmappedButton, wxButton)
EVT_LEFT_DOWN(wxBitmappedButton::OnMouseDown)
EVT_LEFT_UP(wxBitmappedButton::OnMouseUp)
EVT_LEFT_DCLICK(wxBitmappedButton::OnDoubleClick)
EVT_ENTER_WINDOW(wxBitmappedButton::OnMouseUp)
EVT_LEAVE_WINDOW(wxBitmappedButton::OnMouseUp)
EVT_PAINT(wxBitmappedButton::OnPaint)
END_EVENT_TABLE()

wxBitmappedButton::wxBitmappedButton(wxWindow * parent, wxWindowID id, 
									 wxBitmap normal, wxBitmap pushed, wxPoint pos)
									 : wxButton(parent, id, wxEmptyString, pos),
									 m_IsPushed(false),
									 m_Normal(normal), m_Pushed(pushed)
{
	nor_width = m_Normal.GetWidth();
	nor_height = m_Normal.GetHeight();
	push_width = m_Pushed.GetWidth();
	push_height = m_Pushed.GetHeight();

	SetSize(m_Normal.GetWidth(), m_Normal.GetHeight());
	pos_x = pos.x;
	pos_y = pos.y;
	//::SetShape(this, wxRegion(m_Normal));	
}

void wxBitmappedButton::OnMouseDown(wxMouseEvent & event)
{
	m_IsPushed = true;
	Refresh();
}

void wxBitmappedButton::OnMouseUp(wxMouseEvent & event)
{
	m_IsPushed = false;
	Refresh();
}

void wxBitmappedButton::OnDoubleClick(wxMouseEvent & event)
{
	Refresh();
}

void wxBitmappedButton::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	m_IsPushed ? dc.DrawBitmap(m_Pushed,(nor_width-push_width)/2,(nor_height-push_height)/2,true):dc.DrawBitmap(m_Normal,0,0,true);
}