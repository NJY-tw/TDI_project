#include "SD_button.h"





BEGIN_EVENT_TABLE(wxBitmappedButton, wxButton)
EVT_LEFT_DOWN(wxBitmappedButton::OnMouseDown)
EVT_LEFT_UP(wxBitmappedButton::OnMouseUp)
EVT_LEFT_DCLICK(wxBitmappedButton::OnDoubleClick)
EVT_ENTER_WINDOW(wxBitmappedButton::Motion)
EVT_LEAVE_WINDOW(wxBitmappedButton::Motion)
EVT_PAINT(wxBitmappedButton::OnPaint)
END_EVENT_TABLE()



wxBitmappedButton::wxBitmappedButton(wxWindow * parent, wxWindowID winid, BUTTON_TYPE typeN,
									 wxBitmap normal, wxBitmap pushed, wxPoint pos, wxBitmapBGPanel* panels_c[2], wxPanel* panels_b)
									 : wxButton(parent, winid, wxEmptyString, pos),
									 clicked_flag(0),
									 motion_flag(false),
									 type(typeN),
									 pic_one(normal), pic_two(pushed),
									 ball_cling_panels(panels_b),
									 ball_count(0),
									 finished(0)
{
	cling_panels[0] = panels_c[0];
	cling_panels[1] = panels_c[1];
	SetSize(pic_one.GetWidth(), pic_one.GetHeight());
	pos_x = pos.x;
	pos_y = pos.y;
}


wxBitmappedButton::wxBitmappedButton(wxWindow * parent, wxWindowID winid, BUTTON_TYPE typeN,
									 wxBitmap pic_oneN,wxBitmap pic_twoN,wxBitmap pic_threeN, wxPoint pos)
									 : wxButton(parent, winid, wxEmptyString, pos),
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
			BallCreate();
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
	if(type==TYPE_BALL){
		finished = (finished==0)?1:0;
		ball_cling_panels->Reparent(cling_panels[finished]);
	}
	
	
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
			Refresh();
			break;
			
		case 1:
			clicked_flag ? dc.DrawBitmap(pic_two,pos_x,pos_y,false):dc.DrawBitmap(pic_one,pos_x,pos_y,false);
			Refresh();
			break;
		case 2:
			if(clicked_flag ==0)
				dc.DrawBitmap(pic_one,pos_x,pos_y,false);
			else if(clicked_flag==1)
				dc.DrawBitmap(pic_two,pos_x,pos_y,false);
			else
				dc.DrawBitmap(pic_three,pos_x,pos_y,false);

			Refresh();
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


void wxBitmappedButton::BallCreate(){

	if(ball_count==0){
		wxImage Ball1(wxT("C:/workspace/project0/pic/ball1_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball1_c(wxT("C:/workspace/project0/pic/ball1_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball1 = new wxPanel(cling_panels[0],PANEL_1, wxPoint(709,3),wxSize(59,57),wxNO_BORDER,"123");
        wxBitmappedButton* item_b1 = new wxBitmappedButton(panel_ball1,BALL_1,TYPE_BALL,Ball1,Ball1_c,wxPoint(0,0),cling_panels,panel_ball1);
		ball_count+=1;
	}
	else if(ball_count==1){
		wxImage Ball2(wxT("C:/workspace/project0/pic/ball2_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball2_c(wxT("C:/workspace/project0/pic/ball2_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball2 = new wxPanel(cling_panels[0],PANEL_2, wxPoint(709-(60*ball_count),3),wxSize(59,58),wxNO_BORDER,"123");
        wxBitmappedButton* item_b2 = new wxBitmappedButton(panel_ball2,BALL_2,TYPE_BALL,Ball2,Ball2_c,wxPoint(0,0),cling_panels,panel_ball2);
		ball_count+=1;
	}
	else if(ball_count==2){
		wxImage Ball3(wxT("C:/workspace/project0/pic/ball3_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball3_c(wxT("C:/workspace/project0/pic/ball3_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball3 = new wxPanel(cling_panels[0],PANEL_3, wxPoint(709-(60*ball_count),3),wxSize(59,57),wxNO_BORDER,"123");
        wxBitmappedButton* item_b3 = new wxBitmappedButton(panel_ball3,BALL_3,TYPE_BALL,Ball3,Ball3_c,wxPoint(0,0),cling_panels,panel_ball3);
		ball_count+=1;
	}
	else if(ball_count==3){
		wxImage Ball4(wxT("C:/workspace/project0/pic/ball4_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball4_c(wxT("C:/workspace/project0/pic/ball4_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball4 = new wxPanel(cling_panels[0],PANEL_4, wxPoint(709-(60*ball_count),3),wxSize(57,57),wxNO_BORDER,"123");
        wxBitmappedButton* item_b4 = new wxBitmappedButton(panel_ball4,BALL_4,TYPE_BALL,Ball4,Ball4_c,wxPoint(0,0),cling_panels,panel_ball4);
		ball_count+=1;
	}
	else if(ball_count==4){
		wxImage Ball5(wxT("C:/workspace/project0/pic/ball5_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball5_c(wxT("C:/workspace/project0/pic/ball5_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball5 = new wxPanel(cling_panels[0],PANEL_5, wxPoint(709-(60*ball_count),3),wxSize(59,57),wxNO_BORDER,"123");
        wxBitmappedButton* item_b5 = new wxBitmappedButton(panel_ball5,BALL_5,TYPE_BALL,Ball5,Ball5_c,wxPoint(0,0),cling_panels,panel_ball5);
		ball_count+=1;
	}
	else if(ball_count==5){
		wxImage Ball6(wxT("C:/workspace/project0/pic/ball6_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball6_c(wxT("C:/workspace/project0/pic/ball6_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball6 = new wxPanel(cling_panels[0],PANEL_6, wxPoint(709-(60*ball_count),3),wxSize(57,57),wxNO_BORDER,"123");
        wxBitmappedButton* item_b6 = new wxBitmappedButton(panel_ball6,BALL_6,TYPE_BALL,Ball6,Ball6_c,wxPoint(0,0),cling_panels,panel_ball6);
		ball_count+=1;
	}
	else if(ball_count==6){
		wxImage Ball7(wxT("C:/workspace/project0/pic/ball7_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball7_c(wxT("C:/workspace/project0/pic/ball7_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball7 = new wxPanel(cling_panels[0],PANEL_7, wxPoint(709-(60*ball_count),3),wxSize(59,57),wxNO_BORDER,"123");
        wxBitmappedButton* item_b7 = new wxBitmappedButton(panel_ball7,BALL_7,TYPE_BALL,Ball7,Ball7_c,wxPoint(0,0),cling_panels,panel_ball7);
		ball_count+=1;
	}
	else if(ball_count==7){
		wxImage Ball8(wxT("C:/workspace/project0/pic/ball8_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball8_c(wxT("C:/workspace/project0/pic/ball8_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball8 = new wxPanel(cling_panels[0],PANEL_8, wxPoint(709-(60*ball_count),3),wxSize(57,57),wxNO_BORDER,"123");
        wxBitmappedButton* item_b8 = new wxBitmappedButton(panel_ball8,BALL_8,TYPE_BALL,Ball8,Ball8_c,wxPoint(0,0),cling_panels,panel_ball8);
		ball_count+=1;
	}
	else if(ball_count==8){
		wxImage Ball9(wxT("C:/workspace/project0/pic/ball9_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball9_c(wxT("C:/workspace/project0/pic/ball9_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball9 = new wxPanel(cling_panels[0],PANEL_9, wxPoint(709-(60*ball_count),3),wxSize(59,58),wxNO_BORDER,"123");
        wxBitmappedButton* item_b9 = new wxBitmappedButton(panel_ball9,BALL_9,TYPE_BALL,Ball9,Ball9_c,wxPoint(0,0),cling_panels,panel_ball9);
		ball_count+=1;
	}
	else if(ball_count==9){
		wxImage Ball10(wxT("C:/workspace/project0/pic/ball10_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball10_c(wxT("C:/workspace/project0/pic/ball10_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball10 = new wxPanel(cling_panels[0],PANEL_10, wxPoint(709-(60*ball_count),3),wxSize(59,58),wxNO_BORDER,"123");
        wxBitmappedButton* item_b10 = new wxBitmappedButton(panel_ball10,BALL_10,TYPE_BALL,Ball10,Ball10_c,wxPoint(0,0),cling_panels,panel_ball10);
		ball_count+=1;
	}
	else if(ball_count==10){
		wxImage Ball11(wxT("C:/workspace/project0/pic/ball11_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball11_c(wxT("C:/workspace/project0/pic/ball11_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball11 = new wxPanel(cling_panels[0],PANEL_11, wxPoint(709-(60*ball_count),3),wxSize(59,57),wxNO_BORDER,"123");
        wxBitmappedButton* item_b11 = new wxBitmappedButton(panel_ball11,BALL_11,TYPE_BALL,Ball11,Ball11_c,wxPoint(0,0),cling_panels,panel_ball11);
		ball_count+=1;
	}
	else if(ball_count==11){
		wxImage Ball12(wxT("C:/workspace/project0/pic/ball12_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball12_c(wxT("C:/workspace/project0/pic/ball12_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball12 = new wxPanel(cling_panels[0],PANEL_12, wxPoint(709-(60*ball_count),3),wxSize(56,56),wxNO_BORDER,"123");
        wxBitmappedButton* item_b12 = new wxBitmappedButton(panel_ball12,BALL_12,TYPE_BALL,Ball12,Ball12_c,wxPoint(0,0),cling_panels,panel_ball12);
		ball_count+=1;
	}
	else if(ball_count==12){
		wxImage Ball13(wxT("C:/workspace/project0/pic/ball13_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball13_c(wxT("C:/workspace/project0/pic/ball13_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball13 = new wxPanel(cling_panels[0],PANEL_13, wxPoint(709-(60*ball_count),3),wxSize(57,57),wxNO_BORDER,"123");
        wxBitmappedButton* item_b13 = new wxBitmappedButton(panel_ball13,BALL_13,TYPE_BALL,Ball13,Ball13_c,wxPoint(0,0),cling_panels,panel_ball13);
		ball_count+=1;
	}
	else if(ball_count==13){
		wxImage Ball14(wxT("C:/workspace/project0/pic/ball14_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball14_c(wxT("C:/workspace/project0/pic/ball14_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball14 = new wxPanel(cling_panels[0],PANEL_14, wxPoint(709-(60*ball_count),3),wxSize(56,58),wxNO_BORDER,"123");
        wxBitmappedButton* item_b14 = new wxBitmappedButton(panel_ball14,BALL_14,TYPE_BALL,Ball14,Ball14_c,wxPoint(0,0),cling_panels,panel_ball14);
		ball_count+=1;
	}
	else if(ball_count==14){
		wxImage Ball15(wxT("C:/workspace/project0/pic/ball15_fit.png"), wxBITMAP_TYPE_PNG);
        wxImage Ball15_c(wxT("C:/workspace/project0/pic/ball15_fit_click.png"), wxBITMAP_TYPE_PNG);
        wxPanel* panel_ball15 = new wxPanel(cling_panels[0],PANEL_15, wxPoint(709-(60*ball_count),3),wxSize(58,57),wxNO_BORDER,"123");
        wxBitmappedButton* item_b15 = new wxBitmappedButton(panel_ball15,BALL_15,TYPE_BALL,Ball15,Ball15_c,wxPoint(0,0),cling_panels,panel_ball15);
		ball_count+=1;
	}
}
