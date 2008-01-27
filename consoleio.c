/*
 gc_consoleio.c - Functions for Console I/O

 Geek Code Generator v1.7.3 - Generates your geek code
 Copyright (C) 1999-2003 Chris Gushue <chris@blackplasma.net>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <stdio.h>

void clear_kb(void)
{
   char junk[80];
   fgets(junk, sizeof(junk), stdin);
}

#ifndef _WIN32

   /* Use standard ANSI codes for clearing screen */
   void clearscreen()
   {
      printf("\033[2J");
   }

#else /* Win32 */

   /* Use Win32 ConsoleIO for clearing screen */
   #include <windows.h>

   void clearscreen()
   {
      COORD coordScreen = { 0, 0 };    /* here's where we'll home the
                                        cursor */
      DWORD cCharsWritten;
      HANDLE hConsole;
      CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */
      DWORD dwConSize;                 /* number of character cells in
                                          the current buffer */


      /* get a handle to StdOut */
      hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

      /* get the number of character cells in the current buffer */
      GetConsoleScreenBufferInfo( hConsole, &csbi );
      dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

      /* fill the entire screen with blanks */
      FillConsoleOutputCharacter( hConsole,
                                  (TCHAR) ' ',
                                  dwConSize,
                                  coordScreen,
                                  &cCharsWritten );

      /* get the current text attribute */
      GetConsoleScreenBufferInfo( hConsole, &csbi );

      /* now set the buffer's attributes accordingly */
      FillConsoleOutputAttribute( hConsole,
                                  csbi.wAttributes,
                                  dwConSize,
                                  coordScreen,
                                  &cCharsWritten );

      /* put the cursor at (0, 0) */
      SetConsoleCursorPosition( hConsole, coordScreen );
 }

#endif /* _WIN32 */
