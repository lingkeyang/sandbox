//
//   glwin.h
//
// minimal opengl on windows framework for writing small opengl test apps
// all in one header file.  No extra downloads, installs, cmake, .DLLs, .LIBs. etc...
//
// try not to use that 16 bit wchar.
//


//
//   bitmap font code from the OpenGL red book example programs the copyright from that sample is:
//
// (c) Copyright 1993, Silicon Graphics, Inc.
//                1993-1995 Microsoft Corporation
//
// ALL RIGHTS RESERVED
//
// Please refer to OpenGL/readme.txt for additional information
//


#include <functional>

#define NOMINMAX
#include <windows.h>
#include <cstring>
#include <GL/gl.h>
#include <GL/glu.h>
#ifdef WIN32
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#endif

class GLWin
{


	GLuint fontOffset;
	void MakeRasterFont(void)
	{
		GLubyte rasters[][13] = {  
			{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18}, 
			{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x36, 0x36, 0x36}, 
			{0x00, 0x00, 0x00, 0x66, 0x66, 0xff, 0x66, 0x66, 0xff, 0x66, 0x66, 0x00, 0x00}, 
			{0x00, 0x00, 0x18, 0x7e, 0xff, 0x1b, 0x1f, 0x7e, 0xf8, 0xd8, 0xff, 0x7e, 0x18}, 
			{0x00, 0x00, 0x0e, 0x1b, 0xdb, 0x6e, 0x30, 0x18, 0x0c, 0x76, 0xdb, 0xd8, 0x70}, 
			{0x00, 0x00, 0x7f, 0xc6, 0xcf, 0xd8, 0x70, 0x70, 0xd8, 0xcc, 0xcc, 0x6c, 0x38}, 
			{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1c, 0x0c, 0x0e}, 
			{0x00, 0x00, 0x0c, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x18, 0x0c}, 
			{0x00, 0x00, 0x30, 0x18, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x18, 0x30}, 
			{0x00, 0x00, 0x00, 0x00, 0x99, 0x5a, 0x3c, 0xff, 0x3c, 0x5a, 0x99, 0x00, 0x00}, 
			{0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18, 0x00, 0x00}, 
			{0x00, 0x00, 0x30, 0x18, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x60, 0x60, 0x30, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x06, 0x06, 0x03, 0x03}, 
			{0x00, 0x00, 0x3c, 0x66, 0xc3, 0xe3, 0xf3, 0xdb, 0xcf, 0xc7, 0xc3, 0x66, 0x3c}, 
			{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x38, 0x18}, 
			{0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x03, 0xe7, 0x7e}, 
			{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0x07, 0x03, 0x03, 0xe7, 0x7e}, 
			{0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0xff, 0xcc, 0x6c, 0x3c, 0x1c, 0x0c}, 
			{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xff}, 
			{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e}, 
			{0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x03, 0x03, 0xff}, 
			{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e}, 
			{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x03, 0x7f, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e}, 
			{0x00, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x30, 0x18, 0x1c, 0x1c, 0x00, 0x00, 0x1c, 0x1c, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06}, 
			{0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x60}, 
			{0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x18, 0x0c, 0x06, 0x03, 0xc3, 0xc3, 0x7e}, 
			{0x00, 0x00, 0x3f, 0x60, 0xcf, 0xdb, 0xd3, 0xdd, 0xc3, 0x7e, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18}, 
			{0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe}, 
			{0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e}, 
			{0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc}, 
			{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff}, 
			{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff}, 
			{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e}, 
			{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3}, 
			{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e}, 
			{0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06}, 
			{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3}, 
			{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0}, 
			{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3}, 
			{0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3}, 
			{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e}, 
			{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe}, 
			{0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c}, 
			{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe}, 
			{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e}, 
			{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff}, 
			{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3}, 
			{0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3}, 
			{0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3}, 
			{0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3}, 
			{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3}, 
			{0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff}, 
			{0x00, 0x00, 0x3c, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3c}, 
			{0x00, 0x03, 0x03, 0x06, 0x06, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x30, 0x60, 0x60}, 
			{0x00, 0x00, 0x3c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x3c}, 
			{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0x66, 0x3c, 0x18}, 
			{0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x38, 0x30, 0x70}, 
			{0x00, 0x00, 0x7f, 0xc3, 0xc3, 0x7f, 0x03, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0}, 
			{0x00, 0x00, 0x7e, 0xc3, 0xc0, 0xc0, 0xc0, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x7f, 0xc3, 0xc3, 0xc3, 0xc3, 0x7f, 0x03, 0x03, 0x03, 0x03, 0x03}, 
			{0x00, 0x00, 0x7f, 0xc0, 0xc0, 0xfe, 0xc3, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x33, 0x1e}, 
			{0x7e, 0xc3, 0x03, 0x03, 0x7f, 0xc3, 0xc3, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0}, 
			{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x18, 0x00}, 
			{0x38, 0x6c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x0c, 0x00}, 
			{0x00, 0x00, 0xc6, 0xcc, 0xf8, 0xf0, 0xd8, 0xcc, 0xc6, 0xc0, 0xc0, 0xc0, 0xc0}, 
			{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78}, 
			{0x00, 0x00, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xfe, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xfc, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00}, 
			{0xc0, 0xc0, 0xc0, 0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0x00, 0x00, 0x00, 0x00}, 
			{0x03, 0x03, 0x03, 0x7f, 0xc3, 0xc3, 0xc3, 0xc3, 0x7f, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xfe, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0xfe, 0x03, 0x03, 0x7e, 0xc0, 0xc0, 0x7f, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x1c, 0x36, 0x30, 0x30, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x00}, 
			{0x00, 0x00, 0x7e, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0xc3, 0xe7, 0xff, 0xdb, 0xc3, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0xc3, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0xc3, 0x00, 0x00, 0x00, 0x00}, 
			{0xc0, 0x60, 0x60, 0x30, 0x18, 0x3c, 0x66, 0x66, 0xc3, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0xff, 0x60, 0x30, 0x18, 0x0c, 0x06, 0xff, 0x00, 0x00, 0x00, 0x00}, 
			{0x00, 0x00, 0x0f, 0x18, 0x18, 0x18, 0x38, 0xf0, 0x38, 0x18, 0x18, 0x18, 0x0f}, 
			{0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18}, 
			{0x00, 0x00, 0xf0, 0x18, 0x18, 0x18, 0x1c, 0x0f, 0x1c, 0x18, 0x18, 0x18, 0xf0}, 
			{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x8f, 0xf1, 0x60, 0x00, 0x00, 0x00} 
		};
		GLuint i;
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		fontOffset = glGenLists (128);
		for (i = 32; i < 127; i++) {
			glNewList(i+fontOffset, GL_COMPILE);
			glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, rasters[i-32]);
			glEndList();
		}
	}


	void SpitLetters(char *s) 
	{
		glPushAttrib (GL_LIST_BIT);
		glListBase(fontOffset);
		glCallLists(strlen(s), GL_UNSIGNED_BYTE, (GLubyte *) s);
		glPopAttrib ();
	}



	HWND CreateOpenGLWindow(const char* title)
	{
		// make a double-buffered, rgba, opengl window
		
		HWND        hWnd;
		WNDCLASSA   wc;   // force non unicode 16 version
		int         pf;
		PIXELFORMATDESCRIPTOR pfd;
		static HINSTANCE hInstance = 0;

		/* only register the window class once - use hInstance as a flag. */
		if (!hInstance) {
			hInstance = GetModuleHandle(NULL);
			wc.style         = CS_OWNDC;
			wc.lpfnWndProc   = (WNDPROC)MsgProcG;
			wc.cbClsExtra    = 0;
			wc.cbWndExtra    = 0;
			wc.hInstance     = hInstance;
			wc.hIcon         = LoadIcon(NULL, IDI_WINLOGO);
			wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
			wc.hbrBackground = NULL;
			wc.lpszMenuName  = NULL;
			wc.lpszClassName = "OpenGL";

			if (!RegisterClass(&wc)) 
				throw("RegisterClass() failed:  Cannot register window class.");
		}

		hWnd = CreateWindowA("OpenGL", title, WS_OVERLAPPEDWINDOW |
				WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
				0,0,Width,Height, NULL, NULL, hInstance, this);  // force non-unicode16 non-wchar version of Windows's CreateWindow

		if (hWnd == NULL)
			throw("CreateWindow() failed:  Cannot create a window.");

		hDC = GetDC(hWnd);

		/* there is no guarantee that the contents of the stack that become
		   the pfd are zeroed, therefore _make sure_ to clear these bits. */
		memset(&pfd, 0, sizeof(pfd));
		pfd.nSize        = sizeof(pfd);
		pfd.nVersion     = 1;
		pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType   = PFD_TYPE_RGBA;
		pfd.cDepthBits   = 32;
		pfd.cColorBits   = 32;

		pf = ChoosePixelFormat(hDC, &pfd);
		if(pf == 0) 
			throw("ChoosePixelFormat() failed:  Cannot find a suitable pixel format."); 
		if (SetPixelFormat(hDC, pf, &pfd) == FALSE) 
			throw( "SetPixelFormat() failed: Cannot set format specified.");
 
		ReleaseDC(hWnd,hDC);
		return hWnd;
	}    
	void ComputeMouseVector(){
		OldMouseVector=MouseVector;
		float spread = (float)tan(ViewAngle/2*3.14/180);  
		float y = spread * ((Height-MouseY)-Height/2.0f) /(Height/2.0f);
		float x = spread * (MouseX-Width/2.0f)  /(Height/2.0f);
		MouseVector = normalize(float3(x,y,-1));
	}
	void Reshape(int width, int height){
		// called initially and when the window changes size
		Width=width;
		Height=height;
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(ViewAngle, (float)width/height, 0.1, 50.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	void DestroyOpenGLWindow()
	{
		if(!hWnd)
			return; // already destroyed or otherwise non existent
	    wglMakeCurrent(NULL, NULL);
		ReleaseDC(hWnd,hDC);
		wglDeleteContext(hRC);
		DestroyWindow(hWnd);
		hWnd=NULL;

	}
public:
	void PrintString(char *s,float x,float y) {
		if(!s) return;
		glPushAttrib(GL_LIGHTING_BIT|GL_DEPTH_BUFFER_BIT|GL_TEXTURE_BIT);
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_LIGHTING);
   			glDisable(GL_DEPTH_TEST);
			//glRasterPos3f(0,0,-2);
			//spitletters("Origin");
			glMatrixMode(GL_PROJECTION);
			  glPushMatrix();
				glLoadIdentity();
				glOrtho (0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
					glRasterPos2f(x,y);
					SpitLetters(s);
					glRasterPos2f(0,0);
			  glPopMatrix();
			glMatrixMode(GL_MODELVIEW);
		glPopAttrib();
	}

	void PrintString(char *s,int x,int y)
	{
		int rows = Height/14;
		int cols = Width/10;
		if(y>=rows){ y=rows-1;}
		if(y<0) { y+= rows;} // caller gives a negative y
		if(y<0) { y = 0;} // caller gives a too much negative y
		if(x<0) { x = cols+x-strlen(s)+1;}
		if(x+(int)strlen(s)>cols) { x=cols-strlen(s);}
		if(x<0) {x=0;}
		y=rows-1-y; // invert y so row 0 is at the top and -1 is at the bottom
		PrintString(s,(float)x/(float)cols,(float)y/(float)rows);
	}

	HWND    hWnd;
	HDC     hDC;              // device context 
    HGLRC   hRC;              // opengl context 
	int 	Width  ;
	int 	Height ;
	int     MouseX ;
	int     MouseY ;
	float3  MouseVector;      // 3D direction mouse points
	float3  OldMouseVector;
	int     MouseState;     // true iff left button down
	float 	ViewAngle;
	std::function<void(int, int, int)> keyboardfunc;

	GLWin(const char *title) : Width(512), Height(512), MouseX(0), MouseY(0), MouseState(0), ViewAngle(45.0f) //, keyboardfunc([](int, int, int){})
	{
		hWnd = CreateOpenGLWindow(title);
		if (hWnd == NULL) throw("failed to create opengl window");

		hDC = GetDC(hWnd);
		hRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hRC);
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow( hWnd );
		glEnable(GL_DEPTH_TEST);
		MakeRasterFont();
	}
	~GLWin()
	{
		DestroyOpenGLWindow();
	}
	LONG WINAPI MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{ 

		switch(uMsg) {
		case WM_SIZE:
			Reshape(LOWORD(lParam), HIWORD(lParam));
			PostMessage(hWnd, WM_PAINT, 0, 0);
			return 0;
		case WM_CHAR:
			switch (wParam) {
				case 27: /* ESC key */
					PostQuitMessage(0);
					break;
			}
			if(keyboardfunc)
				keyboardfunc(wParam, MouseX, MouseY); // to match glut's api, add the x and y.
			return 0;

		case WM_LBUTTONDOWN:
			SetCapture(hWnd);  // set the capture to get mouse moves outside window
			MouseX = LOWORD(lParam);
			MouseY = HIWORD(lParam);
			ComputeMouseVector();
			MouseState = 1;
			return 0;

		case WM_LBUTTONUP:
			MouseX = LOWORD(lParam);
			MouseY = HIWORD(lParam);
			if(MouseX & 1 << 15) MouseX -= (1 << 16);
			if(MouseY & 1 << 15) MouseY -= (1 << 16);
			ComputeMouseVector();
			MouseState=0;
			ReleaseCapture();
			return 0;

		case WM_MOUSEMOVE:
			MouseX = LOWORD(lParam);
			MouseY = HIWORD(lParam);
			if(MouseX & 1 << 15) MouseX -= (1 << 16); // when negative probably needed because 16bit vs 32
			if(MouseY & 1 << 15) MouseY -= (1 << 16);
			ComputeMouseVector();
			return 0;


		case WM_CLOSE:
			PostQuitMessage(0);
			return 0;
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam); 
	}
	bool WindowUp()
	{
		MSG   msg;		// Windows message		
		while(PeekMessage(&msg, hWnd, 0, 0, PM_NOREMOVE)) {
		    if(GetMessage(&msg, hWnd, 0, 0)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
		    } 
			else 
			{
				return false; 
		    }
		}
		return true;
	}
	bool SwapBuffers() { return  (::SwapBuffers(hDC)!=0); }

	static LRESULT WINAPI MsgProcG( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
	{
		if(msg==WM_NCCREATE)
			SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG)(reinterpret_cast<CREATESTRUCT *>(lParam)->lpCreateParams));  // grab my pointer passed into createwindow
		auto glwin = reinterpret_cast<GLWin *>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		return (glwin)? glwin->MsgProc(hWnd, msg, wParam, lParam ) : DefWindowProc( hWnd, msg, wParam, lParam );
	}
};


