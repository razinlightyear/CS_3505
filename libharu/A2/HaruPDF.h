	
/*
* Andrew Emrazian CS3505 - HaruPDF prototyping
*
*/
// include gaurds?
#include "../include/hpdf.h"
#include <string>

class HaruPDF {	

private:
	// private data members
    HPDF_Doc pdf;
    HPDF_Page page;
	char fname[256];
    HPDF_Font font;
	
public:
	// Constructor. create a workable Haru object.
	HaruPDF(HPDF_Doc _pdf, HPDF_Page _page, HPDF_Font _font); //char _fname[256]

	HPDF_STATUS HPDF_Page_SetSize (HPDF_PageSizes size, HPDF_PageDirection direction);

	//HPDF_Page_SetTextLeading (page, 20);
	HPDF_STATUS HPDF_Page_SetTextLeading (HPDF_REAL value);

	HPDF_STATUS HPDF_Page_SetGrayStroke (HPDF_REAL gray);
	
	HPDF_STATUS HPDF_Page_BeginText();

	HPDF_STATUS HPDF_Page_SetFontAndSize(HPDF_REAL size);
	
	void HPDF_Page_SetTextMatrix(HPDF_REAL a, HPDF_REAL b, HPDF_REAL c, HPDF_REAL d, HPDF_REAL x, HPDF_REAL y);								  
			
	HPDF_STATUS HPDF_Page_ShowText (char buf[]);
		 									  
    HPDF_STATUS HPDF_Page_EndText ();
	
    /* save the document to a file */
    HPDF_STATUS HPDF_SaveToFile();

    /* clean up */
    void HPDF_Free();
	
	// getter/setters
	void set_font (const char* font_name, const char* encoding_name);

	void set_fname(char _fname[]); //void set_fname(char _fname[256]);
};