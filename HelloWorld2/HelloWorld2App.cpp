/***************************************************************

 * Name:      HelloWorld2App.cpp
 * Purpose:   Code for Application Class
 * Author:    Lorenzo ()
 * Created:   2019-10-06
 * Copyright: Lorenzo ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "HelloWorld2App.h"

//(*AppHeaders
#include "HelloWorld2Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(HelloWorld2App);

bool HelloWorld2App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	HelloWorld2Frame* Frame = new HelloWorld2Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
