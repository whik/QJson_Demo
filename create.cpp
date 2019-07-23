#include "create.h"
#include <QDebug>

//JSON相关头文件
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

//一个简单的JSON键值对生成
void Create_Simple_JSON(void)
{
/*
{
    "Blog": "https://www.wangchaochao.top/",
    "CSDN": "https://blog.csdn.net/whik1194",
    "Github": "https://github.com/whik/",
    "cnblogs": "https://home.cnblogs.com/u/whik/",
    "enable": true,
    "status": 1,
    "update_time": "20190723"
}
*/
    //创建JSON对象
    QJsonObject root_Obj;
    //添加键值对，值的类型自动识别，顺序不可自定义
    root_Obj.insert("CSDN", "https://blog.csdn.net/whik1194");
    root_Obj.insert("cnblogs", "https://home.cnblogs.com/u/whik/");
    root_Obj.insert("Github", "https://github.com/whik/");
    root_Obj.insert("Blog", "https://www.wangchaochao.top/");
    root_Obj.insert("status", 1);
    root_Obj.insert("enable", true);
    root_Obj.insert("update_time", "20190723");

    //创建Json文档
    QJsonDocument root_Doc;
    root_Doc.setObject(root_Obj);
    QByteArray root_str = root_Doc.toJson(QJsonDocument::Compact);  //紧凑格式
//    QByteArray root_str = root_Doc.toJson(QJsonDocument::Indented);   //标准JSON格式    QString strJson(root_str);
    QString strJson(root_str);
    qDebug() << strJson;
}

void Create_BJTime_JSON(void)
{
/*
{
    "status": "success",
    "result": {
        "timestamp": "ok",
        "datetime_1": "2019-07-21 10:46:57",
        "datetime_2": "2019年07月21日 10时46分57秒",
        "week_1": "0",
        "week_2": "星期日",
        "week_3": "周日",
        "week_4": "Sunday"
    },
    "Blog": "www.wangchaochao.top"
}
*/
    QJsonObject result_Obj;
    result_Obj.insert("timestamp", "ok");
    result_Obj.insert("datetime_1", "2019-07-21 10:46:57");
    result_Obj.insert("datetime_2", "2019年07月21日 10时46分57秒");
    result_Obj.insert("week_1", "0");
    result_Obj.insert("week_2", "星期日");
    result_Obj.insert("week_3", "周日");
    result_Obj.insert("week_4", "Sunday");

    QJsonObject root_Obj;
    //添加键值对，值的类型自动识别，顺序不可自定义
    root_Obj.insert("status", "success");
    root_Obj.insert("Blog", "www.wangchaochao.top");
    root_Obj.insert("result", result_Obj);

    //创建Json文档
    QJsonDocument root_Doc;
    root_Doc.setObject(root_Obj);
    QByteArray root_str = root_Doc.toJson(QJsonDocument::Compact);  //紧凑格式
//    QByteArray root_str = root_Doc.toJson(QJsonDocument::Indented);   //标准JSON格式
//    qDebug() << root_str; //中文输出乱码
    QString strJson(root_str);
    qDebug() << strJson;
}

void Create_Array_Str_JSON(void)
{
/*
["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
*/
    QJsonArray root_Arr;

    root_Arr.insert(0, "Sunday");
    root_Arr.insert(1, "Monday");
    root_Arr.insert(2, "Tuesday");
    root_Arr.insert(3, "Wednesday");
    root_Arr.insert(4, "Thursday");
    root_Arr.insert(5, "Friday");
    root_Arr.insert(6, "Saturday");

    //创建Json文档
    QJsonDocument root_Doc;
    root_Doc.setArray(root_Arr);
    QByteArray root_str = root_Doc.toJson(QJsonDocument::Compact);  //紧凑格式
//    QByteArray root_str = root_Doc.toJson(QJsonDocument::Indented);   //标准JSON格式
//    qDebug() << root_str; //中文输出乱码
    QString strJson(root_str);
    qDebug() << strJson;
}

void Create_Array_JSON(void)
{
    QJsonObject day0_Obj;
    QJsonObject day1_Obj;
    QJsonObject day2_Obj;

    day0_Obj.insert("date", "2019-07-21");
    day0_Obj.insert("cond_txt", "多云");
    day0_Obj.insert("cond_code", "101");
    day0_Obj.insert("hum", "23");
    day0_Obj.insert("tmp_H", "31");
    day0_Obj.insert("tmp_L", "25");

    day1_Obj.insert("date", "2019-07-21");
    day1_Obj.insert("cond_txt", "阵雨");
    day1_Obj.insert("cond_code", "107");
    day1_Obj.insert("hum", "44");
    day1_Obj.insert("tmp_H", "30");
    day1_Obj.insert("tmp_L", "26");

    day2_Obj.insert("date", "2019-07-22");
    day2_Obj.insert("cond_txt", "晴");
    day2_Obj.insert("cond_code", "100");
    day2_Obj.insert("hum", "20");
    day2_Obj.insert("tmp_H", "33");
    day2_Obj.insert("tmp_L", "26");

    QJsonArray weather_Arr;
    weather_Arr.insert(0, day0_Obj);
    weather_Arr.insert(1, day1_Obj);
    weather_Arr.insert(2, day2_Obj);

    QJsonObject root_Obj;
    root_Obj.insert("status", "ok");
    root_Obj.insert("update", "2019-07-21 11:00");
    root_Obj.insert("Blog", "www.wangchaochao.top");
    root_Obj.insert("weather", weather_Arr);    //数组作为weather键的值

    //创建Json文档
    QJsonDocument root_Doc;
    root_Doc.setObject(root_Obj);
    QByteArray root_str = root_Doc.toJson(QJsonDocument::Compact);  //紧凑格式
//    QByteArray root_str = root_Doc.toJson(QJsonDocument::Indented);   //标准JSON格式
//    qDebug() << root_str; //中文输出乱码
    QString strJson(root_str);
    qDebug() << strJson;
}
/*
{
    "status": "ok",
    "weather": [{
        "date": "2019-07-21",
        "cond_txt": "多云",
        "cond_code": "101",
        "hum": "23",
        "tmp_H": "31",
        "tmp_L": "25"
    }, {
        "date": "2019-07-22",
        "cond_txt": "晴",
        "cond_code": "100",
        "hum": "20",
        "tmp_H": "33",
        "tmp_L": "26"
    }, {
        "date": "2019-07-23",
        "cond_txt": "阵雨",
        "cond_code": "107",
        "hum": "45",
        "tmp_H": "32",
        "tmp_L": "25"
    }],
    "update": "2019-07-21 11:00",
    "Blog": "www.wangchaochao.top"
}
*/

//构建包含多个数组的JSON字符串
void Create_Array_Nest_JSON(void)
{
    QJsonArray table_Arr = {"地区", "92号汽油", "95号汽油", "98号汽油", "0号柴油"};
    QJsonArray bj_Arr = {"北京", "6.78", "7.21", "8.19", "6.45"};
    QJsonArray sh_Arr = {"上海", "6.74", "7.17", "7.87", "6.39"};
    QJsonArray js_Arr = {"江苏", "6.75", "7.18", "8.06", "6.37"};
    QJsonArray tj_Arr = {"天津", "6.77", "7.15", "8.07", "6.41"};

    QJsonArray data_Arr;    //数组内嵌套了5个数组
    data_Arr.insert(0, table_Arr);
    data_Arr.insert(1, bj_Arr);
    data_Arr.insert(2, sh_Arr);
    data_Arr.insert(3, js_Arr);
    data_Arr.insert(4, tj_Arr);

    QJsonObject root_Obj;

    root_Obj.insert("status", "ok");
    root_Obj.insert("msg", "全国各省份汽柴油价格信息");
    root_Obj.insert("update", "2019-07-21");
    root_Obj.insert("About", "wcc");
    root_Obj.insert("Blog", "www.wangchaochao.top");
    root_Obj.insert("data", data_Arr);  //数组作为键的值

    //创建Json文档
    QJsonDocument root_Doc;
    root_Doc.setObject(root_Obj);
    QByteArray root_str = root_Doc.toJson(QJsonDocument::Compact);  //紧凑格式
//    QByteArray root_str = root_Doc.toJson(QJsonDocument::Indented);   //标准JSON格式
//    qDebug() << root_str; //中文输出乱码
    QString strJson(root_str);
    qDebug() << strJson;
}
/*
{
    "status": "ok",
    "msg": "全国各省份汽柴油价格信息",
    "update": "2019-07-21",
    "data": [
        ["地区", "92号汽油", "95号汽油", "98号汽油", "0号柴油"],
        ["北京", "6.78", "7.21", "8.19", "6.45"],
        ["上海", "6.74", "7.17", "7.87", "6.39"],
        ["江苏", "6.75", "7.18", "8.06", "6.37"],
        ["天津", "6.77", "7.15", "8.07", "6.41"]
    ],
    "About": "wcc",
    "Blog": "www.wangchaochao.top"
}
*/


