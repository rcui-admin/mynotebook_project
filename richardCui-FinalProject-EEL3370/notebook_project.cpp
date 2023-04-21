/***************************************************************
 * Name:      notebook_project.cpp
 * Purpose:   Code for Application Frame
 * Author:    Richard Cui (rcui002@fiu.edu)
 * Created:   2023-04-16
 * Copyright: Richard Cui ()
 * License:
 **************************************************************/
#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "notebook_project.h"

// Declare Build information about wxWidgets version and other technical details
enum wxbuildinfoformat
{
    short_f, long_f
    };

// Define Build information of wxWidgets
wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
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

IMPLEMENT_APP(notebook_projectApp);

bool notebook_projectApp::OnInit()
{
	// Create an instance of notebook_projectFrame and show it
    notebook_projectFrame *frame = new notebook_projectFrame("Richard Cui - Final Project Demonstration", wxDefaultPosition, wxDefaultSize);
    int width, height;												//set variables for window width and height
    frame->GetSize(&width, &height);								//returns the size of the entire window to window width and window height
    frame->SetSize(200, 100, 800, 600, wxDefaultCoord);
    //sets the size of the windows in pixels (x position, y position, window width, window height, interpretation of other parameters)
    //this overload sets the position and size of the window, wxDefaultCoord is the default value supplied by wxWidgets

    frame->Show(true);
    return true;
}

// Event table for the notebook_projectFrame class
BEGIN_EVENT_TABLE(notebook_projectFrame, wxFrame)
	EVT_CLOSE(notebook_projectFrame::OnClose)
    EVT_MENU(idAddPage, notebook_projectFrame::OnAddPage)
    EVT_MENU(idInsertPage, notebook_projectFrame::OnInsertPage)
    EVT_MENU(idDeletePage, notebook_projectFrame::OnDeletePage)
    EVT_MENU(idMenuQuit, notebook_projectFrame::OnQuit)
    EVT_MENU(idMenuAbout, notebook_projectFrame::OnAbout)
END_EVENT_TABLE()


// Set up a Window of the project using the wxFrame utility to design the frame
notebook_projectFrame::notebook_projectFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenuBar* menuBar = new wxMenuBar;  			// Create a menu bar

    wxMenu* fileMenu = new wxMenu(_T(""));    										// Create a "File" menu
    fileMenu->Append(idAddPage, "&Add Page", "Add a new page");
    fileMenu->Append(idInsertPage, "&Insert Page", "Insert a page");
    fileMenu->Append(idDeletePage, "&Delete Page", "Delete the current page");
    fileMenu->AppendSeparator();
    fileMenu->Append(idMenuQuit, "&Quit", "Quit the application");
    menuBar->Append(fileMenu, "&Notebook Operations");    							// Add the menus to the menu bar

    wxMenu* helpMenu = new wxMenu(_T("")); 											// Another fileMenu for Help section
    helpMenu->Append(idMenuAbout, "&About", "Show info about this application");
	menuBar->Append(helpMenu, "&Help");  											// Add the menus to the menu bar

    SetMenuBar(menuBar);  // Set the menu bar for the frame

    my_notebook = new wxNotebook(this, wxID_ANY);     // Create a notebook object

    // Add the initial page
    pageCount = 1;
    pageTitle = wxString::Format("Page %d", pageCount);
    textControl = new wxTextCtrl(my_notebook, wxID_ANY, pageTitle + "\nHello! Welcome to my program, please feel free to type stuff!", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH);
    my_notebook->AddPage(textControl, pageTitle);

    // Create a sizer to manage the layout of the frame
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(my_notebook, 1, wxEXPAND);
    SetSizerAndFit(sizer);

    // Create a status bar to display info
    CreateStatusBar(1);
    SetStatusText("Hello it's  " + wxDateTime::Now().Format(" %c  using  " + wxbuildinfo(short_f)),0);
}

// Functions defined here


notebook_projectFrame::~notebook_projectFrame()
{
}


void notebook_projectFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void notebook_projectFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void notebook_projectFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, "wxWidgets Build");
}

void notebook_projectFrame::OnAddPage(wxCommandEvent& event)
{
	pageCount++;
    pageTitle = wxString::Format("Page %d", pageCount);
	textControl = new wxTextCtrl(my_notebook, wxID_ANY, pageTitle, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH);
	my_notebook->AddPage(textControl, pageTitle);
}


void notebook_projectFrame::OnInsertPage(wxCommandEvent& event)
{
	currentPage = my_notebook->GetSelection();
    if (currentPage != wxNOT_FOUND)
    {
    	pageCount++;
        pageTitle = wxString::Format("Page %d", pageCount);
        textControl = new wxTextCtrl(my_notebook, wxID_ANY, pageTitle, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH);
        my_notebook->InsertPage(currentPage, textControl, pageTitle);
    }
}


void notebook_projectFrame::OnDeletePage(wxCommandEvent& event)
{
    currentPage = my_notebook->GetSelection();
    if (currentPage != wxNOT_FOUND) {
        my_notebook->RemovePage(currentPage);
    }
}

