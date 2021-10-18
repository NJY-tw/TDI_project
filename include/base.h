//define all needed self defined include file and configuration here
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    friend void BallCreate();

protected :  
    int ball_count;
    wxBitmapBGPanel* panel_rack_h;
private:
    //Set the event corresponding behavior
    // int ball_count;
    // wxBitmapBGPanel* panel_rack_h;
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton(wxCommandEvent& event);
    //static void BallCreate();
    
    wxDECLARE_EVENT_TABLE();
};

extern void BallCreate();
