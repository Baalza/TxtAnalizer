#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_Analizza_clicked();

    int numCaratteri();
    int numCaratteriSenzaSpazi();
    int numParole();
    int numParagrafi();
    int numFrasi();

private:
    Ui::MainWindow *ui;
    QChartView *graphView = nullptr;
    QString percorso;
};
#endif // MAINWINDOW_H
