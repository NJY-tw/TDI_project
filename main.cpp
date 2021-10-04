// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <base.h>

#include <wx/window.h>
#include <wx/bitmap.h>
#include <wx/button.h>

/*self define header*/
#include <SD_button.h>
#include <SD_colour.h>

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
    wxBitmap BackGround;
private:
    //Set the event corresponding behavior
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton(wxCommandEvent& event);
    void OnPaint(wxPaintEvent & event);
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Hello = 1,
    ID_Button = 2,
    ID_Background = 3
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
    wxInitAllImageHandlers();
    wxImage testImageBack(wxT("C:/workspace/project0/pic/wood_base.jpg"), wxBITMAP_TYPE_JPEG);

    MyFrame *frame = new MyFrame( "TDI", wxPoint(50, 50), wxSize(650, 440) );
    frame->Show( true );
    // wxInitAllImageHandlers();

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

    //[init image handlers]
    wxInitAllImageHandlers();

    //[load images]
    wxImage testImageBack(wxT("C:/workspace/project0/pic/wood_base.jpg"), wxBITMAP_TYPE_JPEG);
    wxImage testImage(wxT("C:/workspace/project0/pic/ball1.png"), wxBITMAP_TYPE_PNG);
    wxImage testImage1(wxT("C:/workspace/project0/pic/ball1.png"), wxBITMAP_TYPE_PNG);
    

    //[set the background]
    // wxPanel * panelBack = new wxPanel(this, ID_Background, wxDefaultPosition);
    // panelBack->SetBackgroundColour(SD_Orange);
    
    
    
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
    


    //
}
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
void MyFrame::OnPaint(wxPaintEvent & event)
{
    wxPaintDC dc(this);
    dc.DrawBitmap(testImageBack,0,0);
}

void MyFrame::OnButton(wxCommandEvent& event)
{
   
}
