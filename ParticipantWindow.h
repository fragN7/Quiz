//
// Created by Alen on 06/06/2022.
//

#pragma once

#include <QWidget>
#include "C:\Users\Alen\Documents\GitHub\e913-913-Iaguta-Alen-Mihael-1\cmake-build-debug\e913_913_Iaguta_Alen_Mihael_1_autogen\include\ui_ParticipantWindow.h"
#include "Controller.h"
#include "Observer.h"
#include <QColor>

class ParticipantWindow : public QWidget,public Observer
{
    Q_OBJECT

public:
    ParticipantWindow(Controller &c,std::string name,QWidget *parent = Q_NULLPTR);
    ~ParticipantWindow();

private:
    Ui::ParticipantWindow ui;
    Controller &c;
    std::string name;
    void populate();
    int score;
    void update()override;
private slots:
    void answer();

};

