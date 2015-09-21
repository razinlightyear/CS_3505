/*
* Andrew Emrazian CS3505 - HaruPDF implementation
*
*/
#include "../include/hpdf.h"
#include "HaruPDF.h"
#include <string>
#include <stdio.h>
#include <string.h>

#include <iostream>
using namespace std;

		// Constructor. create a workable Haru object.
		HaruPDF::HaruPDF(HPDF_Doc _pdf, HPDF_Page _page, HPDF_Font _font){  // char _fname[256   // std::string _fname
			pdf = _pdf;
			page = _page;
			//fname = _fname;
			font = _font;
			cout << "constructor" << endl;
			cout << "pdf" << endl;
			cout << "page" << endl;
		}

		HPDF_STATUS HaruPDF::HPDF_Page_SetSize (HPDF_PageSizes size, HPDF_PageDirection direction)
		{
			return ::HPDF_Page_SetSize (page, size, direction);
		}

		//HPDF_Page_SetTextLeading (page, 20);
		HPDF_STATUS HaruPDF::HPDF_Page_SetTextLeading (HPDF_REAL value)
		{
			return ::HPDF_Page_SetTextLeading (page, value);
		}

		HPDF_STATUS HaruPDF::HPDF_Page_SetGrayStroke (HPDF_REAL gray)
		{
			return ::HPDF_Page_SetGrayStroke (page, gray);
		}
		
		HPDF_STATUS HaruPDF::HPDF_Page_BeginText()
		{
			return ::HPDF_Page_BeginText(page);
		}

		HPDF_STATUS HaruPDF::HPDF_Page_SetFontAndSize(HPDF_REAL size)
		{
			return ::HPDF_Page_SetFontAndSize(page, font, size);
		}	
		
		void HaruPDF::HPDF_Page_SetTextMatrix(HPDF_REAL a, HPDF_REAL b, HPDF_REAL c, HPDF_REAL d, HPDF_REAL x, HPDF_REAL y)
		{
			::HPDF_Page_SetTextMatrix(page, a, b, c, d, x, y);
		}																		  
				
		HPDF_STATUS HaruPDF::HPDF_Page_ShowText (char buf[])
		{
			return ::HPDF_Page_ShowText(page, buf);
		}
			 									  
	    HPDF_STATUS HaruPDF::HPDF_Page_EndText () // HPDF_Page_EndText (page);
		{
			return ::HPDF_Page_EndText(page);
		}
		
	    /* save the document to a file */
	    HPDF_STATUS HaruPDF::HPDF_SaveToFile() // HPDF_SaveToFile (pdf, fname);
		{
			cout << "fname @ save file	" << fname << endl;
			return ::HPDF_SaveToFile(pdf, fname);
		}

	    /* clean up */
	    void HaruPDF::HPDF_Free()	 // HPDF_Free (pdf);
		{
			::HPDF_Free (pdf);
		}
		
		// getter/setters
		void HaruPDF::set_font (const char* font_name, const char* encoding_name)
		{
			font = ::HPDF_GetFont (pdf, font_name, encoding_name);
		}
	
		void HaruPDF::set_fname(char _fname[])
		{
			//char* f = _fname;
			//fname = f;
			cout << "hey " << endl;
			strcpy (fname, _fname);
						cout << "howdy " << endl;
			cout << "_fname " << _fname << endl;
			cout << "fname " << fname << endl;
		}