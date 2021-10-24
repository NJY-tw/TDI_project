#include <base.h>
#include <wx/bitmap.h>
#include "SD_panel.h"


enum BUTTON_TYPE
{
    TYPE_BALL=200,
	TYPE_NEW,
	TYPE_SORT,
};

enum{
	BALL_1=100,
	BALL_2,
	BALL_3,
	BALL_4,
	BALL_5,
	BALL_6,
	BALL_7,
	BALL_8,
	BALL_9,
	BALL_10,
	BALL_11,
	BALL_12,
	BALL_13,
	BALL_14,
	BALL_15,
	PANEL_1,
	PANEL_2,
	PANEL_3,
	PANEL_4,
	PANEL_5,
	PANEL_6,
	PANEL_7,
	PANEL_8,
	PANEL_9,
	PANEL_10,
	PANEL_11,
	PANEL_12,
	PANEL_13,
	PANEL_14,
	PANEL_15,
};


class wxBitmappedButton : public wxButton
{
	wxBitmap pic_one;
	wxBitmap pic_two;
	wxBitmap pic_three;
	wxCoord pos_x;
	wxCoord pos_y;
	
	
public:
	wxBitmappedButton(wxWindow * parent, wxWindowID winid, BUTTON_TYPE typeN,
		wxBitmap normal, wxBitmap pushed, wxPoint pos, wxBitmapBGPanel* panels_c[2],wxPanel* panels_b);

	wxBitmappedButton(wxWindow * parent, wxWindowID winid, BUTTON_TYPE typeN,
		wxBitmap pic_one, wxBitmap pic_two,wxBitmap pic_three, wxPoint pos);
	DECLARE_EVENT_TABLE()

	void OnMouseDown(wxMouseEvent & event);
	void OnMouseUp(wxMouseEvent & event);
	void OnPaint(wxPaintEvent & event);
	void OnDoubleClick(wxMouseEvent & event);
	void Motion(wxMouseEvent & event);
	void BallCreate();

protected :
	//int dist_board;
	// int dist_x=60;
    int ball_count;
	int clicked_flag;
	bool motion_flag;
	BUTTON_TYPE type;
	wxBitmapBGPanel* cling_panels[2];
	wxPanel* ball_cling_panels;
	int finished;

};





