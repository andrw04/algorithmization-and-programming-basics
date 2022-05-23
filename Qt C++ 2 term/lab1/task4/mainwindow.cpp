#include "mainwindow.h"
#include "ui_mainwindow.h"

int readersCount = 1;
int librarySize = 1;
int prBookCount = 1;
bool prGenerated = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readersArr = new Reader[readersCount];
    books = new Library[librarySize];
    prBooks = new PromiseBook[prBookCount];
}

MainWindow::~MainWindow()
{
    delete ui;
}

Library* addBook(Library* obj,int bCode, QString aut, QString bName,int y,QString lang)
{
    if(librarySize == 1)
    {
        obj[0].setData(bCode,aut,bName,y,lang);
    }
    else
    {
        Library *tmp_obj = new Library[librarySize];
        for(int i = 0; i < librarySize - 1;i++)
        {
            tmp_obj[i] = obj[i];
        }
        delete[] obj;
        obj = tmp_obj;
        obj[librarySize - 1].setData(bCode,aut,bName,y,lang);
    }
    librarySize++;
    return obj;
}
Reader* addReader(Reader *obj,QString n,int readerCode,QString home,QString phone)
{
    if(readersCount == 1)
    {
        obj[0].setData(n,readerCode,home,phone);
    }
    else
    {
        Reader *tmp_obj = new Reader[readersCount];
        for(int i = 0; i < readersCount - 1;i++)
        {
            tmp_obj[i] = obj[i];
        }
        delete[] obj;
        obj = tmp_obj;
        obj[readersCount-1].setData(n,readerCode,home,phone);
    }
    readersCount++;
    return obj;
}


void MainWindow::on_openReader_clicked()
{
    QFile file(QFileDialog::getOpenFileName(this,"Выбрать файл", "C:\\","TXT File (*.txt)"));
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString name = in.readLine();
        if(name.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0;i < name.size();i++)
        {
            if(!name[i].isLetter()){
                QMessageBox::warning(this,"Ошибка","Ошибка");
                return;
            }
        }
        QString readerCode = in.readLine();
        if(readerCode.size() > 5)
        {
            QMessageBox::warning(this,"Ошибка","Ошибка");
            return;
        }
        if(readerCode.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0;i < readerCode.size();i++)
        {
            if(!readerCode[i].isDigit())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        QString homeAddress = in.readLine();
        if(homeAddress.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0;i < homeAddress.size();i++)
        {
            if(!homeAddress[i].isLetter())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        QString phoneNumber = in.readLine();
        if(phoneNumber.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0;i < phoneNumber.size();i++)
        {
            if(!phoneNumber[i].isDigit())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        readersArr = addReader(readersArr,name,readerCode.toInt(),homeAddress,phoneNumber);
    }
    file.close();
}


void MainWindow::on_openBook_clicked()
{
    QFile file(QFileDialog::getOpenFileName(this,"Выбрать файл", "C:\\","TXT File (*.txt)"));
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString bookCode = in.readLine();
        if(bookCode.size() > 5)
        {
            QMessageBox::warning(this,"Ошибка","Ошибка");
            return;
        }
        if(bookCode.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
        }
        for(int i = 0;i < bookCode.size();i++)
        {
            if(bookCode[i].isLetter())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        QString author = in.readLine();
        if(author.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
        for(int i = 0;i < author.size();i++)
        {
            if(!author[i].isLetter())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        QString bookName = in.readLine();
        if(bookName.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
        }
        for(int i = 0;i < bookName.size();i++)
        {
            if(!bookName[i].isLetter())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        QString year = in.readLine();
        if(year.size() > 4)
        {
            QMessageBox::warning(this,"Ошибка","Ошибка8");
            return;
        }
        if(year.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
        }
        for(int i = 0;i < year.size();i++)
        {
            if(!year[i].isDigit())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        QString language = in.readLine();
        if(language.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
        }
        for(int i = 0;i < language.size();i++)
        {
            if(!language[i].isLetter())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
        }
        books = addBook(books,bookCode.toInt(),author,bookName,year.toInt(),language);
    }
    file.close();
}



PromiseBook* addPromiseBook(PromiseBook *obj, Library book,Reader reader,QDate date)
{
    if(prBookCount == 1)
    {
        obj[0].setData(book,reader,date);
    }
    else
    {
        PromiseBook *tmp_obj = new PromiseBook[prBookCount];
        for(int i = 0; i < prBookCount - 1;i++)
        {
            tmp_obj[i] = obj[i];
        }
        delete[] obj;
        obj = tmp_obj;
        obj[prBookCount - 1].setData(book,reader,date);
    }
    prBookCount++;
    return obj;
}


void MainWindow::on_generatePromiser_clicked() // список книг, находящихся у читателей
{
    if(prGenerated){
        PromiseBook *temp_obj = new PromiseBook[1];
        delete[] prBooks;
        prBooks = temp_obj;
        prBookCount = 1;
    }
    srand(time(NULL));
    if(librarySize < readersCount)
    {
        for(int i = 0; i < librarySize - 1;i++)
        {
            int l,r;
            if(librarySize > 1)
            {
                l = rand() % (librarySize - 1);
            }
            else
            {
                l = 0;
            }
            if(readersCount > 1)
            {
                r = rand() % (readersCount - 1);
            }
            else
            {
                r = 0;
            }
            QDate d;
            d = d.currentDate();
            int days = -(rand() % 30 + 1);
            d = d.addDays(days);
            prBooks = addPromiseBook(prBooks,books[l],readersArr[r],d);
        }
    }
    if(librarySize >= readersCount)
    {
        for(int i = 0; i < readersCount - 1;i++)
        {
            int l,r;
            if(librarySize > 1)
            {
                l = rand() % (librarySize - 1);
            }
            else
            {
                l = 0;
            }
            if(readersCount > 1)
            {
                r = rand() % (readersCount - 1);
            }
            else
            {
                r = 0;
            }
            QDate d;
            d = d.currentDate();
            int days = -(rand() % 30 + 1);
            d = d.addDays(days);
            prBooks = addPromiseBook(prBooks,books[l],readersArr[r],d);
        }
    }
    ui->listWidget->clear();
    for(int i = 0; i < prBookCount - 1;i++)
    {
        ui->listWidget->addItem(prBooks[i].returnString());
    }
    prGenerated = true;
}


void MainWindow::on_pushButton_clicked() // поиск читателя по ФИО
{
    ui->listWidget->clear();
    QString fio = QInputDialog::getText(this,"Введите ФИО","ФИО:",QLineEdit::Normal);
    for(int i = 0; i < readersCount - 1;i++)
    {
        if(fio == readersArr[i].returnName())
        {
            ui->listWidget->addItem(readersArr[i].returnString());
        }
    }
}


void MainWindow::on_findBookByAuthor_clicked()
{
    ui->listWidget->clear();
    QString fio = QInputDialog::getText(this,"Введите ФИО","ФИО:",QLineEdit::Normal);
    for(int i = 0; i < librarySize - 1;i++)
    {
        if(fio == books[i].returnAuthor())
        {
            ui->listWidget->addItem(books[i].returnString());
        }
    }
}


void MainWindow::on_findBookByName_clicked()
{
    ui->listWidget->clear();
    QString name = QInputDialog::getText(this,"Введите название книги","Название:", QLineEdit::Normal);
    for(int i = 0; i < librarySize - 1;i++)
    {
        if(name == books[i].returnBookName())
        {
            ui->listWidget->addItem(books[i].returnString());
        }
    }
}


void MainWindow::on_generatePromiser_2_clicked()
{
    ui->comboBox->clear();
    for(int i = 0; i < readersCount - 1;i++)
    {
        for(int j = 0; j < prBookCount - 1; j++)
        {
        if(readersArr[i].returnReaderCode() == prBooks[j].returnReaderCode())
            if(prBooks[j].debt())
                ui->comboBox->addItem(readersArr[i].returnName());
        }
    }
}


void MainWindow::on_NumberOfBookSort_clicked()
{
    for(int i=0; i < librarySize - 1; i++)
    {
        for(int j = librarySize - 2; j > i; j-- )
        {
          if ( books[j-1].returnBookCode() > books[j].returnBookCode() )
          {
              Library tmp = books[j-1];
              books[j-1] = books[j];
              books[j] = tmp;
          }
        }

    }
}


void MainWindow::on_YearSort_clicked()
{
    for(int i=0; i < librarySize - 1; i++)
    {
        for(int j = librarySize - 2; j > i; j-- )
        {
          if ( books[j-1].returnYear() > books[j].returnYear() )
          {
              Library tmp = books[j-1];
              books[j-1] = books[j];
              books[j] = tmp;
          }
        }

    }
}


void MainWindow::on_showListOfBooks_clicked()
{
    ui->listWidget->clear();
    for(int i = 0; i < librarySize - 1;i++)
    {
        ui->listWidget->addItem(books[i].returnString());
    }
}


void MainWindow::on_showListOfReaders_clicked()
{
    ui->listWidget->clear();
    for(int i = 0; i < readersCount - 1; i++)
    {
       ui->listWidget->addItem(readersArr[i].returnString());
    }
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    for(int i = 0; i < readersCount - 1; i++)
    {
        if(item->text() == readersArr[i].returnString())
        {
            QString name = QInputDialog::getText(this,"Введите ФИО","ФИО:",QLineEdit::Normal);
            if(name.isEmpty())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
            for(int i = 0;i < name.size();i++)
            {
                if(!name[i].isLetter())
                {
                    QMessageBox::warning(this,"Ошибка","Ошибка!");
                    return;
                }
            }
            int rCode = QInputDialog::getInt(this,"Введите номер читателя","Номер:",0,0,99999,QLineEdit::Normal);
            QString homeAddress = QInputDialog::getText(this,"Введите домашний адрес","Адрес:",QLineEdit::Normal);
            if(homeAddress.isEmpty())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
            }
            for(int i = 0;i < homeAddress.size();i++)
            {
                if(!homeAddress[i].isLetter())
                {
                    QMessageBox::warning(this,"Ошибка","Ошибка!");
                    return;
                }
            }
            QString phoneNumber = QInputDialog::getText(this,"Введите контактный номер","Номер:",QLineEdit::Normal);
            if(homeAddress.isEmpty())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
            }
            for(int i = 0;i < phoneNumber.size();i++)
            {
                if(!phoneNumber[i].isDigit())
                {
                    QMessageBox::warning(this,"Ошибка","Ошибка!");
                    return;
                }
            }
            readersArr[i].setData(name,rCode,homeAddress,phoneNumber);
        }
    }
    for(int i = 0; i < librarySize -1;i++)
    {
        if(item->text() == books[i].returnString())
        {
            QString bookCode = QInputDialog::getText(this,"Номер книги","Номер:",QLineEdit::Normal);
            if(bookCode.isEmpty())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
            if(bookCode.size() > 5)
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
            for(int i = 0;i < bookCode.size();i++)
            {
                if(!bookCode[i].isDigit())
                {
                    QMessageBox::warning(this,"Ошибка","Ошибка!");
                    return;
                }
            }
            QString author = QInputDialog::getText(this,"Введите ФИО автора","ФИО:",QLineEdit::Normal);
            if(author.isEmpty())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
            for(int i = 0;i < author.size();i++)
            {
                if(!author[i].isLetter())
                {
                    QMessageBox::warning(this,"Ошибка","Ошибка!");
                    return;
                }
            }
            QString bookName = QInputDialog::getText(this,"Введите название книги","Название:",QLineEdit::Normal);
            if(bookName.isEmpty())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
            for(int i = 0;i < bookName.size();i++)
            {
                if(!bookName[i].isLetter())
                {
                    QMessageBox::warning(this,"Ошибка","Ошибка!");
                    return;
                }
            }
            QString year = QInputDialog::getText(this,"Введите год","Год:",QLineEdit::Normal);
            if(year.isEmpty())
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
            if(year.size() > 4)
            {
                QMessageBox::warning(this,"Ошибка","Ошибка!");
                return;
            }
            for(int i = 0;i < year.size();i++)
            {
                if(!year[i].isDigit())
                {
                    QMessageBox::warning(this,"Ошибка","Ошибка!");
                    return;
                }
            }
            QString language = QInputDialog::getText(this,"Введите язык","Язык:",QLineEdit::Normal);
            books[i].setData(bookCode.toInt(),author,bookName,year.toInt(),language);
        }
    }
}


void MainWindow::on_saveButton_clicked()
{
    QFile file1(QFileDialog::getOpenFileName(this,"Сохранить список читателей", "C:\\","TXT File (*.txt)"));
    if (!file1.open(QIODevice::WriteOnly)) {
        qWarning("Cannot open file for reading");
    }
    QTextStream out1(&file1);
    for(int i = 0; i < readersCount - 1;i++)
    {
        out1 << readersArr[i].name << "\n" << readersArr[i].rCode << "\n" << readersArr[i].homeAddress << "\n" << readersArr[i].phoneNumber << "\n";
    }
    file1.close();
    QFile file2(QFileDialog::getOpenFileName(this,"Сохранить список книг", "C:\\","TXT File (*.txt)"));
    if(!file2.open(QIODevice::WriteOnly)){
        qWarning("Cannot open file for reading");
    }
    QTextStream out2(&file2);
    for(int i = 0;i < librarySize - 1;i++)
    {
        out2 << books[i].bookCode << "\n" << books[i].author << "\n" << books[i].bookName << "\n" << books[i].year << "\n" <<books[i].language << "\n";
    }
    file2.close();
}


void MainWindow::on_newReader_clicked()
{
    QString name = QInputDialog::getText(this,"Введите ФИО","ФИО:",QLineEdit::Normal);
    if(name.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < name.size();i++)
    {
        if(!name[i].isLetter())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    int rCode = QInputDialog::getInt(this,"Введите номер читателя","Номер:",0,0,99999,QLineEdit::Normal);
    QString homeAddress = QInputDialog::getText(this,"Введите домашний адрес","Адрес:",QLineEdit::Normal);
    if(homeAddress.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
    }
    for(int i = 0;i < homeAddress.size();i++)
    {
        if(!homeAddress[i].isLetter())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    QString phoneNumber = QInputDialog::getText(this,"Введите контактный номер","Номер:",QLineEdit::Normal);
    if(homeAddress.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
    }
    for(int i = 0;i < phoneNumber.size();i++)
    {
        if(!phoneNumber[i].isDigit())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    readersArr = addReader(readersArr,name,rCode,homeAddress,phoneNumber);
}


void MainWindow::on_newBook_clicked()
{
    int bookCode = QInputDialog::getInt(this,"Номер книги","Номер:",0,0,99999,QLineEdit::Normal);
    QString author = QInputDialog::getText(this,"Введите ФИО автора","ФИО:",QLineEdit::Normal);
    if(author.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < author.size();i++)
    {
        if(!author[i].isLetter())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    QString bookName = QInputDialog::getText(this,"Введите название книги","Название:",QLineEdit::Normal);
    if(bookName.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < bookName.size();i++)
    {
        if(!bookName[i].isLetter())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    int year = QInputDialog::getInt(this,"Введите год","Год:",0,0,2022,QLineEdit::Normal);
    QString language = QInputDialog::getText(this,"Введите язык","Язык:",QLineEdit::Normal);
    if(language.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Ошибка!");
        return;
    }
    for(int i = 0;i < language.size();i++)
    {
        if(!language[i].isLetter())
        {
            QMessageBox::warning(this,"Ошибка","Ошибка!");
            return;
        }
    }
    books = addBook(books,bookCode,author,bookName,year,language);
}


Reader* deletePerson(Reader *obj,int index)
{
    if(readersCount > 0)
    {
    readersCount--;
    Reader* temp_Obj = new Reader[readersCount];
    int j = 0;
    for (int i = 0; i < readersCount; i++) {
        if (i != index) {
            temp_Obj[j] = obj[i];
            j++;
            }
        }
    delete[] obj;
    obj = temp_Obj;
    }
    return obj;
}

Library* deleteBook(Library *obj,int index)
{
    if(librarySize > 0)
    {
        librarySize--;
        Library* temp_obj = new Library[librarySize];
        int j = 0;
        for(int i = 0; i < librarySize;i++)
        {
            if(i != index)
            {
                temp_obj[j] = obj[i];
                j++;
            }
        }
        delete[] obj;
        obj = temp_obj;
    }
    return obj;
}

void MainWindow::on_deleteReader_clicked()
{
    int str = QInputDialog::getText(this,"Введите номер читателя", "Номер:",QLineEdit::Normal).toInt();
    if(readersCount > 0)
    {
        for(int i = 0; i < readersCount - 1;i++)
        {
            if(str == readersArr[i].returnReaderCode())
            {
                readersArr = deletePerson(readersArr,i);
            }
        }
    }
}


void MainWindow::on_deleteBook_clicked()
{
    int str = QInputDialog::getText(this,"Введите номер книги", "Номер:",QLineEdit::Normal).toInt();
        for(int i = 0; i < librarySize - 1;i++)
        {
            if(str == books[i].returnBookCode())
            {
                 books = deleteBook(books,i);
            }
        }
}


