#ifndef UI_STYLE_H
#define UI_STYLE_H

#include <QString>

const QString RESET_BUTTON_STYLE =
		// 操作按钮风格（扁平，圆角，黑白）
		"QPushButton"
		"{"
			"background-color:rgba(242,242,242,200);"	// 背景色（也可以设置图片）
			"border-style:outset;"						// 边框样式（inset/outset）
			"border:1px solid rgba(12,137,222,255);"	// 边框宽度像素和颜色
			"border-radius:19px;"						// 边框圆角半径像素
			"font:bold 15px;"							// 字体，字体大小
			"color:rgba(11,132,217,255);"				// 字体颜色
			"padding:4px;"								// 填衬
		"}"
		//鼠标按下样式
		"QPushButton:pressed"
		"{"
			"background-color:rgba(12,137,222,255);"
			"border-style:inset;"						// 边框样式（inset/outset）
			"border:2px solid rgba(234,234,234,255);"	// 边框宽度像素和颜色
		"}"
		//鼠标悬停样式
		"QPushButton:hover"
		"{"
			"background-color:rgba(12,137,222,255);"
			"border-color:rgba(250,250,250,250);"
			"color:rgba(250,250,250,250);"
		"}";

const QString MODE_BUTTON_STYLE =
		// 操作按钮风格（扁平，圆角，黑白）
		"QPushButton"
		"{"
			"background-color:rgba(12,137,222,255);"	// 背景色（也可以设置图片）
			"border-style:outset;"						// 边框样式（inset/outset）
			"border:1px solid rgba(12,137,222,255);"	// 边框宽度像素和颜色
			"border-radius:19px;"						// 边框圆角半径像素
			"font:bold 15px;"							// 字体，字体大小
			"color:rgba(250,250,250,250);"				// 字体颜色
			"padding:4px;"								// 填衬
		"}"
		//鼠标按下样式
		"QPushButton:pressed"
		"{"
			"background-color:rgba(12,137,222,255);"
			"border-style:inset;"						// 边框样式（inset/outset）
			"border:2px solid rgba(234,234,234,255);"	// 边框宽度像素和颜色
		"}"
		//鼠标悬停样式
		"QPushButton:hover"
		"{"
			"background-color:rgba(12,137,222,230);"
			"border-color:rgba(250,250,250,250);"
			"color:rgba(250,250,250,250);"
		"}";

const QString LCD_STYLE =
		"QLCDNumber"
		"{"
			"background-color:rgba(252,252,252,252);"	// 背景色（也可以设置图片）
			"border:1px solid rgba(12,137,222,255);"	// 边框宽度像素和颜色
			"border-radius:0px;"						// 边框圆角半径像素
			"color:rgba(48,48,48,235);"					// 字体颜色
		"}"
		;


const QString CTRL_BUTTON_STYLE =
		// 操作按钮风格（扁平，圆角，黑白）
		"QPushButton"
		"{"
			"background-color:rgba(244,244,244,200);"	// 背景色（也可以设置图片）
			"border-style:outset;"						// 边框样式（inset/outset）
			"border-width:1px;"							// 边框宽度像素
			"border-radius:19px;"						// 边框圆角半径像素
			"border-color:rgba(68,68,68,220);"			// 边框颜色
			"font:bold 15px;"							// 字体，字体大小
			"color:rgba(58,58,58,230);"					// 字体颜色
			"padding:4px;"								// 填衬
		"}"
		//鼠标按下样式
		"QPushButton:pressed"
		"{"
			"background-color:rgba(42,42,42,255);"
			"border-width:2px;"							// 边框宽度像素
			"border-color:rgba(234,234,234,255);"
			"border-style:inset;"
			"color:rgba(200,200,200,255);"
		"}"
		//鼠标悬停样式
		"QPushButton:hover"
		"{"
			"background-color:rgba(48,48,48,230);"
			"border-color:rgba(250,250,250,250);"
			"color:rgba(250,250,250,250);"
		"}";

const QString TITLE_BUTTON_STYLE[] = {
		// 标题栏按钮风格（扁平，圆角，黑白）
		"QPushButton"
		"{"
			"background-color:rgba(38,38,38,0);"		// 背景色（也可以设置图片）
			"border-style:outset;"						// 边框样式（inset/outset）
			"border-width:2px;"							// 边框宽度像素
			"border-radius:15px;"						// 边框圆角半径像素
			"border-color:rgba(38,38,38,0);"			// 边框颜色
			"font:bold 9px;"							// 字体，字体大小
			"color:rgba(38,38,38,240);"					// 字体颜色
		"}"
		//鼠标按下样式
		"QPushButton:pressed"
		"{"
			"font:bold 7px;"
		"}",

		"QPushButton"
		"{"
			"background-color:rgba(38,38,38,0);"
			"border-style:outset;"
			"border-width:2px;"
			"border-radius:15px;"
			"border-color:rgba(38,38,38,0);"
			"font:bold 19px;"
			"color:rgba(38,38,38,240);"
		"}"
		//鼠标按下样式
		"QPushButton:pressed"
		"{"
			"font:bold 15px;"
		"}"
		//鼠标悬停样式（无）
		};



const QString LABEL_STYLE =
		"QLabel"
		"{"
			"color:rgb(56,56,56,250);"				// 字体颜色
		"}"
		;



const QString LINE_EDITOR_STYLE =
		"QLineEdit"
		"{"
			"background-color: rgba(255,255,255,255);"
			"border-radius: 19px;"
			"border:1px solid rgba(12,137,222,255);"
//			"height: 25px;"
			"font:bold 15px;"							//字体，字体大小
		"}"
		"QLineEdit:enabled"
		"{"
			"color: rgb(12, 137, 222);"
		"}"
		"QLineEdit:enabled:hover"
		"{"
			"color: rgb(158, 158, 158);"
		"}"
		"QLineEdit:enabled:focus"
		"{"
			"color: rgb(118, 118, 118);"
		"}"
//		"QLineEdit:!enabled"
//		"{"
//			"color: rgb(200, 200, 200);"
//		"}"
		;

#endif // UI_STYLE_H
