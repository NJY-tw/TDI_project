#include "SD_button.h"




BEGIN_EVENT_TABLE(wxBitmappedButton, wxButton)
EVT_LEFT_DOWN(wxBitmappedButton::OnMouseDown)
EVT_LEFT_UP(wxBitmappedButton::OnMouseUp)
EVT_LEFT_DCLICK(wxBitmappedButton::OnDoubleClick)
EVT_ENTER_WINDOW(wxBitmappedButton::Motion)
EVT_LEAVE_WINDOW(wxBitmappedButton::Motion)
EVT_PAINT(wxBitmappedButton::OnPaint)
END_EVENT_TABLE()



wxBitmappedButton::wxBitmappedButton(wxWindow * parent, wxWindowID id, BUTTON_TYPE typeN,
									 wxBitmap normal, wxBitmap pushed, wxPoint pos, wxBitmapBGPanel* panels)
									 : wxButton(parent, id, wxEmptyString, pos),
									 clicked_flag(0),
									 motion_flag(false),
									 type(typeN),
									 pic_one(normal), pic_two(pushed),
									 cling_panels(panels),
									 ball_count(0)
{
	
	SetSize(pic_one.GetWidth(), pic_one.GetHeight());
	pos_x = pos.x;
	pos_y = pos.y;
}

wxBitmappedButton::wxBitmappedButton(wxWindow * parent, wxWindowID id, BUTTON_TYPE typeN,
									 wxBitmap pic_oneN, wxBitmap pic_twoN,wxBitmap pic_threeN, wxPoint pos)
									 : wxButton(parent, id, wxEmptyString, pos),
									 clicked_flag(0),
									 motion_flag(false),
									 type(typeN),
									 pic_one(pic_oneN), pic_two(pic_twoN), pic_three(pic_threeN)
									 
{
	SetSize(pic_one.GetWidth(), pic_one.GetHeight());
	pos_x = pos.x;
	pos_y = pos.y;
}

void wxBitmappedButton::OnMouseDown(wxMouseEvent & event)
{
	
	switch (type)
	{
		case TYPE_BALL:
			clicked_flag = (clicked_flag==1)?0:1;
			Refresh();
			break;
		case TYPE_NEW:
			clicked_flag = 1;
			BallCreate(ball_count);
			Refresh();
			break;
		case TYPE_SORT: 
			if(clicked_flag==0)
				clicked_flag = 1;
			else if(clicked_flag==1)
				clicked_flag = 2;
			else
				clicked_flag =0;
			break;
		default:
			break;
	}
	
	
}

void wxBitmappedButton::BallCreate(int ballNum){

		wxImage Ball10(wxT("C:/workspace/project0/pic/ball10_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball10_c(wxT("C:/workspace/project0/pic/ball10_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball10 = new wxPanel(cling_panels,wxID_ANY, wxPoint(300,5),wxSize(59,58),wxNO_BORDER,"123");
        wxBitmappedButton* item_b10 = new wxBitmappedButton(panel_ball10,wxID_ANY,TYPE_BALL,Ball10,Ball10_c,wxPoint(0,0),nullptr);
}

void wxBitmappedButton::OnMouseUp(wxMouseEvent & event)
{
	switch (type)
	{
		case 0:
			Refresh();
			break;
		case 1:
			clicked_flag = 0;
			Refresh();
			break;
		default:
			break;
	}
}

void wxBitmappedButton::OnDoubleClick(wxMouseEvent & event)
{
	Refresh();
}

void wxBitmappedButton::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	//m_IsPushed ? dc.DrawBitmap(m_Pushed,(nor_width-push_width)/2,(nor_height-push_height)/2,true):dc.DrawBitmap(m_Normal,0,0,true);
	
	switch (type)
	{
		case 0:
			clicked_flag ? dc.DrawBitmap(pic_two,pos_x,pos_y,false):dc.DrawBitmap(pic_one,pos_x,pos_y,false);
			if(!clicked_flag){
				motion_flag ? dc.DrawBitmap(pic_two,pos_x,pos_y,false):dc.DrawBitmap(pic_one,pos_x,pos_y,false);
			}
			break;
			
		case 1:
			clicked_flag ? dc.DrawBitmap(pic_two,pos_x,pos_y,false):dc.DrawBitmap(pic_one,pos_x,pos_y,false);
			break;
		case 2:
			if(clicked_flag ==0)
				dc.DrawBitmap(pic_one,pos_x,pos_y,false);
			else if(clicked_flag==1)
				dc.DrawBitmap(pic_two,pos_x,pos_y,false);
			else
				dc.DrawBitmap(pic_three,pos_x,pos_y,false);
			break;
		default:
			break;
	}
	
}

void wxBitmappedButton::Motion(wxMouseEvent & event)
{
	if(event.Entering())
		motion_flag = true;
	if(event.Leaving())
		motion_flag = false;
}	


