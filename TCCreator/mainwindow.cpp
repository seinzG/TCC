#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initialize();


    // QObject::connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    QSettings settings("Intel", "Terralogic");
    settings.setValue("Author", ui->author_line->text());
    qDebug() << settings.value("Author");
    qDebug() << "destructor" << endl;
    delete ui;
}

bool MainWindow::initialize() {

    pyW = new Wrapper();
    pyW->createToken();

    QSettings settings("Intel", "Terralogic");
    if (settings.value("Author") != "") {
        // ui->author_line->setText(QString())
        QString author = settings.value("Author").toString();
        ui->author_line->setText(author);
    }

    QStringList sheets = pyW->getSheets();
    ui->testSuite_cb->addItems(sheets);

    QStringList formType = {"New", "Updated", "Delete"};
    ui->type_cb->addItems(formType);

    QDateTime date = QDateTime::currentDateTime();
    ui->dateEdit->setDateTime(date);

    //TODO: Load testcase ID

    QString testcaseID = pyW->createTestID();
    ui->testCaseID_line->setText(testcaseID);

    QStringList validTCs = {"Yes", "No"};
    ui->valid_cb->addItems(validTCs);

    QStringList autoAvailability = {"Not yet", "Can", "Can not", "Done", "Delete"};
    ui->autoAvai_cb->addItems(autoAvailability);

    QObject::connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::close);
    QObject::connect(ui->type_cb, &QComboBox::currentTextChanged, this, &MainWindow::changeType);

    return true;
}

void MainWindow::changeType() {
    qDebug() << "Changed" << endl;
    if (ui->type_cb->currentText() == "New") {
        this->change2New();
        return;
    }
    else
    if ( ui->type_cb->currentText() == "Updated") {
        this->change2Update();
        return;
    }
    this->change2Delete();
    return;
}

void MainWindow::change2New() {
    //TODO:

    //1. Load testsuit
    // QStringList sheets = pyW->getSheets();
    // ui->testSuite_cb->clear();
    // ui->testSuite_cb->addItems(sheets);

    //2. Create test case ID
    QString currTS = ui->testSuite_cb->currentText();

    ui->testCaseID_line->setText(pyW->createTestID());

    //3. Change button
    ui->pushButton->setText("Add");
}

void MainWindow::change2Update() {
    qDebug() << "Update" << endl;
    //TODO:
    //1. Load testsuites
    //2. Load test case ID --> change to combobox
    QStringList testCaseID = pyW->getTestCaseID();
    QComboBox* testCaseID_cb = new QComboBox();
    testCaseID_cb->addItems(testCaseID);
    ui->gridLayout->replaceWidget(ui->testCaseID_line, testCaseID_cb);
    //3. Load test descriptor
    QString testDescription = pyW->getTestDescription();
    ui->testDes_pte->insertPlainText(testDescription);
    //4. Load steps
    QString steps = pyW->getSteps();
    ui->steps_pte->insertPlainText(steps);
    //5. Load expected result
    QString expectedResult = pyW->getExpectedResult();
    ui->eR_pte->insertPlainText(expectedResult);
    //6. Change button
    ui->pushButton->setText("Update");
}

void MainWindow::change2Delete() {
    //TODO:
    //1. Load testsuites
    //2. Load testcaseID --> change to combobox
    //3. Change textboxs to readonly
    //4. Change button
}

