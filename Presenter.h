//
// Created by Alen on 06/06/2022.
//

#pragma once

#include <QWidget>
#include "ui_Presenter.h"
#include "Controller.h"

class Presenter : public QWidget
{
Q_OBJECT

public:
    Presenter(Controller &c, QWidget *parent = Q_NULLPTR);
    ~Presenter();

private:
    Controller &c;
    Ui::Presenter ui;
    void populate();
private slots:
    void add();
};
