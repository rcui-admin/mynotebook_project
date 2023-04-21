/***************************************************************
 * Name:      notebook_project.h
 * Purpose:   Code for Application Frame
 * Author:    Richard Cui (rcui002@fiu.edu)
 * Created:   2023-04-16
 * Copyright: Richard Cui ()
 * License:
 **************************************************************/

#ifndef NOTEBOOK_PROJECT_H
#define NOTEBOOK_PROJECT_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/notebook.h>
#include "notebook_projectApp.h"

// Define the notebook_projectFrame class which represents the main window of the application
// Sets up public and private constructors for functions
class notebook_projectFrame : public wxFrame
{
public:
    notebook_projectFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    ~notebook_projectFrame();
private:
	enum
        {
            idMenuQuit,
            idAddPage,
            idInsertPage,
            idDeletePage,
            idMenuAbout,
        };
	int pageCount;								// int variable to hold the number of tabs opened
	int currentPage;							// int variable to hold the page number of the selected tab
	wxString pageTitle;							// String object to hold the title of the tabs
	wxTextCtrl* textControl;					// Pointer to the TextCtrl object
    wxNotebook* my_notebook; 					// Pointer to the notebook object
    void OnAddPage(wxCommandEvent& event);		// Event handler for the "Add Page" menu item
    void OnInsertPage(wxCommandEvent& event);   // Event handler for the "Insert Page" menu item
    void OnDeletePage(wxCommandEvent& event);	// Event handler for the "Delete Page" menu item
    void OnQuit(wxCommandEvent& event);			// Event handler for the "Quit" menu item
    void OnAbout(wxCommandEvent& event);		// Event handler for the "About" menu item
    void OnClose(wxCloseEvent& event);			// Event handler for the "Close" menu item

    DECLARE_EVENT_TABLE();						// A data structure to hold the events and functions used in each event
};

#endif // NOTEBOOK_PROJECT_H
