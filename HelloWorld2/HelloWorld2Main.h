/***************************************************************
 * Name:      HelloWorld2Main.h
 * Purpose:   Defines Application Frame
 * Author:    Lorenzo ()
 * Created:   2019-10-06
 * Copyright: Lorenzo ()
 * License:
 **************************************************************/

#ifndef HELLOWORLD2MAIN_H
#define HELLOWORLD2MAIN_H

//(*Headers(HelloWorld2Frame)
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/choicebk.h>
#include <wx/frame.h>
//*)

class HelloWorld2Frame: public wxFrame
{
    public:

        HelloWorld2Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~HelloWorld2Frame();

    private:

        //(*Handlers(HelloWorld2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        //*)

        //(*Identifiers(HelloWorld2Frame)
        static const long ID_BUTTON1;
        static const long ID_CHOICEBOOK1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(HelloWorld2Frame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxChoicebook* Choicebook1;
        wxButton* Button1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // HELLOWORLD2MAIN_H
                            