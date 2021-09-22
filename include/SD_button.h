#include <base.h>
#include <wx/button.h>
#include <wx/bitmap.h>

class wxBitmappedButton : public wxButton
{
	wxBitmap m_Normal;
	wxBitmap m_Pushed;
	wxCoord pos_x;
	wxCoord pos_y;
	unsigned int nor_width;
	unsigned int nor_height;
	unsigned int push_width;
	unsigned int push_height;
	bool m_IsPushed;
public:
	wxBitmappedButton(wxWindow * parent, wxWindowID id, 
		wxBitmap normal, wxBitmap pushed, wxPoint pos);

	DECLARE_EVENT_TABLE()

	void OnMouseDown(wxMouseEvent & event);
	void OnMouseUp(wxMouseEvent & event);
	void OnPaint(wxPaintEvent & event);
	void OnDoubleClick(wxMouseEvent & event);
};