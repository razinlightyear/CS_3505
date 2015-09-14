/*
* Provides access to haru function calls
*
*
*/

//namespace HaruWrapper
//{
	// include stuff
	class HaruPDF {

		// private data members
		font
		page
		pdf // ?
	private:
	
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
	
	public:
		// Constructor. create a workable Haru object.
		HaruPDF(){
	
		}

		HaruPDF::Haru_make_pdf(char *filename) {
		   ::Haru_make_pdf( page, font, "filename.pdf");

		}

	    HPDF_STATUS HaruPDF::HPDF_Page_EndText () // HPDF_Page_EndText (page);
		{
			return ::HPDF_Page_EndText (page);
		}
		
	    /* save the document to a file */
	    void HaruPDF::HPDF_SaveToFile (fname) // HPDF_SaveToFile (pdf, fname);
		{
			::HPDF_SaveToFile (pdf, fname);
		}

	    /* clean up */
	    void HaruPDF::HPDF_Free ()	 // HPDF_Free (pdf);
		{
			::HPDF_Free (pdf);
		}
		
		// getter/setters
	
		// operator overlaoding
	};
	//} // namespace