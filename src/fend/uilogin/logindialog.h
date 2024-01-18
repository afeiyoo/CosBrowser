#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginDialog;
}
QT_END_NAMESPACE

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

protected:
    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_btnClose_clicked();

    void on_btnLogin_clicked();

private:
    Ui::LoginDialog *ui;
    /** 记录鼠标的初始位置 */
    QPoint m_start;
};
#endif // LOGINDIALOG_H
