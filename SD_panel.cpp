#include "SD_panel.h"

BEGIN_EVENT_TABLE(wxBitmapBGPanel, wxPanel)
EVT_PAINT(wxBitmapBGPanel::OnPaint)
END_EVENT_TABLE()

wxBitmapBGPanel::wxBitmapBGPanel(wxWindow *parent, wxBitmap Background, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER, const wxString& name = wxASCII_STR(wxPanelNameStr)):
            wxPanel(parent, winid , pos, size, style, name), 
            SD_Background(Background)
{

}

void wxBitmapBGPanel::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	dc.DrawBitmap(SD_Background,0,0,false);
}

wxTransparentPanel::wxTransparentPanel(wxWindow *parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER, const wxString& name = wxASCII_STR(wxPanelNameStr)):
            wxPanel()
{
    SetBackgroundStyle(wxBG_STYLE_TRANSPARENT);
    Create(parent, winid, pos, size, style, name);
}
