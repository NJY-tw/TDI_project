#include <base.h>
#include <wx/bitmap.h>


class wxBitmapBGPanel : public wxPanel
{
	wxBitmap SD_Background;
	
public:
	wxBitmapBGPanel(wxWindow *parent,
            wxBitmap Background,
            wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size,
            long style,
            const wxString& name);

	DECLARE_EVENT_TABLE();


	void OnPaint(wxPaintEvent & event);
};


class wxTransparentPanel : public wxPanel
{
    public:
	wxTransparentPanel(wxWindow *parent,
            wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size,
            long style,
            const wxString& name);
};