
/***************************************************************
 * Name:      notebook_projectApp.h
 * Purpose:   Code for Application Frame
 * Author:    Richard Cui (rcui002@fiu.edu)
 * Created:   2023-04-16
 * Copyright: Richard Cui ()
 * License:
 **************************************************************/

#ifndef NOTEBOOK_PROJECTAPP_H
#define NOTEBOOK_PROJECTAPP_H

#include <wx/app.h>


// Define the notebook_projectApp class which represents the application object
class notebook_projectApp : public wxApp
{
public:
    virtual bool OnInit() override;
};


#endif // NOTEBOOK_PROJECTAPP_H
