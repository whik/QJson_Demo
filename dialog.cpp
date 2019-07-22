#include "dialog.h"
#include "ui_dialog.h"
#include "parse.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    Parse_HeWeather_Now_Json();
    Parse_Seniverse_Now_Json();
    Parse_Seniverse_Forecast_Json();
    Parse_AQI_Json();
    Parse_BJTime_Json();
    Parse_Oil_Price_Json();

}

Dialog::~Dialog()
{
    delete ui;
}


