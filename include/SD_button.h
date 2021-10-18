#include <base.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include "SD_panel.h"



class wxBitmappedButton : public wxButton
{
	wxBitmap pic_one;
	wxBitmap pic_two;
	wxBitmap pic_three;
	wxCoord pos_x;
	wxCoord pos_y;
	
	
public:
	wxBitmappedButton(wxWindow * parent, wxWindowID id, int typeN,
		wxBitmap normal, wxBitmap pushed, wxPoint pos);

	wxBitmappedButton(wxWindow * parent, wxWindowID id, int typeN,
		wxBitmap pic_one, wxBitmap pic_two,wxBitmap pic_three, wxPoint pos);
	DECLARE_EVENT_TABLE()

	void OnMouseDown(wxMouseEvent & event);
	void OnMouseUp(wxMouseEvent & event);
	void OnPaint(wxPaintEvent & event);
	void OnDoubleClick(wxMouseEvent & event);
	void Motion(wxMouseEvent & event);

protected :
	int clicked_flag;
	bool motion_flag;
	int type;
};





