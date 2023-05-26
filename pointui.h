#ifndef POINTUI_H
#define POINTUI_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class PointUI; }
QT_END_NAMESPACE

class PointUI : public QWidget
{
    Q_OBJECT

public:
    PointUI(QWidget *parent = nullptr);
    ~PointUI();

private slots:
    void on_browse_button_clicked();

    void on_load_button_clicked();

    void on_run_button_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::PointUI *ui;
    std::string config_path;
    std::string cmd;
};
#endif // POINTUI_H
