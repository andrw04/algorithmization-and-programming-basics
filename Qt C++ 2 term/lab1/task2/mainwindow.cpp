#include "mainwindow.h"
#include "ui_mainwindow.h"
QColor CIRCLE_PEN_COLOR;
QColor CIRCLE_BRUSH_COLOR;
int CIRCLE_POS_X = 0;
int CIRCLE_POS_Y = 0;
int R = 10;
QColor RECTANGLE_PEN_COLOR;
QColor RECTANGLE_BRUSH_COLOR;
int RECTANGLE_POS_X = 0;
int RECTANGLE_POS_Y = 0;
int RECTANGLE_WIDTH;
int RECTANGLE_HEIGHT;
QColor ELLIPSE_PEN_COLOR;
QColor ELLIPSE_BRUSH_COLOR;
int ELLIPSE_POS_X = 0;
int ELLIPSE_POS_Y = 0;
int ELLIPSE_WIDTH;
int ELLIPSE_HEIGHT;
QColor SQUARE_PEN_COLOR;
QColor SQUARE_BRUSH_COLOR;
int SQUARE_POS_X = 0;
int SQUARE_POS_Y = 0;
int SQUARE_SIDE;
QColor TRIANGLE_PEN_COLOR;
QColor TRIANGLE_BRUSH_COLOR;
int TRIANGLE_POS_X = 0;
int TRIANGLE_POS_Y = 0;
int TRIANGLE_BASE;
int TRIANGLE_SIDE;
QColor STAR_PEN_COLOR;
QColor STAR_BRUSH_COLOR;
int STAR_POS_X = 0;
int STAR_POS_Y = 0;
int STAR_R;
QColor HEXAGONE_PEN_COLOR;
QColor HEXAGONE_BRUSH_COLOR;
int HEXAGONE_POS_X = 0;
int HEXAGONE_POS_Y = 0;
int HEXAGONE_SIDE;
bool CIRCLE_PARAMETRS = false;
bool RECTANGLE_PARAMETRS = false;
bool ELLIPSE_PARAMETRS = false;
bool SQUARE_PARAMETRS = false;
bool TRIANGLE_PARAMETRS = false;
bool STAR_PARAMETRS = false;
bool HEXAGONE_PARAMETRS = false;
bool FIGURE_EXISTS = false;
int circle_count = 0;
int ellipse_count = 0;
int rectangle_count = 0;
int square_count = 0;
int triangle_count = 0;
int star_count = 0;
int hexagone_count = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    //circle = new Circle[circleCount];
    ui->graphicsView->setScene(scene);
    scene->addLine(-1000,0,1000,0);
    scene->addLine(0,-1000,0,1000);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    cDialog = new CircleDialog;
    rDialog = new RectangleDialog;
    eDialog = new EllipseDialog;
    sDialog = new SquareDialog;
    tDialog = new TriangleDialog;
    stDialog = new StarDialog;
    hDialog = new HexagoneDialog;
    timer = new QTimer;
    rotatingTimer = new QTimer;
    canva = new Canva;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::getCircleInfo(int pos_x, int pos_y, int r, QColor brush_color, QColor pen_color)
{
    CIRCLE_PEN_COLOR = pen_color;
    CIRCLE_BRUSH_COLOR = brush_color;
    CIRCLE_POS_X = pos_x;
    CIRCLE_POS_Y = pos_y;
    R = r;
}
void MainWindow::getRectangleInfo(int pos_x, int pos_y, int w,int h, QColor brush_color, QColor pen_color)
{
    RECTANGLE_PEN_COLOR = pen_color;
    RECTANGLE_BRUSH_COLOR = brush_color;
    RECTANGLE_POS_X = pos_x;
    RECTANGLE_POS_Y = pos_y;
    RECTANGLE_WIDTH = w;
    RECTANGLE_HEIGHT = h;
}
void MainWindow::getEllipseInfo(int pos_x, int pos_y, int horisontal, int vertical, QColor brush_color, QColor pen_color)
{
    ELLIPSE_POS_X = pos_x;
    ELLIPSE_POS_Y = pos_y;
    ELLIPSE_WIDTH = horisontal;
    ELLIPSE_HEIGHT = vertical;
    ELLIPSE_PEN_COLOR = pen_color;
    ELLIPSE_BRUSH_COLOR = brush_color;
}

void MainWindow::getSquareInfo(int pos_x, int pos_y, int side_size, QColor brush_color, QColor pen_color)
{
    SQUARE_POS_X = pos_x;
    SQUARE_POS_Y = pos_y;
    SQUARE_SIDE = side_size;
    SQUARE_BRUSH_COLOR = brush_color;
    SQUARE_PEN_COLOR = pen_color;

}

void MainWindow::getTriangleInfo(int pos_x, int pos_y, int base_size, int side_size, QColor brush_color, QColor pen_color)
{
    TRIANGLE_POS_X = pos_x;
    TRIANGLE_POS_Y = pos_y;
    TRIANGLE_BASE = base_size;
    TRIANGLE_SIDE = side_size;
    TRIANGLE_BRUSH_COLOR = brush_color;
    TRIANGLE_PEN_COLOR = pen_color;
}

void MainWindow::getStarInfo(int pos_x, int pos_y, int r, QColor brush_color, QColor pen_color)
{
    STAR_POS_X = pos_x;
    STAR_POS_Y = pos_y;
    STAR_R = r;
    STAR_BRUSH_COLOR = brush_color;
    STAR_PEN_COLOR = pen_color;

}

void MainWindow::getHexagoneInfo(int pos_x, int pos_y, int side_size, QColor brush_color, QColor pen_color)
{
    HEXAGONE_POS_X = pos_x;
    HEXAGONE_POS_Y = pos_y;
    HEXAGONE_SIDE = side_size;
    HEXAGONE_BRUSH_COLOR = brush_color;
    HEXAGONE_PEN_COLOR = pen_color;

}

void MainWindow::on_FigureParametrs_clicked()
{
    if(ui->comboBox->currentText() == "Круг")
    {
        cDialog->setModal(true);
        cDialog->show();
        connect(cDialog,SIGNAL(sendInfo(int,int,int,QColor,QColor)),this,SLOT(getCircleInfo(int,int,int,QColor,QColor)));
    }
    else if(ui->comboBox->currentText() == "Прямоугольник")
    {
        rDialog->setModal(true);
        rDialog->show();
        connect(rDialog,SIGNAL(sendInfo(int,int,int,int,QColor,QColor)),this,SLOT(getRectangleInfo(int,int,int,int,QColor,QColor)));
    }
    else if(ui->comboBox->currentText() == "Эллипс")
    {
        eDialog->setModal(true);
        eDialog->show();
        connect(eDialog,SIGNAL(sendInfo(int,int,int,int,QColor,QColor)),this,SLOT(getEllipseInfo(int,int,int,int,QColor,QColor)));
    }
    else if(ui->comboBox->currentText() == "Квадрат")
    {
        sDialog->setModal(true);
        sDialog->show();
        connect(sDialog,SIGNAL(sendInfo(int,int,int,QColor,QColor)),this,SLOT(getSquareInfo(int,int,int,QColor,QColor)));
    }
    else if(ui->comboBox->currentText() == "Треугольник")
    {
        tDialog->setModal(true);
        tDialog->show();
        connect(tDialog,SIGNAL(sendInfo(int,int,int,int,QColor,QColor)),this,SLOT(getTriangleInfo(int,int,int,int,QColor,QColor)));
    }
    else if(ui->comboBox->currentText() == "Звезда")
    {
        stDialog->setModal(true);
        stDialog->show();
        connect(stDialog,SIGNAL(sendInfo(int,int,int,QColor,QColor)),this,SLOT(getStarInfo(int,int,int,QColor,QColor)));
    }
    else if(ui->comboBox->currentText() == "Шестиугольник")
    {
        hDialog->setModal(true);
        hDialog->show();
        connect(hDialog,SIGNAL(sendInfo(int,int,int,QColor,QColor)),this,SLOT(getHexagoneInfo(int,int,int,QColor,QColor)));
    }
}

bool FindString(QString s1,QString s2) // поиск в строке s1 строки s2
{
    for(int i = 0;i < s2.size();i++)
    {
        if(s1[i] != s2[i])
            return false;
    }
    return true;
}

void MainWindow::on_addFigure_clicked()
{
    if(ui->comboBox->currentText() == "Круг")
    {
        if(!CIRCLE_PARAMETRS)
        {
            QMessageBox::warning(this,"Ошибка!","Выберите параметры фигуры!");
            return;
        }
        circle = new Circle(CIRCLE_POS_X,CIRCLE_POS_Y,R,CIRCLE_BRUSH_COLOR,CIRCLE_PEN_COLOR);
        scene->addItem(circle);
        circles.append(circle);
        QString str = "Круг" + QString::number(circle_count++);
        ui->listWidget->addItem(str);
        FIGURE_EXISTS = true;
    }
    else if(ui->comboBox->currentText() == "Прямоугольник")
    {
        if(!RECTANGLE_PARAMETRS)
        {
            QMessageBox::warning(this,"Ошибка!","Выберите параметры фигуры!");
            return;
        }
        rectangle = new Rectangle(RECTANGLE_POS_X,RECTANGLE_POS_Y,RECTANGLE_WIDTH,RECTANGLE_HEIGHT,RECTANGLE_BRUSH_COLOR,RECTANGLE_PEN_COLOR);
        scene->addItem(rectangle);
        rectangles.append(rectangle);
        QString str = "Прямоугольник" + QString::number(rectangle_count++);
        ui->listWidget->addItem(str);
        FIGURE_EXISTS = true;
    }
    else if(ui->comboBox->currentText() == "Эллипс")
    {
        if(!ELLIPSE_PARAMETRS)
        {
            QMessageBox::warning(this,"Ошибка!","Выберите параметры фигуры!");
            return;
        }
        ellipse = new Ellipse(ELLIPSE_POS_X,ELLIPSE_POS_Y,ELLIPSE_WIDTH,ELLIPSE_HEIGHT,ELLIPSE_BRUSH_COLOR,ELLIPSE_PEN_COLOR);
        scene->addItem(ellipse);
        ellipses.append(ellipse);
        QString str = "Эллипс" + QString::number(ellipse_count++);
        ui->listWidget->addItem(str);
        FIGURE_EXISTS = true;
    }
    else if(ui->comboBox->currentText() == "Квадрат")
    {
        if(!SQUARE_PARAMETRS)
        {
            QMessageBox::warning(this,"Ошибка!","Выберите параметры фигуры!");
            return;
        }
        square = new Square(SQUARE_POS_X,SQUARE_POS_Y,SQUARE_SIDE,SQUARE_BRUSH_COLOR,SQUARE_PEN_COLOR);
        scene->addItem(square);
        squares.append(square);
        QString str = "Квадрат" + QString::number(square_count++);
        ui->listWidget->addItem(str);
        FIGURE_EXISTS = true;
    }
    else if(ui->comboBox->currentText() == "Треугольник")
    {
        if(!TRIANGLE_PARAMETRS)
        {
            QMessageBox::warning(this,"Ошибка!","Выберите параметры фигуры!");
            return;
        }
        triangle = new Triangle(TRIANGLE_POS_X,TRIANGLE_POS_Y,TRIANGLE_BASE,TRIANGLE_SIDE,TRIANGLE_BRUSH_COLOR,TRIANGLE_PEN_COLOR);
        scene->addItem(triangle);
        triangles.append(triangle);
        QString str = "Треугольник" + QString::number(triangle_count++);
        ui->listWidget->addItem(str);
        FIGURE_EXISTS = true;
    }
    else if(ui->comboBox->currentText() == "Звезда")
    {
        if(!STAR_PARAMETRS)
        {
            QMessageBox::warning(this,"Ошибка!","Выберите параметры фигуры!");
            return;
        }
        star = new Star(STAR_POS_X,STAR_POS_Y,STAR_R,STAR_BRUSH_COLOR,STAR_PEN_COLOR);
        scene->addItem(star);
        stars.append(star);
        QString str = "Звезда" + QString::number(star_count++);
        ui->listWidget->addItem(str);
        FIGURE_EXISTS = true;
    }
    else if(ui->comboBox->currentText() == "Шестиугольник")
    {
        if(!HEXAGONE_PARAMETRS)
        {
            QMessageBox::warning(this,"Ошибка!","ВЫберите параметры фигуры!");
            return;
        }
        hexagone = new Hexagone(HEXAGONE_POS_X,HEXAGONE_POS_Y,HEXAGONE_SIDE,HEXAGONE_BRUSH_COLOR,HEXAGONE_PEN_COLOR);
        scene->addItem(hexagone);
        hexagons.append(hexagone);
        QString str = "Шестиугольник" + QString::number(hexagone_count++);
        ui->listWidget->addItem(str);
        FIGURE_EXISTS = true;
    }
}



void MainWindow::on_moveRight_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"Ошибка!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите фигуру в списке!");
        return;
    }
    QString str = ui->listWidget->currentItem()->text();
    if(FindString(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        connect(timer,SIGNAL(timeout()),circles[i],SLOT(MoveRight()));
        timer->start(3);
    }
    else if(FindString(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),ellipses[i],SLOT(MoveRight()));
        timer->start(3);
    }
    else if(FindString(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),rectangles[i],SLOT(MoveRight()));
        timer->start(3);
    }
    else if(FindString(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        connect(timer,SIGNAL(timeout()),squares[i],SLOT(MoveRight()));
        timer->start(3);

    }
    else if(FindString(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        connect(timer,SIGNAL(timeout()),triangles[i],SLOT(MoveRight()));
        timer->start(3);
    }
    else if(FindString(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),stars[i],SLOT(MoveRight()));
        timer->start(3);
    }
    else if(FindString(str,"Шестиугольник"))
    {
        int i = str.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),hexagons[i],SLOT(MoveRight()));
        timer->start(3);
    }
}


void MainWindow::on_SquareSelected_clicked()
{
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите фигуру в списке!");
        return;
    }
    QString str = ui->listWidget->currentItem()->text();
    if(FindString(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        QMessageBox::information(this,"Площадь","Площадь круга: " + QString::number(circles[i]->SQUARE()));
    }
    else if(FindString(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        QMessageBox::information(this,"Площадь","Площадь эллипса: " + QString::number(ellipses[i]->SQUARE()));
    }
    else if(FindString(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        QMessageBox::information(this,"Площадь","Площадь прямоугольника: " + QString::number(rectangles[i]->SQUARE()));
    }
    else if(FindString(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        QMessageBox::information(this,"Площадь","Площадь квадрата: " + QString::number(squares[i]->SQUARE()));
    }
    else if(FindString(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        QMessageBox::information(this,"Площадь","Площадь треугольника: " +QString::number(triangles[i]->SQUARE()));
    }
    else if(FindString(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        QMessageBox::information(this,"Площадь","Площадь звезды: " + QString::number(stars[i]->SQUARE()));
    }
    else if(FindString(str,"Шестиугольник"))
    {
        int i = str.remove(0,13).toInt();
        QMessageBox::information(this,"Площадь","Площадь фигуры: " + QString::number(hexagons[i]->SQUARE()));
    }
}


void MainWindow::on_PerimetrSelected_clicked()
{
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите выделите фигуру в списке!");
        return;
    }
    QString str = ui->listWidget->currentItem()->text();
    if(FindString(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        QMessageBox::information(this,"Периметр","Периметр круга: " + QString::number(circles[i]->PERIMETR()));
    }
    else if(FindString(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        QMessageBox::information(this,"Периметр","Периметр эллипса: " + QString::number(ellipses[i]->PERIMETR()));
    }
    else if(FindString(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        QMessageBox::information(this,"Периметр","Периметр прямоугольника: " + QString::number(rectangles[i]->PERIMETR()));
    }
    else if(FindString(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        QMessageBox::information(this,"Периметр","Периметр квадрата: " + QString::number(squares[i]->PERIMETR()));
    }
    else if(FindString(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        QMessageBox::information(this,"Периметр","Периметр треугольника: " +QString::number(triangles[i]->PERIMETR()));
    }
    else if(FindString(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        QMessageBox::information(this,"Периметр","Периметр звезды: " + QString::number(stars[i]->PERIMETR()));
    }
    else if(FindString(str,"Шестиугольник"))
    {
        int i = str.remove(0,13).toInt();
        QMessageBox::information(this,"Периметр","Периметр звезды: " + QString::number(hexagons[i]->PERIMETR()));
    }
}



void MainWindow::on_moveLeft_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"Ошибка!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите выделите фигуру в списке!");
        return;
    }
    QString str = ui->listWidget->currentItem()->text();
    if(FindString(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        connect(timer,SIGNAL(timeout()),circles[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(FindString(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),ellipses[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(FindString(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),rectangles[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(FindString(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        connect(timer,SIGNAL(timeout()),squares[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(FindString(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        connect(timer,SIGNAL(timeout()),triangles[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(FindString(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),stars[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(FindString(str,"Шестиугольник"))
    {
        int i = str.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),hexagons[i],SLOT(MoveLeft()));
        timer->start(3);
    }
}


void MainWindow::on_moveUp_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"Ошибка!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите выделите фигуру в списке!");
        return;
    }
    QString str = ui->listWidget->currentItem()->text();
    if(FindString(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        connect(timer,SIGNAL(timeout()),circles[i],SLOT(MoveUp()));
        timer->start(3);
    }
    else if(FindString(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),ellipses[i],SLOT(MoveUp()));
        timer->start(3);
    }
    else if(FindString(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),rectangles[i],SLOT(MoveUp()));
        timer->start(3);
    }
    else if(FindString(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        connect(timer,SIGNAL(timeout()),squares[i],SLOT(MoveUp()));
        timer->start(3);
    }
    else if(FindString(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
         connect(timer,SIGNAL(timeout()),triangles[i],SLOT(MoveUp()));
         timer->start(3);
    }
    else if(FindString(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),stars[i],SLOT(MoveUp()));
        timer->start(3);
    }
    else if(FindString(str,"Шестиугольник"))
    {
        int i = str.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),hexagons[i],SLOT(MoveUp()));
        timer->start(3);
    }
}


void MainWindow::on_moveDown_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"Ошибка!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите выделите фигуру в списке!");
        return;
    }
    QString str = ui->listWidget->currentItem()->text();
    if(FindString(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        connect(timer,SIGNAL(timeout()),circles[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(FindString(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),ellipses[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(FindString(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),rectangles[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(FindString(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        connect(timer,SIGNAL(timeout()),squares[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(FindString(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        connect(timer,SIGNAL(timeout()),triangles[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(FindString(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),stars[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(FindString(str,"Шестиугольник"))
    {
        int i = str.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),hexagons[i],SLOT(MoveDown()));
        timer->start(3);
    }
}


void MainWindow::on_Scale_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"Ошибка!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите выделите фигуру в списке!");
        return;
    }
    QString str = ui->listWidget->currentItem()->text();
    if(FindString(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        circles[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите радиус",0,10,300));
        connect(timer,SIGNAL(timeout()),circles[i],SLOT(Scale()), Qt::UniqueConnection);
        timer->start(10);
    }
    else if(FindString(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        ellipses[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите большую полуось",0,10,500),QInputDialog::getInt(this,"Введите параметры","Введите меньшую полуось",0,10,300));
        connect(timer,SIGNAL(timeout()),ellipses[i],SLOT(Scale()), Qt::UniqueConnection);
        timer->start(10);
    }
    else if(FindString(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        rectangles[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите ширину",0,10,1000),QInputDialog::getInt(this,"Введите параметры","Введите высоту",0,10,600));
        connect(timer,SIGNAL(timeout()),rectangles[i],SLOT(Scale()), Qt::UniqueConnection);
        timer->start(10);
    }
    else if(FindString(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        squares[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите сторону",0,10,600));
        connect(timer,SIGNAL(timeout()),squares[i],SLOT(Scale()), Qt::UniqueConnection);
        timer->start(10);
    }
    else if(FindString(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        triangles[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите основание",0,10,1000),QInputDialog::getInt(this,"Введите параметры","Введите боковую сторону",0,10,600));
        connect(timer,SIGNAL(timeout()),triangles[i],SLOT(Scale()), Qt::UniqueConnection);
        timer->start(10);
    }
    else if(FindString(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        stars[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите радиус",0,10,500));
        connect(timer,SIGNAL(timeout()),stars[i],SLOT(Scale()),Qt::UniqueConnection);
        timer->start(10);
    }
    else if(FindString(str,"Шестиугольник"))
    {
        int i = str.remove(0,13).toInt();
        hexagons[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите сторону",0,10,500));
        connect(timer,SIGNAL(timeout()),hexagons[i],SLOT(Scale()),Qt::UniqueConnection);
        timer->start(10);
    }
}

void MainWindow::Lrotate()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"Ошибка!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите выделите фигуру в списке!");
        return;
    }
    QString str = ui->listWidget->currentItem()->text();
    if(FindString(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        circles[i]->setRotation(circles[i]->angleDec());

    }
    else if(FindString(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        ellipses[i]->setRotation(ellipses[i]->angleDec());
    }
    else if(FindString(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        rectangles[i]->setRotation(rectangles[i]->angleDec());
    }
    else if(FindString(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        squares[i]->setRotation(squares[i]->angleDec());

    }
    else if(FindString(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        rectangles[i]->setRotation(rectangles[i]->angleDec());
    }
    else if(FindString(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        stars[i]->setRotation(stars[i]->angleDec());
    }
    else if(FindString(str,"Шестиугольник"))
    {
        int i = str.remove(0,13).toInt();
        hexagons[i]->setRotation(hexagons[i]->angleDec());
    }
}
void MainWindow::Rrotate()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"Ошибка!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите выделите фигуру в списке!");
        return;
    }
    QString str = ui->listWidget->currentItem()->text();
    if(FindString(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        circles[i]->setRotation(circles[i]->angleInc());

    }
    else if(FindString(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        ellipses[i]->setRotation(ellipses[i]->angleInc());
    }
    else if(FindString(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        rectangles[i]->setRotation(rectangles[i]->angleInc());
    }
    else if(FindString(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        squares[i]->setRotation(squares[i]->angleInc());

    }
    else if(FindString(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        rectangles[i]->setRotation(rectangles[i]->angleInc());

    }
    else if(FindString(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        stars[i]->setRotation(stars[i]->angleInc());
    }
    else if(FindString(str,"Шестиугольник"))
    {
        int i = str.remove(0,13).toInt();
        hexagons[i]->setRotation(hexagons[i]->angleInc());
    }
}


void MainWindow::on_rotL_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"Ошибка!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите выделите фигуру в списке!");
        return;
    }
    connect(rotatingTimer,SIGNAL(timeout()),this,SLOT(Lrotate()));
    rotatingTimer->start(10);
}


void MainWindow::on_DxDy_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"Ошибка!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите выделите фигуру в списке!");
        return;
    }
    QString str = ui->listWidget->currentItem()->text();
    if(FindString(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        circles[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));

    }
    else if(FindString(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        ellipses[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));
    }
    else if(FindString(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        rectangles[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));
    }
    else if(FindString(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        squares[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));

    }
    else if(FindString(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        rectangles[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));

    }
    else if(FindString(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        stars[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));
    }
    else if(FindString(str,"Шестиугольник"))
    {
        int i = str.remove(0,6).toInt();
        hexagons[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),QInputDialog::getInt(this,"Введите параметры", "Введите dy",0,-1000,1000));
    }

}


void MainWindow::on_rotR_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"Ошибка!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listWidget->currentItem() == NULL)
    {
        QMessageBox::warning(this,"Ошибка!","Выберите выделите фигуру в списке!");
        return;
    }
    connect(rotatingTimer,SIGNAL(timeout()),this,SLOT(Rrotate()));
    rotatingTimer->start(10);
}


void MainWindow::on_myFigure_clicked()
{
    canva->setModal(true);
    canva->show();
}

