#include "pointui.h"
#include "ui_pointui.h"
#include <QFileDialog>
#include <QProcess>
#include <string>
#include <yaml-cpp/yaml.h>

PointUI::PointUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PointUI)
{
    ui->setupUi(this);
    this->cmd = "source /opt/ros/humble/setup.bash && cd /home/point/ros2_ws && colcon build --packages-select pc_det && source install/setup.bash && ros2 launch pc_det nuscenes_demo_launch.py";
}

PointUI::~PointUI()
{
    delete ui;
}


void PointUI::on_browse_button_clicked()
{
    // open file browser
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/point/ros2_ws/src/pc_det/config", tr("All Files (*);;Text Files (*.txt)"));
    ui->sys_config_path->setText(filename);
}


void PointUI::on_load_button_clicked()
{
    QString filename = ui->sys_config_path->text();
    if(filename.isEmpty())
    {
        return;
    }
    std::string str_filemame = filename.toStdString();
    this->config_path = str_filemame;
    YAML::Node config = YAML::LoadFile(str_filemame);
    const std::string mmdet3d_path = config["infer_node"]["ros__parameters"]["mmdet3d_path"].as<std::string>();
    const std::string model_config_file = config["infer_node"]["ros__parameters"]["config_file"].as<std::string>();
    const std::string model_checkpoint_file = config["infer_node"]["ros__parameters"]["checkpoint_file"].as<std::string>();
    const std::string onnx_model = config["infer_node"]["ros__parameters"]["onnx_model"].as<std::string>();
    ui->mmdet3d_path->setText(QString::fromStdString(mmdet3d_path));
    ui->model_config_path->setText(QString::fromStdString(model_config_file));
    ui->ckpt_path->setText(QString::fromStdString(model_checkpoint_file));
    ui->onnx_model_path->setText(QString::fromStdString(onnx_model));
}


void PointUI::on_run_button_clicked()
{
    QProcess process;
    qDebug() << this->cmd;
    process.start("bash", QStringList() << "-c" << this->cmd.c_str());
    process.waitForFinished(-1);
}


void PointUI::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    std::string str_text = arg1.toStdString();
    if(str_text == "Nuscenes(v1.0 mini)")
    {
        this->cmd = "source /opt/ros/humble/setup.bash && cd /home/point/ros2_ws && colcon build --packages-select pc_det && source install/setup.bash && ros2 launch pc_det nuscenes_demo_launch.py";
    }
    else if(str_text == "depth camera")
    {
        this->cmd = "source /opt/ros/humble/setup.bash && cd /home/point/ros2_ws && colcon build --packages-select pc_det && source install/setup.bash && ros2 launch pc_det depthcam_demo_launch.py";
    }
    else
    {
        this->cmd = "[WARNING]: echo \"not complete\"";
    }
}

