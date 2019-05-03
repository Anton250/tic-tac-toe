#include "dealingwithmap.h"

dealingWithMap::dealingWithMap()
{

}

void dealingWithMap::drawMap(QGraphicsRectItem * items[], QGraphicsScene & scene)
{
   items[0] = new QGraphicsRectItem(0, 0, 60, 30);
   items[0]->setPos(30, 30);
   items[1] = new QGraphicsRectItem(0, 0, 90, 30);
   items[1]->setPos(120, 30);
   items[2] = new QGraphicsRectItem(0, 0, 20, 60);
   items[2]->setPos(240, 0);
   items[3] = new QGraphicsRectItem(0, 0, 90, 30);
   items[3]->setPos(290, 30);
   items[4] = new QGraphicsRectItem(0, 0, 60, 30);
   items[4]->setPos(410, 30);
   items[5] = new QGraphicsRectItem(0, 0, 60, 20);
   items[5]->setPos(30, 90);
   items[6] = new QGraphicsRectItem(0, 0, 20, 120);
   items[6]->setPos(120, 90);
   items[7] = new QGraphicsRectItem(0, 0, 160, 20);
   items[7]->setPos(170, 90);
   items[8] = new QGraphicsRectItem(0, 0, 20, 120);
   items[8]->setPos(360, 90);
   items[9] = new QGraphicsRectItem(0, 0, 60, 20);
   items[9]->setPos(410, 90);
   items[10] = new QGraphicsRectItem(0, 0, 90, 190);
   items[10]->setPos(0, 140);
   items[11] = new QGraphicsRectItem(0, 0, 70, 20);
   items[11]->setPos(140, 140);
   items[12] = new QGraphicsRectItem(0, 0, 20, 50);
   items[12]->setPos(240, 110);
   items[13] = new QGraphicsRectItem(0, 0, 70, 20);
   items[13]->setPos(290, 140);
   items[14] = new QGraphicsRectItem(0, 0, 90, 190);
   items[14]->setPos(410, 140);
   items[15] = new QGraphicsRectItem(0, 0, 160, 90);
   items[15]->setPos(170, 190);
   items[16] = new QGraphicsRectItem(0, 0, 20, 90);
   items[16]->setPos(120, 240);
   items[17] = new QGraphicsRectItem(0, 0, 20, 90);
   items[17]->setPos(360, 240);
   items[18] = new QGraphicsRectItem(0, 0, 160, 20);
   items[18]->setPos(170, 310);
   items[19] = new QGraphicsRectItem(0, 0, 20, 50);
   items[19]->setPos(240, 330);
   items[20] = new QGraphicsRectItem(0, 0, 60, 20);
   items[20]->setPos(30, 360);
   items[21] = new QGraphicsRectItem(0, 0, 90, 20);
   items[21]->setPos(120, 360);
   items[22] = new QGraphicsRectItem(0, 0, 90, 20);
   items[22]->setPos(290, 360);
   items[23] = new QGraphicsRectItem(0, 0, 60, 20);
   items[23]->setPos(410, 360);
   items[24] = new QGraphicsRectItem(0, 0, 20, 50);
   items[24]->setPos(70, 380);
   items[25] = new QGraphicsRectItem(0, 0, 20, 50);
   items[25]->setPos(410, 380);
   items[26] = new QGraphicsRectItem(0, 0, 40, 20);//
   items[26]->setPos(0, 410);
   items[27] = new QGraphicsRectItem(0, 0, 20, 50);
   items[27]->setPos(120, 410);
   items[28] = new QGraphicsRectItem(0, 0, 160, 20);
   items[28]->setPos(170, 410);
   items[29] = new QGraphicsRectItem(0, 0, 20, 50);
   items[29]->setPos(360, 410);
   items[30] = new QGraphicsRectItem(0, 0, 40, 20);
   items[30]->setPos(460, 410);
   items[31] = new QGraphicsRectItem(0, 0, 180, 20);
   items[31]->setPos(30, 460);
   items[32] = new QGraphicsRectItem(0, 0, 20, 50);
   items[32]->setPos(240, 430);
   items[33] = new QGraphicsRectItem(0, 0, 180, 20);
   items[33]->setPos(290, 460);
   for (int i = 0; i < 34; i++){
       items[i]->setBrush(Qt::black);
       items[i]->setPen(QPen( Qt::blue, 3, Qt::SolidLine));
       scene.addItem(items[i]);
   }
}
