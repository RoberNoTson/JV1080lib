// create_menu_actions.cpp
#include	"JVlibForm.h"
#include	<QtGui>

void JVlibForm::createMenuActions() {
  PortBox = new QComboBox();
  PortBox->setMaxVisibleItems(10);
  QWidgetAction *PortList = new QWidgetAction(menuMIDI_Port);
  PortList->setDefaultWidget(PortBox);
  menuMIDI_Port->removeAction(actionSelectPort);
  menuMIDI_Port->addAction(PortList);

  connect(JVlibForm::actionOpen, SIGNAL(triggered()), this, SLOT(open()));
  connect(JVlibForm::action_Save, SIGNAL(triggered()), this, SLOT(save()));
  connect(JVlibForm::actionSave_As, SIGNAL(triggered()), this, SLOT(saveAs()));
  connect(JVlibForm::actionE_xit, SIGNAL(triggered()), this, SLOT(close()));
  connect(JVlibForm::action_About, SIGNAL(triggered()), this, SLOT(about()));
  connect(JVlibForm::action_Help_Manual, SIGNAL(triggered()), this, SLOT(HelpDoc()));
  connect(JVlibForm::PortBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectedPort()));
  connect(JVlibForm::action_Configuration, SIGNAL(triggered()), this, SLOT(slotConfig()));
  connect(JVlibForm::action_Offline, SIGNAL(triggered(bool)), this, SLOT(slotOffline(bool)));
  connect(JVlibForm::actionCopy, SIGNAL(triggered()), this, SLOT(slotactionCopy()));
  connect(JVlibForm::actionWrite, SIGNAL(triggered()), this, SLOT(slotactionWrite()));
  connect(JVlibForm::actionWhats_This, SIGNAL(activated()), this, SLOT(slotactionWhats_This()));
  connect(JVlibForm::actionAbout_QT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
  actionWrite->setEnabled(false);
  actionCopy->setEnabled(false);
}	// end createActions
