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
    OffLine.setLine(30,10,30,160);
    ptrOffLine = scene->addLine(OffLine,dotLine);
    OffText = scene->addSimpleText("Off");
    OffText->setPos(30,164);
}
void LFO::setOffOut() {
    OffLine.setLine(42,10,42,160);
    ptrOffLine = scene->addLine(OffLine,dotLine);
    OffText = scene->addSimpleText("Off");
    OffText->setPos(40,164);
}
void LFO::FillEffect() {
    static QList<qreal> Xcross;
    static QList<QGraphicsLineItem *> WaveLines;
    if (!Xcross.isEmpty()) Xcross.clear();
    QGraphicsLineItem *dummy;
    while (!WaveLines.isEmpty()) {
        dummy = WaveLines.takeFirst();
        scene->removeItem(dummy);
    }
  if (ui->Rate_select->value()) {
    QPen WavePen(Qt::darkGreen);
    qreal newX1, newX2, newY1, newY2;
    qreal spacer;
    qreal WaveFreq =  35 - (ui->Rate_select->value()/4);
    qreal UpSlope = FadeUpLine.dy() / FadeUpLine.dx();
    qreal DownSlope = FadeDownLine.dy() / FadeDownLine.dx();
    qreal UpBeta = FadeUpLine.y2() - (UpSlope*FadeUpLine.x2());
    qreal DownBeta = FadeDownLine.y2() - (DownSlope*FadeDownLine.x2());
    int L;
    switch(ui->FadeMode_select->currentIndex()) {
      case 0:
      case 2:
        spacer = FadeStartLine.x1()+1;
        for (int x=0;x<=140/WaveFreq;x++) {
            Xcross << spacer;
            spacer += WaveFreq;
            if (spacer > 141) break;
        }        
        L = Xcross.size() - 1;
        for (int n=0;n<L;n+=2) {
            newX1 = n ? (Xcross[n]+Xcross[n-1])/2 : Xcross[n];
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            newY1 = newX1>=FadeEndLine.x1() ? EffectDownLine.y1()-1 : DownSlope*newX1+DownBeta+1;
            if (newY1 >= EffectDownLine.y1()) newY1 = EffectDownLine.y1()-1;
            if (newY1 >= DownSlope*newX2+DownBeta) newY1 = DownSlope*newX2+DownBeta-1;
            if (!n) newY1 = 96;
            newY2 = newX2>=FadeEndLine.x1() ? EffectUpLine.y1()-1 : UpSlope*newX2+UpBeta+1;
            if (newY2 <= EffectUpLine.y1()) newY2 = EffectUpLine.y1()+1;
            if (newY2 < UpSlope*newX2+UpBeta) newY2 = UpSlope*newX2+UpBeta+1;
            dummy = scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        for (int n=1;n<L;n+=2) {
            newX1 = (Xcross[n]+Xcross[n-1])/2;
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            newY1 = newX1>=FadeEndLine.x1() ? EffectUpLine.y1()+1 : UpSlope*newX1+UpBeta+1;
            if (newY1 <= EffectUpLine.y1()) newY1 = EffectUpLine.y1()+1;
            if (newY1 <= UpSlope*newX2+UpBeta) newY1 = UpSlope*newX2+UpBeta+1;
            newY2 = newX2>=FadeEndLine.x1() ? EffectDownLine.y1()-1 : DownSlope*newX2+DownBeta-1;
            if (newY2 >= EffectDownLine.y1()) newY2 = EffectDownLine.y1()-1;
            if (newY2 >= DownSlope*newX2+DownBeta) newY2 = DownSlope*newX2+DownBeta-1;
            dummy = scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        newX1 = Xcross[L] - (WaveFreq/2);
        newX2 = 140;
        newY1 = Xcross.size()%2 ?EffectDownLine.y2()-1:EffectUpLine.y2()-1;
        newY2 = 96;
        dummy = scene->addLine(newX1, newY1, newX2, newY2);
        dummy->setPen(WavePen);
        WaveLines << dummy;
        break;
      case 1:
      case 3:
        spacer = 11;
        for (int x=0;x<=FadeEndLine.x1()/WaveFreq;x++) {
            Xcross << spacer;
            spacer += WaveFreq;
            if (spacer > FadeEndLine.x1()+1) break;
        }
        L = Xcross.size() - 1;
        for (int n=0;n<L;n+=2) {
            newX1 = n ? (Xcross[n]+Xcross[n-1])/2 : Xcross[n];
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            newY1 = newX1<=FadeStartLine.x1() ? EffectDownLine.y1()-1 : DownSlope*newX1+DownBeta+1;
            if (newY1 >= EffectDownLine.y1()) newY1 = EffectDownLine.y1()-1;
            if (!n) newY1 = 96;
            newY2 = newX2<=FadeStartLine.x1() ? EffectUpLine.y1()+1 : UpSlope*newX2+UpBeta-1;
            if (newY2 <= EffectUpLine.y1()) newY2 = EffectUpLine.y1()+1;
            dummy = scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        for (int n=1;n<L;n+=2) {
            newX1 = (Xcross[n]+Xcross[n-1])/2;
            newX2 = (Xcross[n]+Xcross[n+1])/2;
            newY1 = newX1<=FadeStartLine.x1() ? EffectUpLine.y1()+1 : UpSlope*newX1+UpBeta+1;
            if (newY1 <= EffectUpLine.y1()) newY1 = EffectUpLine.y1()+1;
            newY2 = newX2<=FadeStartLine.x1() ? EffectDownLine.y1()-1 : DownSlope*newX2+DownBeta-1;
            if (newY2 >= EffectDownLine.y1()) newY2 = EffectDownLine.y1()-1;
            dummy = scene->addLine(newX1, newY1, newX2, newY2);
            dummy->setPen(WavePen);
            WaveLines << dummy;
        }
        newX1 = Xcross[L] - (WaveFreq/2);
        newX2 = newX1 + (WaveFreq/2);
        if (Xcross.size()%2) {
            newY1 = newX1<FadeStartLine.x1() ? EffectDownLine.y1()-1 : DownSlope*newX1+DownBeta-1;
            newY2 = newX2 > FadeStartLine.x1() ? UpSlope*newX2+UpBeta-1 : EffectUpLine.y1()+1;
        }
        else {
            newY1 = newX1<FadeStartLine.x1() ? EffectUpLine.y1()+1 : UpSlope*newX1+UpBeta+1;
            newY2 = newX2 > FadeStartLine.x1() ? DownSlope*newX2+DownBeta-1 : EffectDownLine.y2()-1;
        }
        if (newX2>= FadeEndLine.x1()) {
            newX2 = FadeEndLine.x1()-1;
            newY2 = 96;
        }
        dummy = scene->addLine(newX1, newY1, newX2, newY2);
        dummy->setPen(WavePen);
        WaveLines << dummy;
        break;
    } // end switch
  } // end if Rate>0
}   // end FillEffect

LFO::LFO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LFO)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    dotLine.setColor(Qt::blue);
    scene->setSceneRect(0, 0, 256, 192);
    scene->addLine(10, 192/2, 140, 192/2, blackLine);     // X axis
    scene->addLine(10,10,10,160,dotLine);   // Note-On line
    QGraphicsSimpleTextItem *OnText = scene->addSimpleText("On");
    OnText->setPos(8,164);
    OffText = 0;
    FadeText = 0;
    DelayText = 0;
    EffectText = 0;
    ui->LFO_display->setScene(scene);
    ui->LFO_display->fitInView(0,0,80,35);
    ui->LFO_display->show();
    // fake set_initial_values section for testing
    ui->Depth_select->blockSignals(true);
    ui->Depth_select->setValue(127);
    ui->Depth_display->display(127);
    ui->Depth_select->blockSignals(false);
    ui->Rate_select ->setValue(64);
    ui->FadeMode_select->setCurrentIndex(0);
    ui->Fade_select->blockSignals(true);
    ui->Fade_select->setValue(64);
    ui->Fade_display->display(64);
    ui->Fade_select->blockSignals(false);
    ui->Delay_select->setValue(64);
}

LFO::~LFO()
{
    delete ui;
}

void LFO::on_Delay_select_valueChanged(int value)
{
    static QGraphicsLineItem *ptrFadeStartLine;
    qreal DelayVal = value/3;
    if (ptrFadeStartLine) {
        scene->removeItem(ptrFadeStartLine);
        ptrFadeStartLine = 0;
    }
    if (DelayText) {
        scene->removeItem(DelayText);
        DelayText = 0;
    }
    if (value) DelayText = scene->addSimpleText(value>50?"Dly":"D");
    switch(ui->FadeMode_select->currentIndex()) {
    case 0:   // On-In
    case 1:
        DelayVal += 10;
        FadeStartLine.setLine(DelayVal,10,DelayVal,160);
        if (DelayText) DelayText->setPos(value>50 ? FadeStartLine.x1()/2 : FadeStartLine.x1()/2+5,5);
        break;
    case 2:   // Off-In
        if (!ptrOffLine) setOffIn();
        DelayVal += OffLine.x1();
        FadeStartLine.setLine(DelayVal,10,DelayVal,160);
        if (DelayText) DelayText->setPos((FadeStartLine.x1()+OffLine.x1())/2-10,5);
      break;
    case 3:   // Off-Out
        if (!ptrOffLine) setOffOut();
        DelayVal += OffLine.x1();
        FadeStartLine.setLine(DelayVal,10,DelayVal,160);
        if (DelayText) DelayText->setPos((FadeStartLine.x1()+OffLine.x1())/2-10,5);
      break;
    } // end switch
    ptrFadeStartLine = scene->addLine(FadeStartLine,dotLine);
    on_Fade_select_valueChanged(ui->Fade_select->value());
}   // end on_Delay_select_valueChanged

void LFO::on_Fade_select_valueChanged(int value)
{
    static QGraphicsLineItem *ptrFadeEndLine;
    qreal FadeVal = value/3 + FadeStartLine.x2();
    if (ptrFadeEndLine) {
        scene->removeItem(ptrFadeEndLine);
        ptrFadeEndLine = 0;
    }
    if (FadeText) {
        scene->removeItem(FadeText);
        FadeText = 0;
    }
    if (ptrFadeUp) {
        scene->removeItem(ptrFadeUp);
        ptrFadeUp = 0;
    }
    if (ptrFadeDown) {
        scene->removeItem(ptrFadeDown);
        ptrFadeDown = 0;
    }
    if (ptrEffectUp) {
        scene->removeItem(ptrEffectUp);
        ptrEffectUp = 0;
    }
    if (ptrEffectDown) {
        scene->removeItem(ptrEffectDown);
        ptrEffectDown = 0;
    }
    FadeEndLine.setLine(FadeVal,10,FadeVal,160);
    ptrFadeEndLine = scene->addLine(FadeEndLine,dotLine);
    switch(ui->FadeMode_select->currentIndex()) {
      case 0:
      case 2:
          FadeUpLine.setLine(FadeStartLine.x1(), 96, FadeEndLine.x1(), 96-(ui->Depth_select->value()/2));
          FadeDownLine.setLine(FadeStartLine.x1(), 96, FadeEndLine.x1(), 96+(ui->Depth_select->value()/2));
          EffectUpLine.setLine(FadeEndLine.x2(), FadeUpLine.y2(), 140, FadeUpLine.y2());
          EffectDownLine.setLine(FadeEndLine.x2(), FadeDownLine.y2(), 140, FadeDownLine.y2());
          break;
      case 1:
      case 3:
          FadeUpLine.setLine(FadeStartLine.x1(), 96-(ui->Depth_select->value()/2), FadeEndLine.x1(), 96);
          FadeDownLine.setLine(FadeStartLine.x1(), 96+(ui->Depth_select->value()/2), FadeEndLine.x1(), 96);
          EffectUpLine.setLine(10, FadeUpLine.y1(), FadeStartLine.x1(), FadeUpLine.y1());
          EffectDownLine.setLine(10, FadeDownLine.y1(), FadeStartLine.x1(), FadeDownLine.y1());
          break;
    } // end switch
    if (value) {
        FadeText = scene->addSimpleText(value>50?"Fade":"F");
        FadeText->setPos(value>50 ? (FadeEndLine.x1()+FadeStartLine.x1())/2-10 : (FadeEndLine.x1()+FadeStartLine.x1())/2,5);
    }
    ptrFadeUp = scene->addLine(FadeUpLine,redLine);
    ptrFadeDown = scene->addLine(FadeDownLine,redLine);
    ptrEffectUp = scene->addLine(EffectUpLine,redLine);
    ptrEffectDown = scene->addLine(EffectDownLine,redLine);
    on_Waveform_select_currentIndexChanged(ui->Waveform_select->currentIndex());
    FillEffect();
}   // end on_Fade_select_valueChanged

void LFO::on_Depth_select_valueChanged()
{
    on_Delay_select_valueChanged(ui->Delay_select->value());
}   // end on_Depth_select_valueChanged

void LFO::on_FadeMode_select_currentIndexChanged(int index)
{
    if (ptrOffLine) {
        scene->removeItem(ptrOffLine);
        ptrOffLine = 0;
        scene->removeItem(OffText);
        OffText = 0;
    }
    if (index == 2) setOffIn();
    if (index == 3) setOffOut();
    on_Delay_select_valueChanged(ui->Delay_select->value());
}   // end on_FadeMode_select_currentIndexChanged

void LFO::on_Rate_select_valueChanged()
{
    on_Delay_select_valueChanged(ui->Delay_select->value());
}   // end on_Rate_select_valueChanged

void LFO::on_Waveform_select_currentIndexChanged(int index)
{
    switch(index) {
    case 0: // Delta
        break;
    case 1: // Sine
        break;
    case 2: // Sawtooth
        break;
    case 3: // Square
        break;
    case 4: // Trapezoid
        break;
    case 5: // Sample/Hold
        break;
    case 6: // Random
        break;
    case 7: // Chaotic
        break;
    }   // end switch
}   // end on_Waveform_select_currentIndexChanged
