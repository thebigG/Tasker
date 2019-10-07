/***************************************************************
 * Name:      HelloWorld2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Lorenzo ()
 * Created:   2019-10-06
 * Copyright: Lorenzo ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "HelloWorld2Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(HelloWorld2Frame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(HelloWorld2Frame)
const long HelloWorld2Frame::ID_BUTTON1 = wxNewId();
const long HelloWorld2Frame::ID_CHOICEBOOK1 = wxNewId();
const long HelloWorld2Frame::ID_PANEL1 = wxNewId();
const long HelloWorld2Frame::idMenuQuit = wxNewId();
const long HelloWorld2Frame::idMenuAbout = wxNewId();
const long HelloWorld2Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(HelloWorld2Frame,wxFrame)
    //(*EventTable(HelloWorld2Frame)
    //*)
END_EVENT_TABLE()

HelloWorld2Frame::HelloWorld2Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(HelloWorld2Frame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(128,112), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Label"), wxPoint(136,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Choicebook1 = new wxChoicebook(Panel1, ID_CHOICEBOOK1, wxPoint(184,216), wxDefaultSize, 0, _T("ID_CHOICEBOOK1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HelloWorld2Frame::OnButton1Click);
    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&HelloWorld2Frame::OnPanel1Paint,0,this);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&HelloWorld2Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&HelloWorld2Frame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&HelloWorld2Frame::OnClose);
    //*)
}

HelloWorld2Frame::~HelloWorld2Frame()
{
    //(*Destroy(HelloWorld2Frame)
    //*)
}

void HelloWorld2Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void HelloWorld2Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void HelloWorld2Frame::OnClose(wxCloseEvent& event)
{
}

void HelloWorld2Frame::OnButton1Click(wxCommandEvent& event)
{
}

void HelloWorld2Frame::OnPanel1Paint(wxPaintEvent& event)
{
}
