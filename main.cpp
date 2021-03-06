// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <base.h>

#include <wx/window.h>
#include <wx/bitmap.h>
#include <wx/button.h>

/*self define header*/
#include <SD_button.h>
#include <SD_colour.h>
// #include <SD_panel.h>

enum 
{
    ID_Hello=0,
    ID_BUTTON_NEW,
    ID_BUTTON_SAVE,
    ID_BUTTON_MODE,
    ID_BASIC,
};

//#include <wx/wxShapedWindow.h>

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    

private:
    //Set the event corresponding behavior
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton(wxCommandEvent& event);
    void BallCreate();
    
    wxDECLARE_EVENT_TABLE();
};



//bind the ID number with the behavior
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_PAINT(MyFrame::OnPaint)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    //[init image handlers]
    wxInitAllImageHandlers();
    //[load background]
    
    MyFrame *frame = new MyFrame( "TDI", wxPoint(0, 0), wxSize(940, 580));
    frame->Show( true );
    
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    
    //[default frame]
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Author\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "TDI sorts your To Do Items !" );
    //r
    
    //[create button]

    //panels
    wxImage BG(wxT("C:/workspace/project0/pic/BackGround.png"), wxBITMAP_TYPE_PNG);

    wxImage rack(wxT("C:/workspace/project0/pic/rack_fit.png"), wxBITMAP_TYPE_PNG);


    wxBitmapBGPanel* panel_racks[2];
    //buttons
    wxBitmapBGPanel* panel_BG = new wxBitmapBGPanel(this,BG,ID_BASIC, wxPoint(100,100),wxSize(50,50),wxNO_BORDER,"123");

    wxPanel* panel_new = new wxPanel(panel_BG,ID_BASIC, wxPoint(765,350.5),wxSize(98,97));

    wxPanel* panel_save = new wxPanel(panel_BG,ID_BASIC, wxPoint(765,225.4),wxSize(97,96),wxNO_BORDER,"123");

    wxPanel* panel_mode = new wxPanel(panel_BG,ID_BASIC, wxPoint(708.6,228.2),wxSize(38,87),wxNO_BORDER,"123");

    wxBitmapBGPanel* panel_rack_h = new wxBitmapBGPanel(panel_BG,rack,ID_BASIC, wxPoint(57,45),wxSize(789,65),wxNO_BORDER,"123");

    wxBitmapBGPanel* panel_rack_l = new wxBitmapBGPanel(panel_BG,rack,ID_BASIC, wxPoint(57,129.6),wxSize(789,65),wxNO_BORDER,"123");

    panel_racks[0] = panel_rack_h;
    panel_racks[1] = panel_rack_l;
    
    //wxPanel* panel_ball10 = new wxPanel(panel_rack_h,ID_PanelBall_10, wxPoint(300,5),wxSize(59,58),wxNO_BORDER,"123");
    

    wxImage new_button(wxT("C:/workspace/project0/pic/n_fit.png"), wxBITMAP_TYPE_PNG);
    wxImage new_button_c(wxT("C:/workspace/project0/pic/n_fit_click.png"), wxBITMAP_TYPE_PNG);  
    // wxBitmap new_button_bm(new_button);
    // wxBitmap new_button_c_bm(new_button_c);

    wxImage mode_button_0(wxT("C:/workspace/project0/pic/flip_high_fit.png"), wxBITMAP_TYPE_PNG);
    wxImage mode_button_1(wxT("C:/workspace/project0/pic/flip_middle_fit.png"), wxBITMAP_TYPE_PNG);  
    wxImage mode_button_2(wxT("C:/workspace/project0/pic/flip_low_fit.png"), wxBITMAP_TYPE_PNG);  

    wxImage save_button(wxT("C:/workspace/project0/pic/s_fit.png"), wxBITMAP_TYPE_PNG);
    wxImage save_button_c(wxT("C:/workspace/project0/pic/s_fit_click.png"), wxBITMAP_TYPE_PNG);  

    wxImage ImageBall9(wxT("C:/workspace/project0/pic/ball9_fit.png"), wxBITMAP_TYPE_PNG);
    wxImage ImageBall9_c(wxT("C:/workspace/project0/pic/ball9_fit_click.png"), wxBITMAP_TYPE_PNG);

    wxImage ImageBall10(wxT("C:/workspace/project0/pic/ball10_fit.png"), wxBITMAP_TYPE_PNG);
    wxImage ImageBall10_c(wxT("C:/workspace/project0/pic/ball10_fit_click.png"), wxBITMAP_TYPE_PNG);
 
    
    wxBitmappedButton* button_new = new wxBitmappedButton(panel_new,ID_BUTTON_NEW,TYPE_NEW,new_button,new_button_c,wxPoint(0,0),panel_racks,nullptr);
    
    wxBitmappedButton* button_save = new wxBitmappedButton(panel_save,ID_BUTTON_SAVE,TYPE_NEW,save_button,save_button_c,wxPoint(0,0),panel_racks,nullptr);

    wxBitmappedButton* button_mode = new wxBitmappedButton(panel_mode,ID_BUTTON_MODE,TYPE_SORT,mode_button_0,mode_button_1,mode_button_2,wxPoint(0,0));

    //wxBitmappedButton* item_b1 = new wxBitmappedButton(panel_ball10,ID_Button_Ball10,0,ImageBall10,ImageBall10_c,wxPoint(0,0));

}

//action taken
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("A little help from Alexander");
}



