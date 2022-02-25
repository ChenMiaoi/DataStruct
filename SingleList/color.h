#ifndef __COLOR__H__
#define __COLOR__H__

/** Reset all the Attributes */
extern const char* RESET;	//重置所有设置

/** Set Font Color
 * Format: "\033[BackColor;FrontColormString\033[0m"
*/
extern const char* FRONT_BLACK;			//字体 -- 黑
extern const char* FRONT_RED;			//字体 -- 红
extern const char* FRONT_GREEN;			//字体 -- 绿
extern const char* FRONT_YELLOW;		//字体 -- 黄
extern const char* FRONT_BLUE;			//字体 -- 蓝
extern const char* FRONT_PURPLR;		//字体 -- 紫
extern const char* FRONT_DARKGREEN;		//字体 -- 青
extern const char* FRONT_WHITE;			//字体 -- 白

extern const char* BACK_BLACK;			//背景 -- 黑
extern const char* BACK_RED;			//背景 -- 红
extern const char* BACK_GREEN;			//背景 -- 绿
extern const char* BACK_YELLOW;			//背景 -- 黄
extern const char* BACK_BLUE;			//背景 -- 蓝 
extern const char* BACK_PURPLR;			//背景 -- 紫
extern const char* BACK_DARKGREEN;		//背景 -- 青
extern const char* BACK_WHITE;			//背景 -- 白

/** Set Font Effect */
extern const char* BOLD;				//字体 -- 粗
extern const char* UNDERLINE;			//字体 -- 下划线
extern const char* TWINKLING;			//字体 -- 闪烁
extern const char* REVERSE;				//字体 -- 旋转
extern const char* HIDE;				//字体 -- 隐藏
#endif // !__COLOR__H__

