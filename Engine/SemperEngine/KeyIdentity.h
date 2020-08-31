#ifndef KEYIDENTITY

#include "EngineDef.h"

#ifdef GLFW

#include <GLFW/glfw3.h>

#endif

namespace SemperEngine {


#ifdef GLFW
	/* The unknown key */
#define KEY_UNKNOWN                 GLFW_KEY_UNKNOWN

/* Printable keys */
#define KEY_SPACE                   GLFW_KEY_SPACE
#define KEY_APOSTROPHE				GLFW_KEY_APOSTROPHE /* ' */
#define KEY_COMMA					GLFW_KEY_COMMA /* , */
#define KEY_MINUS					GLFW_KEY_MINUS/* - */
#define KEY_PERIOD					GLFW_KEY_PERIOD/* . */
#define KEY_SLASH					GLFW_KEY_SLASH /* / */
#define KEY_0						GLFW_KEY_0 
#define KEY_1						GLFW_KEY_1 
#define KEY_2						GLFW_KEY_2 
#define KEY_3						GLFW_KEY_3
#define KEY_4						GLFW_KEY_4 
#define KEY_5						GLFW_KEY_5 
#define KEY_6						GLFW_KEY_6 
#define KEY_7						GLFW_KEY_7 
#define KEY_8						GLFW_KEY_8 
#define KEY_9						GLFW_KEY_9
#define KEY_SEMICOLON				GLFW_KEY_SEMICOLON  /* ; */
#define KEY_EQUAL					GLFW_KEY_EQUAL/* = */
#define KEY_A						GLFW_KEY_A
#define KEY_B						GLFW_KEY_B
#define KEY_C						GLFW_KEY_C
#define KEY_D						GLFW_KEY_D
#define KEY_E						GLFW_KEY_E
#define KEY_F						GLFW_KEY_F 
#define KEY_G						GLFW_KEY_G 
#define KEY_H						GLFW_KEY_H
#define KEY_I						GLFW_KEY_I
#define KEY_J						GLFW_KEY_J
#define KEY_K						GLFW_KEY_K
#define KEY_L						GLFW_KEY_L
#define KEY_M						GLFW_KEY_M
#define KEY_N						GLFW_KEY_N
#define KEY_O						GLFW_KEY_O
#define KEY_P						GLFW_KEY_P
#define KEY_Q						GLFW_KEY_Q
#define KEY_R						GLFW_KEY_R
#define KEY_S						GLFW_KEY_S 
#define KEY_T						GLFW_KEY_T
#define KEY_U						GLFW_KEY_U 
#define KEY_V						GLFW_KEY_V
#define KEY_W						GLFW_KEY_W 
#define KEY_X						GLFW_KEY_X 
#define KEY_Y						GLFW_KEY_Y  
#define KEY_Z						GLFW_KEY_Z
#define KEY_LEFT_BRACKET			GLFW_KEY_LEFT_BRACKET/* [ */
#define KEY_BACKSLASH				GLFW_KEY_BACKSLASH /* \ */
#define KEY_RIGHT_BRACKET			GLFW_KEY_RIGHT_BRACKET /* ] */
#define KEY_GRAVE_ACCENT			GLFW_KEY_GRAVE_ACCENT  /* ` */
#define KEY_WORLD_1					GLFW_KEY_WORLD_1     /* non-US #1 */
#define KEY_WORLD_2					GLFW_KEY_WORLD_2   /* non-US #2 */

/* Function keys */
#define KEY_ESCAPE					GLFW_KEY_ESCAPE         
#define KEY_ENTER					GLFW_KEY_ENTER          
#define KEY_TAB						GLFW_KEY_TAB             
#define KEY_BACKSPACE				GLFW_KEY_BACKSPACE       
#define KEY_INSERT					GLFW_KEY_INSERT          
#define KEY_DELETE					GLFW_KEY_DELETE          
#define KEY_RIGHT					GLFW_KEY_RIGHT           
#define KEY_LEFT					GLFW_KEY_LEFT             
#define KEY_DOWN					GLFW_KEY_DOWN          
#define KEY_UP						GLFW_KEY_UP               
#define KEY_PAGE_UP					GLFW_KEY_PAGE_UP          
#define KEY_PAGE_DOWN				GLFW_KEY_PAGE_DOWN          
#define KEY_HOME					GLFW_KEY_HOME             
#define KEY_END						GLFW_KEY_END              
#define KEY_CAPS_LOCK				GLFW_KEY_CAPS_LOCK        
#define KEY_SCROLL_LOCK				GLFW_KEY_SCROLL_LOCK      
#define KEY_NUM_LOCK				GLFW_KEY_NUM_LOCK          
#define KEY_PRINT_SCREEN			GLFW_KEY_PRINT_SCREEN      
#define KEY_PAUSE					GLFW_KEY_PAUSE            
#define KEY_F1						GLFW_KEY_F1             
#define KEY_F2						GLFW_KEY_F2
#define KEY_F3						GLFW_KEY_F3 
#define KEY_F4						GLFW_KEY_F4
#define KEY_F5						GLFW_KEY_F5
#define KEY_F6						GLFW_KEY_F6 
#define KEY_F7						GLFW_KEY_F7 
#define KEY_F8						GLFW_KEY_F8
#define KEY_F9						GLFW_KEY_F9
#define KEY_F10						GLFW_KEY_F10
#define KEY_F11						GLFW_KEY_F11            
#define KEY_F12						GLFW_KEY_F12
#define KEY_F13						GLFW_KEY_F13
#define KEY_F14						GLFW_KEY_F14    
#define KEY_F15						GLFW_KEY_F15  
#define KEY_F16						GLFW_KEY_F16
#define KEY_F17						GLFW_KEY_F17  
#define KEY_F18						GLFW_KEY_F18
#define KEY_F19						GLFW_KEY_F19
#define KEY_F20						GLFW_KEY_F20 
#define KEY_F21						GLFW_KEY_F21
#define KEY_F22						GLFW_KEY_F22  
#define KEY_F23						GLFW_KEY_F23   
#define KEY_F24						GLFW_KEY_F24  
#define KEY_F25						GLFW_KEY_F25        
#define KEY_KP_0					GLFW_KEY_KP_0  
#define KEY_KP_1					GLFW_KEY_KP_1  
#define KEY_KP_2					GLFW_KEY_KP_2 
#define KEY_KP_3					GLFW_KEY_KP_3 
#define KEY_KP_4					GLFW_KEY_KP_4
#define KEY_KP_5					GLFW_KEY_KP_5 
#define KEY_KP_6					GLFW_KEY_KP_6
#define KEY_KP_7					GLFW_KEY_KP_7 
#define KEY_KP_8					GLFW_KEY_KP_8 
#define KEY_KP_9					GLFW_KEY_KP_9
#define KEY_KP_DECIMAL				GLFW_KEY_KP_DECIMAL 
#define KEY_KP_DIVIDE				GLFW_KEY_KP_DIVIDE 
#define KEY_KP_MULTIPLY				GLFW_KEY_KP_MULTIPLY 
#define KEY_KP_SUBTRACT				GLFW_KEY_KP_SUBTRACT 
#define KEY_KP_ADD					GLFW_KEY_KP_ADD
#define KEY_KP_ENTER				GLFW_KEY_KP_ENTER
#define KEY_KP_EQUAL				GLFW_KEY_KP_EQUAL
#define KEY_LEFT_SHIFT				GLFW_KEY_LEFT_SHIFT
#define KEY_LEFT_CONTROL			GLFW_KEY_LEFT_CONTROL
#define KEY_LEFT_ALT				GLFW_KEY_LEFT_ALT
#define KEY_LEFT_SUPER				GLFW_KEY_LEFT_SUPER
#define KEY_RIGHT_SHIFT				GLFW_KEY_RIGHT_SHIFT
#define KEY_RIGHT_CONTROL			GLFW_KEY_RIGHT_CONTROL
#define KEY_RIGHT_ALT				GLFW_KEY_RIGHT_ALT
#define KEY_RIGHT_SUPER				GLFW_KEY_RIGHT_SUPER
#define KEY_MENU					GLFW_KEY_MENU


#define PRESS						GLFW_PRESS
#define RELEASE						GLFW_RELEASE
#define REPEAT						GLFW_REPEAT


#define MOUSE_BUTTON_1         GLFW_MOUSE_BUTTON_1
#define MOUSE_BUTTON_2         GLFW_MOUSE_BUTTON_2
#define MOUSE_BUTTON_3         GLFW_MOUSE_BUTTON_3
#define MOUSE_BUTTON_4         GLFW_MOUSE_BUTTON_4
#define MOUSE_BUTTON_5         GLFW_MOUSE_BUTTON_5
#define MOUSE_BUTTON_6         GLFW_MOUSE_BUTTON_6
#define MOUSE_BUTTON_7         GLFW_MOUSE_BUTTON_7
#define MOUSE_BUTTON_8         GLFW_MOUSE_BUTTON_8
#define MOUSE_BUTTON_LAST      GLFW_MOUSE_BUTTON_8
#define MOUSE_BUTTON_LEFT      GLFW_MOUSE_BUTTON_1
#define MOUSE_BUTTON_RIGHT     GLFW_MOUSE_BUTTON_2
#define MOUSE_BUTTON_MIDDLE    GLFW_MOUSE_BUTTON_3

#endif // GLFW

#ifdef WIN32_WIN

#include <Windows.h>

#define KEY_UNKNOWN                 0

/* Printable keys */
#define KEY_SPACE                   0
#define KEY_APOSTROPHE				1 /* ' */
#define KEY_COMMA					2 /* , */
#define KEY_MINUS					3/* - */
#define KEY_PERIOD					4/* . */
#define KEY_SLASH					5 /* / */
#define KEY_0						6 
#define KEY_1						7 
#define KEY_2						8 
#define KEY_3						9
#define KEY_4						10 
#define KEY_5						11 
#define KEY_6						12
#define KEY_7						13
#define KEY_8						14
#define KEY_9						15
#define KEY_SEMICOLON				16 /* ; */
#define KEY_EQUAL					17/* = */
#define KEY_A						18
#define KEY_B						19
#define KEY_C						20
#define KEY_D						21
#define KEY_E						22
#define KEY_F						23 
#define KEY_G						24 
#define KEY_H						25
#define KEY_I						26
#define KEY_J						27
#define KEY_K						28
#define KEY_L						29
#define KEY_M						30
#define KEY_N						31
#define KEY_O						32
#define KEY_P						33
#define KEY_Q						34
#define KEY_R						35
#define KEY_S						36 
#define KEY_T						37
#define KEY_U						38 
#define KEY_V						39
#define KEY_W						40 
#define KEY_X						41 
#define KEY_Y						42  
#define KEY_Z						43
#define KEY_LEFT_BRACKET			44/* [ */
#define KEY_BACKSLASH				45 /* \ */
#define KEY_RIGHT_BRACKET			46 /* ] */
#define KEY_GRAVE_ACCENT			47  /* ` */
#define KEY_WORLD_1					48     /* non-US #1 */
#define KEY_WORLD_2					49   /* non-US #2 */

/* Function keys */
#define KEY_ESCAPE					50         
#define KEY_ENTER					51          
#define KEY_TAB						52             
#define KEY_BACKSPACE				53       
#define KEY_INSERT					54          
#define KEY_DELETE					55          
#define KEY_RIGHT					56           
#define KEY_LEFT					57             
#define KEY_DOWN					58          
#define KEY_UP						59               
#define KEY_PAGE_UP					60          
#define KEY_PAGE_DOWN				61          
#define KEY_HOME					62             
#define KEY_END						63              
#define KEY_CAPS_LOCK				64        
#define KEY_SCROLL_LOCK				65      
#define KEY_NUM_LOCK				66          
#define KEY_PRINT_SCREEN			67      
#define KEY_PAUSE					68            
#define KEY_F1						69             
#define KEY_F2						70
#define KEY_F3						71 
#define KEY_F4						72
#define KEY_F5						73
#define KEY_F6						74 
#define KEY_F7						75 
#define KEY_F8						76
#define KEY_F9						77
#define KEY_F10						78
#define KEY_F11						79            
#define KEY_F12						80
#define KEY_F13						81
#define KEY_F14						82    
#define KEY_F15						83  
#define KEY_F16						84
#define KEY_F17						85  
#define KEY_F18						86
#define KEY_F19						87
#define KEY_F20						88 
#define KEY_F21						89
#define KEY_F22						90  
#define KEY_F23						91   
#define KEY_F24						92  
#define KEY_F25						93        
#define KEY_KP_0					94  
#define KEY_KP_1					95  
#define KEY_KP_2					96 
#define KEY_KP_3					97 
#define KEY_KP_4					98
#define KEY_KP_5					99 
#define KEY_KP_6					100
#define KEY_KP_7					101 
#define KEY_KP_8					102 
#define KEY_KP_9					103
#define KEY_KP_DECIMAL				104 
#define KEY_KP_DIVIDE				105 
#define KEY_KP_MULTIPLY				106 
#define KEY_KP_SUBTRACT				107 
#define KEY_KP_ADD					108
#define KEY_KP_ENTER				109
#define KEY_KP_EQUAL				110
#define KEY_LEFT_SHIFT				111
#define KEY_LEFT_CONTROL			112
#define KEY_LEFT_ALT				113
#define KEY_LEFT_SUPER				114
#define KEY_RIGHT_SHIFT				115
#define KEY_RIGHT_CONTROL			116
#define KEY_RIGHT_ALT				117
#define KEY_RIGHT_SUPER				118
#define KEY_MENU					119


#define PRESS						1
#define RELEASE						2
#define REPEAT						3


#define MOUSE_BUTTON_1         1
#define MOUSE_BUTTON_2         2
#define MOUSE_BUTTON_3         3
#define MOUSE_BUTTON_4         4
#define MOUSE_BUTTON_5         5
#define MOUSE_BUTTON_6         6
#define MOUSE_BUTTON_7         7
#define MOUSE_BUTTON_8         8
#define MOUSE_BUTTON_LAST      8
#define MOUSE_BUTTON_LEFT      1
#define MOUSE_BUTTON_RIGHT     2
#define MOUSE_BUTTON_MIDDLE    3

#endif

}


#endif // !KEYIDENTITY
