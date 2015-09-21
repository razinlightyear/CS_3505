/*
*  Andrew Emrazian CS3505 - SpiralPDF implementation
*/
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

#include "HaruPDF.h"
#include "Spiral.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <setjmp.h>
//#include "../include/hpdf.h"

jmp_buf env;

#ifdef HPDF_DLL
void __stdcall
#else
void
#endif
error_handler  (HPDF_STATUS   error_no,
                HPDF_STATUS   detail_no,
                void         *user_data)
{
    printf ("ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT)error_no,
                (HPDF_UINT)detail_no);
    longjmp(env, 1);
}

int main (int argc, char *argv[])
{
	if(argc <= 1)
	{
		cout << "ERROR: You must give text via command line to create a PDF." << endl;
		return EXIT_FAILURE;
	}
	
    HPDF_Doc  pdf;

    float angle1;
    float angle2;
    float rad1;
    float rad2;

	 //const char* SAMP_TXT = "I pledge allegiance to the Flag of the United States of America, and to the Republic for which it stands, one Nation under God, indivisible, with liberty and justice for all.";


    pdf = HPDF_New (error_handler, NULL);
    if (!pdf) {
        printf ("error: cannot create PdfDoc object\n");
        return 1;
    }

    if (setjmp(env)) {
        HPDF_Free (pdf);
        return 1;
    }

	HaruPDF haru = HaruPDF(pdf, HPDF_AddPage (pdf), HPDF_GetFont (pdf, "Helvetica", NULL)); 
	char f[strlen(argv[0])+2];
	for(int j = 2; j < strlen(argv[0]); j++)
	{
		f[j-2] = argv[0][j];
	}
	char ext[] = ".pdf";
	for(int j = 0; j < strlen(ext); j++)
	{
		f[strlen(argv[0])-2+j] = ext[j];
	}
	
	haru.set_fname(f);

    /* add a new page object. */
    haru.HPDF_Page_SetSize(HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    haru.HPDF_Page_SetTextLeading(20);

    /* text along a circle */
    haru.HPDF_Page_SetGrayStroke(0);

    angle2 = 180;

    haru.HPDF_Page_BeginText();
    haru.set_font("Courier-Bold", NULL);
    haru.HPDF_Page_SetFontAndSize(25);
/*	
	Spiral spiral = Spiral(210, 300, 30 ,30);
	for( int i = 0; strlen(SAMP_TXT); i++)
	{
		char buf[2];
		haru.HPDF_Page_SetTextMatrix(spiral.get_letter_angle_x(), spiral.get_letter_angle_y(), -spiral.get_letter_angle_y(), spiral.get_letter_angle_x(), spiral.get_x(), spiral.get_y());
		spiral++;
        buf[0] = SAMP_TXT[i];
        buf[1] = 0;
        haru.HPDF_Page_ShowText(buf);
	}
*/	
    float x = 210 + cos(rad2) * 70;
    float y = 300 + sin(rad2) * 70;
    for (int i = 0; i < strlen(argv[1]); i++) {//strlen (SAMP_TXT)
        char buf[2];

        rad1 = (angle2 - 90) / 180 * 3.141592;
        rad2 = angle2 / 180 * 3.141592;

        x = 210 + cos(rad2) * 8 * i;
        y = 300 + sin(rad2) * 8 * i; 
						
        haru.HPDF_Page_SetTextMatrix(cos(rad1), sin(rad1), -sin(rad1), cos(rad1), x, y); 

        buf[0] = argv[1][i];
        buf[1] = 0;
        haru.HPDF_Page_ShowText(buf);
        angle2 -= 10.0; // Change depending on the radius.
    }
	cout << "got past for loop" << endl;
    haru.HPDF_Page_EndText();
	cout << "past HPDF_Page_EndText" << endl;
    /* save the document to a file */
    haru.HPDF_SaveToFile();
	cout << "past HPDF_SaveToFile" << endl;
    /* clean up */
    haru.HPDF_Free();
	cout << "past HPDF_Free" << endl;
    return 0;
	
	
}


