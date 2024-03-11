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
    delete this->testCaseID_line;
    delete this->testCaseID_cb;
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

    QStringList formType = {"Add New", "Updated", "Deleted"};
    ui->type_cb->addItems(formType);

    QStringList sheets = pyW->getSheets();
    ui->testSuite_cb->addItems(sheets);

    QDateTime date = QDateTime::currentDateTime();
    ui->dateEdit->setDateTime(date);

    //TODO: Load testcase ID

    this->testCaseID_line = new QLineEdit();
    QString newTestCaseID = this->createTestCaseID();
    this->testCaseID_line->setText(newTestCaseID);
    this->testCaseID_cb = new QComboBox();
    ui->stackedWidget->addWidget(testCaseID_line);
    ui->stackedWidget->addWidget(testCaseID_cb);
    ui->stackedWidget->setCurrentWidget(testCaseID_line);

    // QComboBox* testCaseID_cb;
    // ui->gridLayout->addWidget(testCaseID_cb);

    QStringList validTCs = {"Yes", "No"};
    ui->valid_cb->addItems(validTCs);

    QStringList autoAvailability = {"Not yet", "Can", "Can not", "Done", "Delete"};
    ui->autoAvai_cb->addItems(autoAvailability);

    QObject::connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::close);
    QObject::connect(ui->pushButton_2, &QPushButton::pressed, this, &MainWindow::Finished);
    QObject::connect(ui->type_cb, &QComboBox::currentTextChanged, this, &MainWindow::changeType);
    QObject::connect(ui->testSuite_cb, &QComboBox::currentTextChanged, this, &MainWindow::changeTestSuite);
    // ui->type_cb->currentTextChanged("New");
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
    qDebug() << "New" << endl;

    ui->stackedWidget->setCurrentWidget(this->testCaseID_line);

    //2. Create test case ID
    QString currTestSuite = ui->testSuite_cb->currentText();
    QLineEdit* le = static_cast<QLineEdit*>(ui->stackedWidget->currentWidget());
    le->setText(this->createTestCaseID());
    //check if testcaseID already exist ??

    //3. Change button
    ui->func_le->setReadOnly(false);
    ui->testDes_le->setReadOnly(false);
    ui->steps_le->setReadOnly(false);
    ui->er_le->setReadOnly(false);
    ui->ri_le->setReadOnly(false);
    ui->note_le->setReadOnly(false);
    ui->valid_cb->setDisabled(false);
    ui->autoAvai_cb->setDisabled(false);
    ui->pushButton_2->setText("Add");
}

void MainWindow::change2Update() {
    qDebug() << "Update" << endl;
    // //TODO:
    // //1. Load testsuites
    //2. Load test case ID --> change to combobox
    // QStringList testCaseID = pyW->getTestCaseID();
    // QComboBox* testCaseID_cb = new QComboBox();
    // testCaseID_cb->addItems(testCaseID);
    // ui->gridLayout->replaceWidget(ui->testCaseID_line, testCaseID_cb);
    // //3. Load test descriptor
    // QString testDescription = pyW->getTestDescription();
    // ui->testDes_pte->insertPlainText(testDescription);
    // //4. Load steps
    // QString steps = pyW->getSteps();
    // ui->steps_pte->insertPlainText(steps);
    // //5. Load expected result
    // QString expectedResult = pyW->getExpectedResult();
    // ui->eR_pte->insertPlainText(expectedResult);
    // //6. Change button
    this->updateOrDelete();
    ui->func_le->setReadOnly(false);
    ui->testDes_le->setReadOnly(false);
    ui->steps_le->setReadOnly(false);
    ui->er_le->setReadOnly(false);
    ui->ri_le->setReadOnly(false);
    ui->note_le->setReadOnly(false);
    ui->valid_cb->setDisabled(false);
    ui->autoAvai_cb->setDisabled(false);
    ui->pushButton_2->setText("Update");
}

void MainWindow::change2Delete() {
    qDebug() << "Delete" << endl;
    //TODO:
    //1. Load testsuites
    //2. Load testcaseID --> change to combobox
    //3. Change textboxs to readonly
    //4. Change button
    this->updateOrDelete();
    ui->func_le->setReadOnly(true);
    ui->testDes_le->setReadOnly(true);
    ui->steps_le->setReadOnly(true);
    ui->er_le->setReadOnly(true);
    ui->ri_le->setReadOnly(true);
    ui->note_le->setReadOnly(true);
    ui->valid_cb->setDisabled(true);
    ui->autoAvai_cb->setDisabled(true);
    ui->pushButton_2->setText("Delete");
}

void MainWindow::updateOrDelete() {
    qDebug() << "update or delete" <<endl;
    ui->stackedWidget->setCurrentWidget(this->testCaseID_cb);
    QObject::connect(ui->testSuite_cb, &QComboBox::currentTextChanged, this, &MainWindow::changeTestSuite);
    QObject::connect(this->testCaseID_cb, &QComboBox::currentTextChanged, this, &MainWindow::changeTestCaseID);
    QComboBox* cb = static_cast<QComboBox*>(ui->stackedWidget->currentWidget());
    cb->clear();
    QStringList testCaseIDs = pyW->getTestCaseIDs(ui->testSuite_cb->currentText());
    cb->addItems(testCaseIDs);
}

void MainWindow::changeTestSuite() {
    qDebug() << "changeTestSuite" << endl;
    if (ui->type_cb->currentText() == "New") {
        static_cast<QLineEdit*>(ui->stackedWidget->currentWidget())->setText(this->createTestCaseID());
    }
    else {
        //Update or Delete
        QComboBox* cb = static_cast<QComboBox*>(ui->stackedWidget->currentWidget());
        cb->clear();
        QStringList testCaseIDs = pyW->getTestCaseIDs(ui->testSuite_cb->currentText());
        qDebug() << testCaseIDs << endl;
        cb->addItems(testCaseIDs);
    }
}

void MainWindow::changeTestCaseID() {
    qDebug() << "changeTestCaseID" << endl;
    QString testSuite = ui->testSuite_cb->currentText();
    QString testCaseID = static_cast<QComboBox*>(ui->stackedWidget->currentWidget())->currentText();
    if (testCaseID == "") {
        return;
    }
    //TODO load all other widgets content
    qDebug() << testSuite << " " << testCaseID << endl;
    QString data = pyW->getData(testSuite, testCaseID);
    qDebug() << data << endl;
    QStringList dataList = data.mid(2, data.length()-2).split("', '");
    qDebug() << dataList << endl;
    ui->func_le->setText(dataList[1]);
    // qDebug() << ui->testDes_le->acceptRichText();

    ui->testDes_le->setAcceptRichText(true);
    ui->testDes_le->setText("");
    for (auto line : dataList[2].split("\\n")) {
        ui->testDes_le->append(line);
    }
    // ui->testDes_le->setText(dataList[2].replace("\n", "<\br>"));
    ui->steps_le->setText("");
    ui->steps_le->setAcceptRichText(true);
    for (auto line : dataList[3].split("\\n")) {
        ui->steps_le->append(line);
    }
    // ui->steps_le->setText(dataList[3].replace("\n", "<\br>"));
    ui->er_le->setText("");
    ui->er_le->setAcceptRichText(true);
    for (auto line : dataList[4].split("\\n")) {
        ui->er_le->append(line);
    }
    // ui->er_le->setText(dataList[4].replace("\n", "<\br>"));
    ui->valid_cb->setCurrentText(dataList[5]);
    ui->autoAvai_cb->setCurrentText(dataList[6]);
    ui->ri_le->setText("");
    if (dataList.length() >=8)
        ui->ri_le->setText(dataList[7].replace("\n", "<\br>"));
    ui->note_le->setText("");
    if (dataList.length() ==9) {
        for (auto line : dataList[8].split("\\n")) {
            ui->note_le->append(line);
        }
    }
}

QString MainWindow::createTestCaseID() {
    QString latestID = pyW->getTestCaseIDs(ui->testSuite_cb->currentText()).last();
    QStringList a = latestID.split("_");
    qDebug() << a[0] << " " << a[1] << endl;
    return a[0] + "_" + QString::number(a[1].toInt() + 1);
}

void MainWindow::Finished() {
    // if (ui->pushButton->text() == "Add") {
    qDebug() << "Finish" << endl;
    {
        QString Author = ui->author_line->text();
        QString Type = ui->type_cb->currentText();
        QString Date = ui->dateEdit->text();
        QString TestSuite = ui->testSuite_cb->currentText();
        QString TestCaseID;
        QString Functionality = ui->func_le->text();
        QString TestDescription = ui->testDes_le->toPlainText();
        QString Steps = ui->steps_le->toPlainText();
        QString ER = ui->er_le->toPlainText();
        QString RI = ui->ri_le->text();
        QString Note = ui->note_le->toPlainText();
        QString ValidTCs = ui->valid_cb->currentText();
        QString Automation = ui->autoAvai_cb->currentText();

        QString result;

        if (ui->pushButton_2->text() == "Add") {
            TestCaseID = static_cast<QLineEdit*>(ui->stackedWidget->currentWidget())->text();
            QString add_args =
                                "\"4"+TestSuite+"\" "+
                                "\"5"+TestCaseID+"\" "+
                                "\"6"+Functionality+"\" "+
                                "\"7"+TestDescription+"\" "+
                                "\"8"+Steps+"\" "+
                                "\"9"+ER+"\" "+
                                "\"A"+ValidTCs+"\" "+
                                "\"B" +Automation+"\" "+
                                /*"1"+Author+" "+\*/
                                /*"2:"+Type+" "+\*/
                                /*"3"+Date+" "+\*/
                                "\"C"+RI+"\" "+
                                "\"D"+Note+"\"";

            qDebug() << add_args << endl;
            result = pyW->Add(add_args);
            // QMessageBox msgBox;
            // msgBox.setText("HEYYYYYYYY");
            // msgBox.exec();
        }
        if (ui->pushButton_2->text() == "Update") {
            TestCaseID = static_cast<QComboBox*>(ui->stackedWidget->currentWidget())->currentText();
            qDebug() << 1 << endl;
            QString update_args =
                                "\"4"+TestSuite+"\" "+
                                "\"5"+TestCaseID+"\" "+
                                "\"6"+Functionality+"\" "+
                                "\"7"+TestDescription+"\" "+
                                "\"8"+Steps+"\" "+
                                "\"9"+ER+"\" "+
                                "\"A"+ValidTCs+"\" "+
                                "\"B" +Automation+"\" "+
                                /*"1"+Author+" "+\*/
                                /*"2:"+Type+" "+\*/
                                /*"3"+Date+" "+\*/
                                "\"C"+RI+"\" "+
                                "\"D"+Note+"\"";
            qDebug() << update_args << endl;
            result = pyW->Update(update_args);
        }

        if (ui->pushButton_2->text() == "Delete") {
            TestCaseID = static_cast<QComboBox*>(ui->stackedWidget->currentWidget())->currentText();
            QString delete_args =
                                "\"4"+TestSuite+"\" "+
                                "\"5"+TestCaseID+"\" "+
                                "\"6"+Functionality+"\" "+
                                "\"7"+TestDescription+"\" "+
                                "\"8"+Steps+"\" "+
                                "\"9"+ER+"\" "+
                                "\"A"+ValidTCs+"\" "+
                                "\"B" +Automation+"\" "+
                                /*"1"+Author+" "+\*/
                                /*"2:"+Type+" "+\*/
                                /*"3"+Date+" "+\*/
                                "\"C"+RI+"\" "+
                                "\"D"+Note+"\"";
            qDebug() << delete_args << endl;
            result = pyW->Delete(delete_args);
        }
        qDebug() << result << endl;
        if (result.trimmed() == "Success") {
            qDebug() << "?????" << endl;
            QString hist_args =
                "\"1"+TestSuite+"\" "+
                "\"2"+Functionality+"\" "+
                "\"3"+RI+"\" "+
                "\"4"+TestCaseID+"\" "+
                "\"5"+Type+"\" "+
                "\"6"+Date+"\" "+
                "\"7"+Author;
            result = pyW->updateHistory(hist_args);
        }
        QMessageBox msgBox;
        msgBox.setText(result.trimmed());
        msgBox.exec();
        // result &= pyW->updateHistory(hist_args);
    }
}
