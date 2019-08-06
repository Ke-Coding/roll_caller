#include "mainwindow.h"

#include <QMessageBox>

void MainWindow::on_mode_button_released()
{
	this->update_mode();
}

void MainWindow::on_reset_button_released()
{
	QString input_str = this->input_box->text();
	QString temp = "";
	for (QChar & c : input_str)
	{
		if (c >= QChar('0') && c <= QChar('9'))
			temp.append(c);
	}
	int input_int = temp.toInt() - 1; // 0-9, class1-class10

	if (input_int > 9)
	{
		QMessageBox::information(this, "  Error  ", "  The class number is out of bounds!    ");
	}
	else
	{
		this->class_index = input_int;
		switch (mode_index)
		{
			case GROUP_MODE_INDEX:
				this->reset_group_mode();
				break;

			case CLASS_MODE_INDEX:
				this->reset_class_mode();
				break;
		}
	}
}
