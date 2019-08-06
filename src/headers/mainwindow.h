#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QLineEdit>
#include <QVector>


#include "config.h"
#include "ui_param.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:

		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private:

		struct Mode
		{
			ModeEnum mode;
			QString name;
			vint students_count;
		};

		Mode modes[MODE_CNT];
		xint mode_index;

		Ui::MainWindow *ui;

		QStackedWidget *stack_widget;

		QLCDNumber *group_roll_lcds[GROUP_COUNT];
		QLCDNumber *class_roll_lcd;
		QLabel *group_roll_names[GROUP_COUNT];
		QLabel *class_roll_names[CLASS_ROLL_NAMES_COUNT];
		QPushButton *group_roll_buttons[GROUP_COUNT];
		QPushButton *class_roll_button;

		QPushButton *mode_button;
		QPushButton *reset_button;
		QLineEdit *input_box;

		QTimer roll_timer;

		bool group_roll_available[GROUP_COUNT];
		bool class_roll_available;
		xint class_roll_index;

		vint class_roll_chosen[CLASS_ROLL_NAMES_COUNT];

		xint class_index;
		QVector<QString> student_names_in_group[CLASS_COUNT][GROUP_COUNT];
		QVector<QString> student_names_in_class[CLASS_COUNT];

		void init_window(void);
		void init_pointers(void);
		void init_modes(void);
		void init_students(void);
		void init_title_buttons(void);
		void start_roll(void);
		void init_input_box(void);
		void init_qss(void);
		void set_connections(void);

		void refresh_input_box(void);

		void roll(void);
		void group_select(const xint group_index);
		void class_select(void);
		void update_mode(void);
		void reset_group_mode(void);
		void reset_class_mode(void);

	protected:

		virtual void mousePressEvent(QMouseEvent *event);	// 窗口移动
		virtual void paintEvent(QPaintEvent *event);

	private slots:

		void on_mode_button_released();
		void on_reset_button_released();
};

#endif // MAINWINDOW_H
