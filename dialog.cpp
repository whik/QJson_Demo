#include "dialog.h"
#include "ui_dialog.h"
#include "parse.h"
#include "create.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    /* JSON的解析 */
//    Parse_HeWeather_Now_Json();
//    Parse_Seniverse_Now_Json();
//    Parse_Seniverse_Forecast_Json();
//    Parse_AQI_Json();
//    Parse_BJTime_Json();
//    Parse_Oil_Price_Json();
      Parse_File_Json();    //解析JSON文件

      /* JSON的构建 */
//      Create_Simple_JSON();       //简单的json键值对
//    Create_BJTime_JSON();       //键的值是一个JSON对象
//    Create_Array_Str_JSON();    //JSON数组，元素是字符串
//    Create_Array_JSON();        //键的值是一个数组，数组包含多个对象元素
//    Create_Array_Nest_JSON();      //数组内嵌套了5个数组，每个数组内有5个字符串元素

}

Dialog::~Dialog()
{
    delete ui;
}


