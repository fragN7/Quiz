//
// Created by Alen on 06/06/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ParticipantWindow.h" resolved

#include "ParticipantWindow.h"
#include "qlistwidget.h"

ParticipantWindow::ParticipantWindow(Controller &c,std::string name,QWidget *parent)
        : c(c), name(name),QWidget(parent), Observer()
{

    ui.setupUi(this);
    QWidget::setWindowTitle(name.c_str());
    QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(answer()));
    QObject::connect(ui.listWidget, SIGNAL(itemSelectionChanged()), this, nullptr);
    c.registerObserver(this);
    ui.label->setText("0");
    populate();
}

void ParticipantWindow::answer()
{
    int row = ui.listWidget->currentRow();
    std::string answer = ui.lineEdit->text().toStdString();
    if (c.answer(answer, row,name)) {
        ui.label->clear();
        ui.label->setText(std::to_string(c.getCurrentScore(name)).c_str());
    }

}

ParticipantWindow::~ParticipantWindow()
{
    delete &c;
}

void ParticipantWindow::populate()
{
    ui.listWidget->clear();
    for (auto q : c.getQuestionsSortedByScore()) {
        QListWidgetItem *item = new QListWidgetItem{ q.toStringParticipant().c_str() };
        ui.listWidget->addItem(item);
    }
    ui.listWidget->setCurrentRow(0);
}

void ParticipantWindow::update()
{
    ui.listWidget->clear();
    for (auto q : c.getQuestionsSortedByScore()) {
        QListWidgetItem *item = new QListWidgetItem{ q.toStringParticipant().c_str() };
        ui.listWidget->addItem(item);
    }
    ui.listWidget->setCurrentRow(0);
}
