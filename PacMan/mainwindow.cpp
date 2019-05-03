#include "mainwindow.h"


void MainWindow::keyPressEvent(QKeyEvent *key)
{
    if (key->key() == Qt::Key_Up){
        if (ellipse.y() - 10 >= 0 && checkRect(ellipse.x(), ellipse.y() - 10)) {

            ellipse.setPos(ellipse.x(), ellipse.y() - 10);
            checkNumNum(ellipse.x(),ellipse.y() - 10);
        }
    }
    if (key->key() == Qt::Key_Down){
        if (ellipse.y() + 10 <= 480 && checkRect(ellipse.x(), ellipse.y() + 10)){
            ellipse.setPos(ellipse.x(), ellipse.y() + 10);
            checkNumNum(ellipse.x(),ellipse.y() + 10);
        }
    }
    if (key->key() == Qt::Key_Left){
        if (ellipse.x() - 10 >= 0 && checkRect(ellipse.x() - 10, ellipse.y())){
            ellipse.setPos(ellipse.x() - 10, ellipse.y());
            checkNumNum(ellipse.x() - 10,ellipse.y());
        }
    }
    if (key->key() == Qt::Key_Right){
        if (ellipse.x() + 10 <= 470 && checkRect(ellipse.x() + 10, ellipse.y())){
            ellipse.setPos(ellipse.x() + 10, ellipse.y());
            checkNumNum(ellipse.x() + 10,ellipse.y());
        }
    }
}

void MainWindow::drawNumNum()
{
  srand((unsigned int)(time(nullptr)));
  qreal x = 10 + rand() % 490;
  qreal y = 10 + rand() % 500;
  x = int(x/10) * 10;
  y = int(y/10) * 10;
  qDebug()<< x << y;
  numNum.setRect(0, 0, 10, 10);
  numNum.setBrush(Qt::white);
  while(!checkValidNumNum(x, y)){
      x = 10 + rand() % 490;
      y = 10 + rand() % 500;
  }

    numNum.setPos(x, y);

  scene.addItem(&numNum);
}

MainWindow::MainWindow(int h, int w, QWidget *parent)
    : QGraphicsView(parent),
      scene(0, 0, w, h, this) {
         connect(this, &MainWindow::addNumNum, this, &MainWindow::drawNumNum);
         setScene(&scene);
         fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
         QGraphicsRectItem * rect = new QGraphicsRectItem(0, 0, 500, 510);
         rect->setBrush(Qt::gray);
         scene.addItem(rect);
         scene.addText("Your score:")->setX(500);
         score.setPlainText("0");
         score.setX(570);
         scene.addItem(&score);

         drawMap(rects, scene);
         drawNumNum();

         ellipse.setRect(0, 0, 30, 30);

         ellipse.setBrush(Qt::yellow);
         ellipse.setPos(250,280);
         scene.addItem(&ellipse);


     }



MainWindow::~MainWindow()
{

}



bool MainWindow::checkRect(qreal x, qreal y)
{


    qreal x1, y1 ,w ,h;
    for (int i = 0; i < 34; i++){
        x1 = rects[i]->x();
        y1 = rects[i]->y();
        w = rects[i]->rect().width();
        h = rects[i]->rect().height();
        if(x > (x1 - 30) && x < (x1 + w) && y > (y1 - 30) && y < (y1 + h)){
            return false;
        }
    }
    return true;
}

bool MainWindow::checkValidNumNum(qreal x, qreal y)
{
    qreal x1, y1 ,w ,h;
    for (int i = 0; i < 34; i++){
        x1 = rects[i]->x();
        y1 = rects[i]->y();
        w = rects[i]->rect().width();
        h = rects[i]->rect().height();
        if(x > (x1 - 10) && x < (x1 + w) && y > (y1 - 10) && y < (y1 + h)){
            return false;
        }
    }
    return true;
}

void MainWindow::checkNumNum(qreal x, qreal y)
{
    if (numNum.x() < x + 30 && numNum.x() + 10 > x && numNum.y() < y + 30 && numNum.y() + 10 > y){
        userScore++;
        score.setPlainText(QString::number(userScore));
        srand((unsigned int)(time(nullptr)));
        x = 10 + rand() % 490;
        y = 10 + rand() % 500;
        x = int(x/10) * 10;
        y = int(y/10) * 10;
        while(!checkValidNumNum(x, y)){
            x = 10 + rand() % 490;
            y = 10 + rand() % 500;
            x = int(x/10) * 10;
            y = int(y/10) * 10;
        }

        numNum.setPos(x, y);
    }
}


