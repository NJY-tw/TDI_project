#include <base.h>
#include <wx/bitmap.h>
#include "SD_panel.h"


enum BUTTON_TYPE{
	TYPE_BALL,
	TYPE_NEW,
	TYPE_SORT,
};

class wxBitmappedButton : public wxButton
{
	wxBitmap pic_one;
	wxBitmap pic_two;
	wxBitmap pic_three;
	wxCoord pos_x;
	wxCoord pos_y;
	
	
public:
	wxBitmappedButton(wxWindow * parent, wxWindowID id, BUTTON_TYPE typeN,
		wxBitmap normal, wxBitmap pushed, wxPoint pos, wxBitmapBGPanel* panels);

	wxBitmappedButton(wxWindow * parent, wxWindowID id, BUTTON_TYPE typeN,
		wxBitmap pic_one, wxBitmap pic_two,wxBitmap pic_three, wxPoint pos);
	DECLARE_EVENT_TABLE()

	void OnMouseDown(wxMouseEvent & event);
	void OnMouseUp(wxMouseEvent & event);
	void OnPaint(wxPaintEvent & event);
	void OnDoubleClick(wxMouseEvent & event);
	void Motion(wxMouseEvent & event);
	void BallCreate(int ballNum);

protected :
    int ball_count;
	int clicked_flag;
	bool motion_flag;
	BUTTON_TYPE type;
	wxBitmapBGPanel* cling_panels;

};





