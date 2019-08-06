#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_style.h"


#include <cstdlib>
#include <ctime>
#include <QDebug>
#include <QFont>
#include <QTimer>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	srand(time(nullptr));

	ui->setupUi(this);
	this->init_pointers();
	this->init_qss();

	this->init_window();
	this->init_title_buttons();

	this->init_input_box();
	this->init_students();
	this->init_modes();

	this->set_connections();

	this->start_roll();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::init_window()
{
	QFont main_font("Microsoft YaHei Light", 10, QFont::DemiBold);
//	main_font.setLetterSpacing(QFont::PercentageSpacing, 103);
	QApplication::setFont(main_font);

	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	this->setWindowTitle(QString("签到点名"));
	this->move(200, 100);
	this->setMouseTracking(true);
}

void MainWindow::init_pointers()
{
	group_roll_lcds[0] = ui->lcd1, group_roll_lcds[1] = ui->lcd2, group_roll_lcds[2] = ui->lcd3, group_roll_lcds[3] = ui->lcd4, group_roll_lcds[4] = ui->lcd5;
	group_roll_buttons[0] = ui->pb1, group_roll_buttons[1] = ui->pb2, group_roll_buttons[2] = ui->pb3, group_roll_buttons[3] = ui->pb4, group_roll_buttons[4] = ui->pb5;
	group_roll_names[0] = ui->name1, group_roll_names[1] = ui->name2, group_roll_names[2] = ui->name3, group_roll_names[3] = ui->name4, group_roll_names[4] = ui->name5;

	class_roll_lcd = ui->class_lcd;
	class_roll_button = ui->class_pb;
	class_roll_names[0] = ui->class_name1, class_roll_names[1] = ui->class_name2, class_roll_names[2] = ui->class_name3, class_roll_names[3] = ui->class_name4, class_roll_names[4] = ui->class_name5;

	stack_widget = ui->stack_widget;
	mode_button = ui->mode_button;
	reset_button = ui->reset_button;
	input_box = ui->input_box;
}

void MainWindow::init_modes()
{
	this->modes[GROUP_MODE_INDEX].mode = GROUP_MODE;
	this->modes[GROUP_MODE_INDEX].name = "Group";

	this->modes[CLASS_MODE_INDEX].mode = CLASS_MODE;
	this->modes[CLASS_MODE_INDEX].name = "Class";

	this->mode_index = MODE_INDEX_CNT - 1;
	this->update_mode();
}

void MainWindow::init_students()
{
	QString file_name;
	for (int class_index=0; class_index<CLASS_COUNT; ++class_index)
	{
		file_name = "students_data\\class";
		file_name.append(QString::number(class_index+1));
		file_name.append(".txt");
		QFile file(file_name);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			qDebug() << "failed to open the file:" << file_name;
			exit(-1);
		}

		QTextStream tin(&file);

		while (!tin.atEnd())
		{
			student_names_in_class[class_index].push_back(tin.readLine());
		}

		int students_count = student_names_in_class[class_index].size();

		int group_size[GROUP_COUNT];
		for (int group_index=0; group_index<GROUP_COUNT; ++group_index)
			group_size[group_index] = students_count / GROUP_COUNT;
		int res = students_count % GROUP_COUNT;
		for (int group_index=GROUP_COUNT-1; group_index>=GROUP_COUNT-res; --group_index)
			++group_size[group_index];

		int pointer = 0;
		for (int group_index=0; group_index<GROUP_COUNT; ++group_index)
		{
			for (int i=0; i<group_size[group_index]; ++i)
			{
				student_names_in_group[class_index][group_index].push_back(student_names_in_class[class_index][pointer]);
				++pointer;
			}
		}

		file.close();
	}
}

void MainWindow::init_title_buttons()
{
	ui->minimize_button->setStyleSheet(TITLE_BUTTON_STYLE[0]);
	ui->close_button->setStyleSheet(TITLE_BUTTON_STYLE[1]);
	ui->minimize_button->setText("▁");
	ui->close_button->setText("×");
}

void MainWindow::start_roll()
{
	roll_timer.setParent(this);
	roll_timer.start(UPDATE_INTERVAL);
}

void MainWindow::init_input_box()
{
	this->input_box->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
	this->input_box->setTextMargins(15, 0, 15, 0);
	this->refresh_input_box();
}

void MainWindow::init_qss()
{
	mode_button->setStyleSheet(MODE_BUTTON_STYLE);
	reset_button->setStyleSheet(RESET_BUTTON_STYLE);

	class_roll_lcd->setStyleSheet(LCD_STYLE);
	class_roll_button->setStyleSheet(CTRL_BUTTON_STYLE);

	for (int i=0; i<GROUP_COUNT; ++i)
	{
		group_roll_lcds[i]->setStyleSheet(LCD_STYLE);
		group_roll_buttons[i]->setStyleSheet(CTRL_BUTTON_STYLE);
		group_roll_names[i]->setStyleSheet(LABEL_STYLE);
	}

	for (int i=0; i<CLASS_ROLL_NAMES_COUNT; ++i)
	{
		class_roll_names[i]->setStyleSheet(LABEL_STYLE);
	}

	input_box->setStyleSheet(LINE_EDITOR_STYLE);

	ui->frame->setStyleSheet("QFrame{border:none}");
	ui->frame_2->setStyleSheet("QFrame{border:none}");
	ui->frame_3->setStyleSheet("QFrame{border:none}");
}

void MainWindow::set_connections()
{
	connect(ui->minimize_button, &QPushButton::clicked, this, &MainWindow::showMinimized);
	connect(ui->close_button, &QPushButton::clicked, this, &MainWindow::close);

	connect(this->group_roll_buttons[0], &QPushButton::released, [&](){group_select(0);});
	connect(this->group_roll_buttons[1], &QPushButton::released, [&](){group_select(1);});
	connect(this->group_roll_buttons[2], &QPushButton::released, [&](){group_select(2);});
	connect(this->group_roll_buttons[3], &QPushButton::released, [&](){group_select(3);});
	connect(this->group_roll_buttons[4], &QPushButton::released, [&](){group_select(4);});

	connect(this->class_roll_button, &QPushButton::released, [&](){class_select();});

	connect(&roll_timer, &QTimer::timeout, this, &MainWindow::roll);
}

void MainWindow::refresh_input_box()
{
	this->input_box->setText("class1");
}
