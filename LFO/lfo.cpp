#include "lfo.h"
#include "ui_lfo.h"
QLineF LFO::FadeUpLine(0,0,0,0);
QLineF LFO::FadeDownLine(0,0,0,0);
QLineF LFO::EffectUpLine(0,0,0,0);
QLineF LFO::EffectDownLine(0,0,0,0);
QLineF LFO::FadeStartLine(0,0,0,0);
QLineF LFO::FadeEndLine(0,0,0,0);
QLineF LFO::OffLine(0,0,0,0);
QGraphicsLineItem *LFO::ptrFadeUp = 0;
QGraphicsLineItem *LFO::ptrFadeDown = 0;
QGraphicsLineItem *LFO::ptrEffectUp = 0;
QGraphicsLineItem *LFO::ptrEffectDown = 0;
QGraphicsLineItem *LFO::ptrOffLine = 0;
QGraphicsScene *LFO::scene = 0;
QPen LFO::blackLine(Qt::black, 0);
QPen LFO::dotLine(Qt::DotLine);
QPen LFO::redLine(Qt::red, 0);

void LFO::setOffIn() {
    OffLine.setLine(30,15,30,160);
    ptrOffLine = scene->addLine(OffLine,dotLine);
    OffText = scene->addSimpleText("Off");
    OffText->setPos(30,164);
}
void LFO::setOffOut() {
    OffLine.setLine(42,15,42,160);
    ptrOffLine = scene->addLine(OffLine,dotLine);
    OffText = scene->addSimpleText("Off");
    OffText->setPos(40,164);
}

LFO::LFO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LFO)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    dotLine.setColor(Qt::blue);
    scene->setSceneRect(0, 0, 256, 192);
    scene->addLine(10, 192/2, 140, 192/2, blackLine);     // X axis
    scene->addLine(10, 10, 10, 162, blackLine);    // Y axis
    scene->addLine(15,15,15,160,dotLine);   // Note-On line
    QGraphicsSimpleTextItem *OnText = scene->addSimpleText("On");
    OnText->setPos(12,164);
    OffText = 0;
    FadeText = 0;
    DelayText = 0;
    EffectText = 0;
    ui->LFO_display->setScene(scene);
    ui->LFO_display->fitInView(0,0,80,35);
    ui->LFO_display->show();
    // fake set_initial_values section for testing
    ui->Delay_select->setValue(64);
    ui->Fade_select->setValue(64);
    ui->Depth_select->setValue(64);
    ui->Rate_select ->setValue(64);
    ui->FadeMode_select->setCurrentIndex(0);
}

LFO::~LFO()
{
    delete ui;
}

void LFO::on_Delay_select_valueChanged(int value)
{
    static QGraphicsLineItem *ptrFadeStartLine;
    qreal DelayVal = value/3;
    qreal oldX = ptrFadeStartLine?FadeStartLine.x1():10;
    if (ptrFadeStartLine) {
        scene->removeItem(ptrFadeStartLine);
        ptrFadeStartLine = 0;
    }
    if (DelayText) {
        scene->removeItem(DelayText);
        DelayText = 0;
    }
    if (ptrEffectUp) {
        scene->removeItem(ptrEffectUp);
        ptrEffectUp = 0;
    }
    if (ptrEffectDown) {
        scene->removeItem(ptrEffectDown);
        ptrEffectDown = 0;
    }
  if (value > 0) {
    switch(ui->FadeMode_select->currentIndex()) {
    case 0:   // On-In
        DelayVal += 15;
        FadeStartLine.setLine(DelayVal,15,DelayVal,160);
        ptrFadeStartLine = scene->addLine(FadeStartLine,dotLine);
        DelayText = scene->addSimpleText(value>50?"Dly":"D");
        DelayText->setPos(value>50 ? FadeStartLine.x1()/2 : FadeStartLine.x1()/2+5,5);
        break;
    case 1:   // On-Out
        DelayVal += 15;
        FadeStartLine.setLine(DelayVal,15,DelayVal,160);
        ptrFadeStartLine = scene->addLine(FadeStartLine,dotLine);
        DelayText = scene->addSimpleText(value>50?"Dly":"D");
        DelayText->setPos(value>50 ? FadeStartLine.x1()/2 : FadeStartLine.x1()/2+5,5);
        EffectUpLine.setLine(15,101-(ui->Depth_select->value()/2),FadeStartLine.x1(),101-(ui->Depth_select->value()/2));
        EffectDownLine.setLine(15,91+(ui->Depth_select->value()/2),FadeStartLine.x1(),91+(ui->Depth_select->value()/2));
        ptrEffectUp = scene->addLine(EffectUpLine,redLine);
        ptrEffectDown = scene->addLine(EffectDownLine,redLine);
        break;
    case 2:   // Off-In
        if (!ptrOffLine) setOffIn();
        DelayVal += OffLine.x1();
        FadeStartLine.setLine(DelayVal,15,DelayVal,160);
        ptrFadeStartLine = scene->addLine(FadeStartLine,dotLine);
        DelayText = scene->addSimpleText(value>50?"Dly":"D");
        DelayText->setPos((FadeStartLine.x1()+OffLine.x1())/2-10,5);
      break;
    case 3:   // Off-Out
        if (!ptrOffLine) setOffOut();
        DelayVal += OffLine.x1();
        FadeStartLine.setLine(DelayVal,15,DelayVal,160);
        ptrFadeStartLine = scene->addLine(FadeStartLine,dotLine);
        DelayText = scene->addSimpleText(value>50?"Dly":"D");
        DelayText->setPos((FadeStartLine.x1()+OffLine.x1())/2-10,5);
        EffectUpLine.setLine(15,101-(ui->Depth_select->value()/2),FadeStartLine.x1(),101-(ui->Depth_select->value()/2));
        EffectDownLine.setLine(15,91+(ui->Depth_select->value()/2),FadeStartLine.x1(),91+(ui->Depth_select->value()/2));
        ptrEffectUp = scene->addLine(EffectUpLine,redLine);
        ptrEffectDown = scene->addLine(EffectDownLine,redLine);
      break;
    } // end switch
  }   // end if
  on_Fade_select_valueChanged(ui->Fade_select->value());
}   // end on_Delay_select_valueChanged

void LFO::on_Fade_select_valueChanged(int value)
{
    static QGraphicsLineItem *ptrFadeEndLine;
    qreal FadeVal = value/3;
    qreal oldX = ptrFadeEndLine?FadeEndLine.x1():10;
    if (ptrFadeEndLine) {
        scene->removeItem(ptrFadeEndLine);
        ptrFadeEndLine = 0;
    }
    if (FadeText) {
        scene->removeItem(FadeText);
        FadeText = 0;
    }
    if (ptrEffectUp) {
        scene->removeItem(ptrEffectUp);
        ptrEffectUp = 0;
    }
    if (ptrEffectDown) {
        scene->removeItem(ptrEffectDown);
        ptrEffectDown = 0;
    }
      switch(ui->FadeMode_select->currentIndex()) {
      case 0:   // On-In
          FadeVal += FadeStartLine.x2();
          FadeEndLine.setLine(FadeVal,15,FadeVal,160);
          ptrFadeEndLine = scene->addLine(FadeEndLine,dotLine);
          FadeText = scene->addSimpleText(value>50?"Fade":"F");
          FadeText->setPos(value>50 ? (FadeEndLine.x1()+FadeStartLine.x1())/2-10 : (FadeEndLine.x1()+FadeStartLine.x1())/2,5);
          EffectUpLine.setLine(FadeStartLine.x1(), 96, FadeEndLine.x1(), 101-(ui->Depth_select->value()/2));
          EffectDownLine.setLine(FadeStartLine.x1(), 96, FadeEndLine.x1(), 91+(ui->Depth_select->value()/2));
          ptrEffectUp = scene->addLine(EffectUpLine,redLine);
          ptrEffectDown = scene->addLine(EffectDownLine,redLine);
          break;
      case 1:
          FadeVal += FadeStartLine.x2();
          FadeEndLine.setLine(FadeVal,15,FadeVal,160);
          ptrFadeEndLine = scene->addLine(FadeEndLine,dotLine);
          FadeText = scene->addSimpleText(value>50?"Fade":"F");
          FadeText->setPos(value>50 ? (FadeEndLine.x1()+FadeStartLine.x1())/2-10 : (FadeEndLine.x1()+FadeStartLine.x1())/2,5);
          EffectUpLine.setLine(FadeStartLine.x1(), EffectUpLine.y2(), FadeEndLine.x1(), 96);
          EffectDownLine.setLine(FadeStartLine.x1(), EffectDownLine.y2(), FadeEndLine.x1(), 96);
          ptrEffectUp = scene->addLine(EffectUpLine,redLine);
          ptrEffectDown = scene->addLine(EffectDownLine,redLine);
          break;
      case 2:
          FadeVal += FadeStartLine.x2();
          FadeEndLine.setLine(FadeVal,15,FadeVal,160);
          ptrFadeEndLine = scene->addLine(FadeEndLine,dotLine);
          FadeText = scene->addSimpleText(value>50?"Fade":"F");
          FadeText->setPos(value>50 ? (FadeEndLine.x1()+FadeStartLine.x1())/2-10 : (FadeEndLine.x1()+FadeStartLine.x1())/2,5);
          EffectUpLine.setLine(FadeStartLine.x1(), 96, FadeEndLine.x1(), 101-(ui->Depth_select->value()/2));
          EffectDownLine.setLine(FadeStartLine.x1(), 96, FadeEndLine.x1(), 91+(ui->Depth_select->value()/2));
          ptrEffectUp = scene->addLine(EffectUpLine,redLine);
          ptrEffectDown = scene->addLine(EffectDownLine,redLine);
          break;
      case 3:
          FadeVal += FadeStartLine.x2();
          FadeEndLine.setLine(FadeVal,15,FadeVal,160);
          ptrFadeEndLine = scene->addLine(FadeEndLine,dotLine);
          FadeText = scene->addSimpleText(value>50?"Fade":"F");
          FadeText->setPos(value>50 ? (FadeEndLine.x1()+FadeStartLine.x1())/2-10 : (FadeEndLine.x1()+FadeStartLine.x1())/2,5);
          EffectUpLine.setLine(FadeStartLine.x1(), EffectUpLine.y2(), FadeEndLine.x1(), 96);
          EffectDownLine.setLine(FadeStartLine.x1(), EffectDownLine.y2(), FadeEndLine.x1(), 96);
          ptrEffectUp = scene->addLine(EffectUpLine,redLine);
          ptrEffectDown = scene->addLine(EffectDownLine,redLine);
          break;
      } // end switch

}   // end on_Fade_select_valueChanged

void LFO::on_Depth_select_valueChanged(int value)
{
    on_Delay_select_valueChanged(ui->Delay_select->value());
}   // end on_Depth_select_valueChanged

void LFO::on_Rate_select_valueChanged(int value)
{

}   // end on_Rate_select_valueChanged

void LFO::on_FadeMode_select_currentIndexChanged(int index)
{
    if (ptrOffLine) {
        scene->removeItem(ptrOffLine);
        ptrOffLine = 0;
        scene->removeItem(OffText);
        OffText = 0;
    }
    switch(index) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        setOffIn();
        break;
    case 3:
        setOffOut();
        break;
    }
    on_Delay_select_valueChanged(ui->Delay_select->value());
}   // end on_FadeMode_select_currentIndexChanged
