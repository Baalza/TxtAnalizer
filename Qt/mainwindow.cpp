#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QtWidgets>
#include <QDebug>
#include <QRegularExpression>

#include <QMessageBox>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Testo->setReadOnly(true);//Setto il testo in modalità read-only in modo tale che l'utente non possa modificarlo
    ui->Analizza->setEnabled(false);//Disabilito il tasto analizza per evitare che l'utente lo usi se non necessario
}

MainWindow::~MainWindow()
{
    delete ui;//distruggo il puntatore
    delete graphView;//distruggo il puntatore
}


void MainWindow::on_actionOpen_triggered()//evento richiamato quando l'utente preme sul tasto file per aprire le risorse
{
QString fileName = QFileDialog::getOpenFileName(this,"File");
QFile file(fileName);
percorso = fileName;//setto globalmente il filepath
if(!file.open(QFile::ReadOnly | QFile::Text))
    return ;
QTextStream input(&file);
input.setCodec("UTF-8");
QString testo = input.readAll();
ui->Testo->setText(testo);//visualizzo il testo del file scelto dall'utente
file.close();//chiudo l'esplora risorse
delete graphView;//elimino il puntatore del grapho per permettere l'aggiornamente in caso di un cambio del testo da analizzare
graphView = nullptr;//setto il puntatore a null
ui->Analizza->setEnabled(true);//dopo che l'utente ha caricato il file txt rendo disponibile il tasto analizza
//setto la tabella vuota per visualizzare poi i risultati
ui->tabellaRisultati->setItem(0,0,new QTableWidgetItem(""));
ui->tabellaRisultati->setItem(1,0,new QTableWidgetItem(""));
ui->tabellaRisultati->setItem(2,0,new QTableWidgetItem(""));
ui->tabellaRisultati->setItem(3,0,new QTableWidgetItem(""));
ui->tabellaRisultati->setItem(4,0,new QTableWidgetItem(""));

}


void MainWindow::on_Analizza_clicked()//evento richiamato quando l'utente preme sul tasto analizza per scansionare il file .txt
{
//riempio la tabella con i risultatio ottenuti dalla scansione del file .txt
ui->tabellaRisultati->setItem(0,0,new QTableWidgetItem(QString::number(numCaratteri())));//
ui->tabellaRisultati->setItem(1,0,new QTableWidgetItem(QString::number(numCaratteriSenzaSpazi())));
ui->tabellaRisultati->setItem(2,0,new QTableWidgetItem(QString::number(numParole())));
ui->tabellaRisultati->setItem(3,0,new QTableWidgetItem(QString::number(numFrasi())));
ui->tabellaRisultati->setItem(4,0,new QTableWidgetItem(QString::number(numParagrafi())));
int caratteri=numCaratteri();
int caratteriNoSpace=numCaratteriSenzaSpazi();
int parole=numParole();
int frasi=numFrasi();
int paragrafi=numParagrafi();


    QString filename=QFileInfo(percorso).baseName();//imposto il path per salvare il csv
    QFile data("./"+filename+".csv");//creo il file csv
    if(data.open(QFile::WriteOnly |QFile::Truncate)){
        QTextStream output(&data);
        //riempio il file csv con i risultati ottenuti dalla scansione
        output << "Caratteri (inclusa punteggiatura e spazi): \t"<<caratteri<<"\n";
        output << "Caratteri (spazi esclusi): \t"<<caratteriNoSpace<<"\n";
        output << "Parole: \t"<<paragrafi<<"\n";
        output << "Frasi: \t"<<frasi<<"\n";
        output << "Paragrafi: \t"<<paragrafi;
        data.close();
    }
//creazione del grafo che mostra i risultati dell'analisi
if(graphView == nullptr){
    //creo le tab del grapho
    QBarSet *set0 = new QBarSet("Caratteri");
    QBarSet *set1 = new QBarSet("Caratteri senza spazi");
    QBarSet *set2 = new QBarSet("Parole");
    QBarSet *set3 = new QBarSet("Frasi");
    QBarSet *set4 = new QBarSet("Paragrafi");
    //setto le tab del grafo con i valori ottenuti dalal scansione
    *set0 << caratteri;
    *set1 << caratteriNoSpace;
    *set2 << parole;
    *set3 << frasi;
    *set4 << paragrafi;

    int max = caratteri;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Grafico");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,max);   //SITEMARE 0, MAX
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    graphView = new QChartView(chart);
    graphView->setRenderHint(QPainter::Antialiasing);

    ui->horizontalLayout->addWidget(graphView);
    show();

    }
}
//metodo che restituisce il numero di caratteri
int MainWindow::numCaratteri(){
QString stringa = ui->Testo->toPlainText();//prendo il testo
stringa.remove("\t");//rimuovo i tab
return stringa.remove("\n").length();//rimuovo gli a capo e restituisco la lunghezza della stringa

}
//metodo che restituisce il numero di caratteri senza spazi
int MainWindow::numCaratteriSenzaSpazi(){
QString stringa = ui->Testo->toPlainText();
stringa.remove("\n");
stringa.remove("\t");
return stringa.remove(" ").length();//rimuovo gli spazi e restituisco la lunghezza della stringa

}
//metodo che conta il numero di parole
int MainWindow::numParole(){
QString stringa = ui->Testo->toPlainText();
int count = 0;//inizializzo una variabile contatore a 0
//stringa.remove("\n");
stringa.replace("\n"," ");//rimpiazzo gli a capo con degli spazi
//QRegExp rx("[,-.-!-?-;," "]+\r?");
count = stringa.split(QRegExp("(\\s)+"),QString::SkipEmptyParts).count();//splitto la stringa utilizzando una regex sugli spazi e conto i risultati
return count;//ritorno il valore
}
//metodo che restituisce il numero di paragrafi
int MainWindow::numParagrafi(){
QString stringa = ui->Testo->toPlainText();
int count = 0;
stringa.remove("\t");
count = stringa.split(QRegExp("(\n)+"),QString::SkipEmptyParts).count();//splitto la stringa utilizzando una regex sugli a capo e conto i risultati
return count;
}
//metodo che restituisce il numero di frasi
int MainWindow::numFrasi(){
QString stringa = ui->Testo->toPlainText();
stringa.remove("\n");
stringa.remove(" ");
int count = 0;
count = stringa.split(QRegExp("[.|!|?]"),QString::SkipEmptyParts).count();//splitto la stringa utilizzando una regex sui caratteri speciali e conto i risultati
return count;
}






