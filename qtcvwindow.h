#ifndef QTCVWINDOW_H
#define QTCVWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QtCvWindow; }
QT_END_NAMESPACE

class QtCvWindow : public QMainWindow
{
    Q_OBJECT

public:
    QtCvWindow(QWidget *parent = nullptr);
    ~QtCvWindow();

private slots:
    void on_pbSelectFile_clicked();

    void on_pbShowImg_clicked();

private:
    Ui::QtCvWindow *ui;
};
#endif // QTCVWINDOW_H
