/*
 * << Alternative PDF Library 1.0.0 >> -- text_demo2.c
 *
 * Copyright (c) 1999-2006 Takeshi Kanno <takeshi_kanno@est.hi-ho.ne.jp>
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <setjmp.h>
#include "./libharu/include/hpdf.h"

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

int no = 0;

void
PrintText(HPDF_Page page)
{
    char buf[512];
    HPDF_Point pos = HPDF_Page_GetCurrentTextPos (page);

    no++;
    #ifdef __WIN32__
    _snprintf (buf, 512, ".[%d]%0.2f %0.2f", no, pos.x, pos.y);
    #else
    snprintf (buf, 512, ".[%d]%0.2f %0.2f", no, pos.x, pos.y);
    #endif
    HPDF_Page_ShowText(page, buf);
}


int
main (int argc, char **argv)
{
    HPDF_Doc  pdf;
    HPDF_Page page;
    char fname[256];
    HPDF_Font font;
    float angle1;
    float angle2;
    float rad1;
    float rad2;
    HPDF_REAL page_height;
    HPDF_Rect rect;
    int i;

    const char* SAMP_TXT = "The quick brown fox jumps over the lazy dog. We need more text to test a spiral. Maybe the radians needs to increase with smaller radius. ";

    strcpy (fname, argv[0]);
    strcat (fname, ".pdf");

    pdf = HPDF_New (error_handler, NULL);
    if (!pdf) {
        printf ("error: cannot create PdfDoc object\n");
        return 1;
    }

    if (setjmp(env)) {
        HPDF_Free (pdf);
        return 1;
    }

    /* add a new page object. */
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

//    print_grid  (pdf, page);

    page_height = HPDF_Page_GetHeight (page);

    font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page_SetTextLeading (page, 20);

    /* text along a circle */
    HPDF_Page_SetGrayStroke (page, 0);

    angle2 = 180;

    HPDF_Page_BeginText (page);
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (page, font, 30);
    for (i = 0; i < strlen (SAMP_TXT); i++) {
        char buf[2];
        float x;
        float y;
		//DEJ: rad1 determines the angle of the letter. rad2 is how far
		// around the circle you are. 
        rad1 = (angle2 - 90) / 180 * 3.141592;
        rad2 = angle2 / 180 * 3.141592;

        x = 210 + cos(rad2) * 150;
        y = 300 + sin(rad2) * 150;

        HPDF_Page_SetTextMatrix(page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1), x, y);

        buf[0] = SAMP_TXT[i];
        buf[1] = 0;
        HPDF_Page_ShowText (page, buf);
        angle2 -= 10.0;
    }

    HPDF_Page_EndText (page);

    /* save the document to a file */
    HPDF_SaveToFile (pdf, fname);

    /* clean up */
    HPDF_Free (pdf);

    return 0;
}



