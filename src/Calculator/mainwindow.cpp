#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(add_digit()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(add_digit()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(add_digit()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(add_digit()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(add_digit()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(add_digit()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(add_digit()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(add_digit()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(add_digit()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(add_digit()));
  connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(add_digit()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(add_sign()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(add_minus()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(add_sign()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(add_sign()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(add_sign()));
  connect(ui->pushButton_eq, SIGNAL(clicked()), this,
          SLOT(on_pushButton_eq_clicked()));
  connect(ui->pushButton_AC, SIGNAL(clicked()), this,
          SLOT(on_pushButton_ac_clicked()));
  connect(ui->pushButton_pi, SIGNAL(clicked()), this, SLOT(add_sign()));
  connect(ui->pushButton_e, SIGNAL(clicked()), this, SLOT(add_func()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(add_func()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(add_func()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(add_func()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(add_func()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(add_func()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(add_func()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(add_func()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(add_func()));
  connect(ui->pushButton_log10, SIGNAL(clicked()), this, SLOT(add_func()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(add_sign()));
  connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this,
          SLOT(add_sign()));
  connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this,
          SLOT(add_sign()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(add_sign()));
  connect(ui->x_show, SIGNAL(clicked()), this, SLOT(enter_x()));
  connect(ui->pushButton_plot, SIGNAL(clicked()), this, SLOT(plot()));

  ui->pushButton_eq->setCheckable(true);
  ui->pushButton_eq->setChecked(false);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::add_sign() {
  QPushButton *button = (QPushButton *)sender();
  if (ui->pushButton_eq->isChecked()) {
    ui->result_show->setText("");
    ui->pushButton_eq->setChecked(false);
  }

  QString input_string = (ui->result_show->text() + button->text());

  ui->result_show->setText(input_string);
}
void MainWindow::add_func() {
  QPushButton *button = (QPushButton *)sender();
  if (ui->pushButton_eq->isChecked()) {
    ui->result_show->setText("");
    ui->pushButton_eq->setChecked(false);
  }

  QString input_string = (ui->result_show->text() + button->text() + '(');

  ui->result_show->setText(input_string);
}
void MainWindow::add_digit() {
  QPushButton *button = (QPushButton *)sender();
  if (ui->x_show->isClicked == 0) {
    if (ui->pushButton_eq->isChecked()) {
      ui->result_show->setText("");
      ui->pushButton_eq->setChecked(false);
    }

    QString input_string = (ui->result_show->text() + button->text());

    ui->result_show->setText(input_string);
  } else {
    if (button->text() >= "0" && button->text() <= "9") {
      QString input_string = (ui->x_show->text() + button->text());
      ui->x_show->setText(input_string);
    } else if (button->text() == "." && !(ui->x_show->text().contains("."))) {
      QString input_string = (ui->x_show->text() + ".");
      ui->x_show->setText(input_string);
    }
  }
}
void MainWindow::add_minus() {
  if (ui->x_show->isClicked == 0) {
    if (ui->pushButton_eq->isChecked()) {
      ui->result_show->setText("");
      ui->pushButton_eq->setChecked(false);
    }

    QString input_string = (ui->result_show->text() + "-");

    ui->result_show->setText(input_string);
  } else {
    double x = ui->x_show->text().toDouble();
    x *= -1;
    QString input_string = QString::number(x);
    ui->x_show->setText(input_string);
  }
}
void MainWindow::on_pushButton_eq_clicked() {
  QString input_string = (ui->result_show->text() + '=' + '\0');
  QString output_string;
  double x = ui->x_show->text().toDouble();

  QByteArray ba = input_string.toLocal8Bit();
  char *to_calc = ba.data();

  int err = 0;
  double res = calculate(to_calc, &err, x);
  if (err == 0) {
    output_string = QString::number(res);
  } else {
    output_string = "Incorrect Input";
  }
  ui->result_show->setText(output_string);
  ui->pushButton_eq->setChecked(true);
}

void MainWindow::on_pushButton_ac_clicked() {
  if (ui->x_show->isClicked == 0) {
    ui->result_show->setText("");
  } else {
    ui->x_show->setText("");
  }
}

void MainWindow::plot() {
  QVector<double> x(100001), y(100001);  // initialize with entries 0..100
  double xmin = ui->doubleSpinBox_xmin->value();
  double xmax = ui->doubleSpinBox_xmax->value();
  double ymin = ui->doubleSpinBox_ymin->value();
  double ymax = ui->doubleSpinBox_ymax->value();

  QString input_string = (ui->result_show->text() + '=');

  QByteArray ba = input_string.toLocal8Bit();
  char *to_calc = ba.data();
  int err = 0;

  for (int i = 0; i < 100001; ++i) {
    x[i] = xmin + i * (xmax - xmin) / 100000;  // x goes from -1 to 1
    y[i] = calculate(to_calc, &err, x[i]);  // let's plot a quadratic function
    if (y[i] > ymax || y[i] < ymin) y[i] = NAN;
  }
  // create graph and assign data to it:
  ui->graphicsView->addGraph();
  ui->graphicsView->graph(0)->setData(x, y);
  // give the axes some labels:
  ui->graphicsView->xAxis->setLabel("x");
  ui->graphicsView->yAxis->setLabel("y");
  // set axes ranges, so we see all data:
  ui->graphicsView->xAxis->setRange(xmin, xmax);
  ui->graphicsView->yAxis->setRange(ymin, ymax);
  ui->graphicsView->replot();
}
