// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <base.h>

#include <wx/window.h>
#include <wx/bitmap.h>
#include <wx/button.h>

/*self define header*/
#include <SD_button.h>
#include <SD_colour.h>
#include <SD_panel.h>

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
    wxBitmap SD_Background;

    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton(wxCommandEvent& event);
    
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Hello = 1,
    ID_Button = 2,
    ID_BasicPanel = 3

};

//bind the ID number with the behavior
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_BUTTON(ID_Button, MyFrame::OnButton)
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
    //
    
    //[create button]


    // wxPanel * panel = new wxPanel(this, ID_BasicPanel, wxPoint(100,100),wxSize(50,50));
    // panel->SetBackgroundColour(SD_Black);

    // wxPanel * panel1 = new wxPanel(panel, ID_BasicPanel, wxPoint(100,100),wxSize(50,50));

    wxImage BG(wxT("C:/workspace/project0/pic/BackGround.png"), wxBITMAP_TYPE_PNG);

    wxImage rack_h(wxT("C:/workspace/project0/pic/rack_fit.png"), wxBITMAP_TYPE_PNG);

    wxImage rack_l(wxT("C:/workspace/project0/pic/rack_fit.png"), wxBITMAP_TYPE_PNG);

    
    wxBitmapBGPanel* panel_BG = new wxBitmapBGPanel(this,BG,ID_BasicPanel, wxPoint(100,100),wxSize(50,50),wxNO_BORDER,"123");

    wxPanel* panel_new = new wxPanel(panel_BG,ID_BasicPanel, wxPoint(765,348.5),wxSize(108,106),wxNO_BORDER,"123");

    wxBitmapBGPanel* panel_rack_h = new wxBitmapBGPanel(panel_BG,rack_h,ID_BasicPanel, wxPoint(57,45),wxSize(789,65),wxNO_BORDER,"123");
    
    wxPanel* panel_ball1 = new wxPanel(panel_rack_h,ID_BasicPanel, wxPoint(300,5),wxSize(60,59),wxNO_BORDER,"123");
    //wxTransparentPanel * panel1 = new wxTransparentPanel(panel, ID_BasicPanel, wxPoint(100,100),wxSize(50,50),wxNO_BORDER,"456");
    
    
    
    // panel->SetBackgroundColour(SD_Orange);
    
    // wxImage BG1(wxT("C:/workspace/project0/pic/wood_base.jpg"), wxBITMAP_TYPE_JPEG);
    // wxBitmap BG(BG1);
    // wxBitmapBGPanel* panel = new wxBitmapBGPanel(this,BG,ID_BasicPanel, wxPoint(100,100),wxSize(50,50),wxNO_BORDER,"123");
    // wxPanel * panel1 = new wxPanel(panel, wxID_ANY, wxPoint(100,100),wxSize(50,50),wxNO_BORDER,"456");
    // panel1->SetBackgroundColour(wxTRANSPARENT);

    wxImage new_button(wxT("C:/workspace/project0/pic/n_fit.png"), wxBITMAP_TYPE_PNG);
    //wxImage ImageBall1_p(wxT("C:/workspace/project0/pic/ball1.png"), wxBITMAP_TYPE_PNG);
    

    wxImage ImageBall1(wxT("C:/workspace/project0/pic/ball1_fit.png"), wxBITMAP_TYPE_PNG);
    //wxImage ImageBall1_p(wxT("C:/workspace/project0/pic/ball1.png"), wxBITMAP_TYPE_PNG);
    
    
    
    //wxBitmap button1(ImageBall1);
    
    wxBitmappedButton* button_new = new wxBitmappedButton(panel_new,ID_Button,new_button,new_button,wxPoint(0,0));

    wxBitmappedButton* item_b1 = new wxBitmappedButton(panel_ball1,ID_Button,ImageBall1,ImageBall1,wxPoint(0,0));
    //SD_Button_b1->SetBackgroundColour(wxTRANSPARENT);
    //SD_Button_b1->SetBackgroundStyle(wxBG_STYLE_TRANSPARENT);
    //SD_Button_b1->SetSize(50,50);
    
    
    //[button trial]
    // wxPanel * panel = new wxPanel(panelBack, wxID_ANY, wxDefaultPosition,wxSize(300,300));
    // panel->SetBackgroundColour(SD_Orange);
    

    
    // testImage.Rescale(50,50);
    // testImage1.Rescale(45,45);

    // wxBitmap testBitmap(testImage);
    // wxBitmap testBitmap1(testImage1);

    // wxBitmappedButton* testButton = new wxBitmappedButton(panel,ID_Button,testBitmap,testBitmap1,wxPoint(100,100));
    // testButton->SetBackgroundColour(SD_Orange);
    
    
    //testButton->SetBitmap(testBitmap);

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

void MyFrame::OnButton(wxCommandEvent& event)
{
   
}