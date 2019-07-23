#include "parse.h"   //包含示例字符串
#include "json_str.h"
#include "stdio.h"

#include <QFile>

//JSON相关头文件
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QDebug>

int Parse_HeWeather_Now_Json(void)
{
    QJsonParseError err_rpt;
    QJsonDocument  root_Doc = QJsonDocument::fromJson(he_now_json, &err_rpt);//字符串格式化为JSON

    if(err_rpt.error != QJsonParseError::NoError)
    {
        qDebug() << "JSON格式错误";
        return -1;
    }
    else    //JSON格式正确
    {
        //        qDebug() << "JSON格式正确：\n" << root_Doc;

        QJsonObject root_Obj = root_Doc.object();
        QJsonValue weather_Value = root_Obj.value("HeWeather6");    //HeWeather6键的值，是一个数组
        if(weather_Value.isArray()) //可省略
        {
            QJsonObject weather_Obj = weather_Value.toArray().at(0).toObject();   //HeWeather6数组就含有一个元素0

            /* basic键信息 */
            QJsonObject basic_Obj = weather_Obj.value("basic").toObject();
            QString cid = basic_Obj.value("cid").toString();
            QString location = basic_Obj.value("location").toString();
            QString parent_city = basic_Obj.value("parent_city").toString();
            QString cnty = basic_Obj.value("cnty").toString();
            QString lat = basic_Obj.value("lat").toString();
            QString lon = basic_Obj.value("lon").toString();
            QString basic_info = cid + " " + parent_city + " " + cnty + " " + lat + " " + lon;
            qDebug() << basic_info;

            /* update键信息 */
            QJsonObject update_Obj = weather_Obj.value("update").toObject();
            QString loc = "当地时间:" + update_Obj.value("loc").toString();   //当地时间
            QString utc = "UTC时间:" + update_Obj.value("utc").toString();   //UTC时间
            QString status = "解析状态:" + weather_Obj.value("status").toString();    //"ok"
            qDebug() << loc + " " + utc + " " + status;

            /* now键信息*/
            QJsonObject now_Obj = weather_Obj.value("now").toObject();
            QString cond_txt = "白天天气:" + now_Obj.value("cond_txt").toString();
            QString hum = "湿度:" + now_Obj.value("hum").toString();
            QString tmp = "温度:" + now_Obj.value("tmp").toString();
            QString wind_dir = "风向:" +  now_Obj.value("wind_dir").toString();
            QString wind_sc = "风级:" + now_Obj.value("wind_sc").toString();
            qDebug() << cond_txt + " " + hum + " " + tmp + " " + wind_dir + " " + wind_sc;
        }
        qDebug() << "解析完成!";
    }
    return 0;
}

int Parse_Seniverse_Now_Json(void)
{
    QJsonParseError err_rpt;
    QJsonDocument  root_Doc = QJsonDocument::fromJson(seniverse_now_json, &err_rpt);//字符串格式化为JSON
    if(err_rpt.error != QJsonParseError::NoError)
    {
        qDebug() << "JSON格式错误";
        return -1;
    }
    else    //JSON格式正确
    {
        //        qDebug() << "JSON格式正确：\n" << root_Doc;
        QJsonObject root_Obj = root_Doc.object();
        QJsonValue result_Value = root_Obj.value("results");
        if(result_Value.isArray())
        {
            QJsonObject result_Obj = result_Value.toArray().at(0).toObject();

            QString last_update = result_Obj.value("last_update").toString();
            qDebug() << last_update;

            /* location键的值 */
            QJsonObject location_Obj = result_Obj.value("location").toObject();
            QString id = location_Obj.value("id").toString();
            QString name = location_Obj.value("name").toString();
            QString timezone = location_Obj.value("timezone").toString();
            QString path = location_Obj.value("path").toString();
            QString loc_str = id + " " + name + " " + timezone + " " + path ;
            qDebug() << loc_str;

            /* now键 */
            QJsonObject now_Obj = result_Obj.value("now").toObject();
            QString code = "天气代码: " + now_Obj.value("code").toString();
            QString temperature = "当前温度：" + now_Obj.value("temperature").toString();
            QString text = "天气：" + now_Obj.value("text").toString();
            qDebug() << code << temperature << text;
        }
    }
    return 0;
}

int Parse_Seniverse_Forecast_Json(void)
{
    QJsonParseError err_rpt;
    QJsonDocument  root_Doc = QJsonDocument::fromJson(seniverse_forcast_json, &err_rpt);//字符串格式化为JSON
    if(err_rpt.error != QJsonParseError::NoError)
    {
        qDebug() << "JSON格式错误";
        return -1;
    }
    else    //JSON格式正确
    {
        //        qDebug() << "JSON格式正确：\n" << root_Doc;
        QJsonObject root_Obj = root_Doc.object();
        QJsonValue result_Value = root_Obj.value("results");
        if(result_Value.isArray())
        {
            QJsonObject result_Obj = result_Value.toArray().at(0).toObject();

            QString last_update = result_Obj.value("last_update").toString();
            qDebug() << last_update;
            /* location键的值 */
            QJsonObject location_Obj = result_Obj.value("location").toObject();
            QString id = location_Obj.value("id").toString();
            QString name = location_Obj.value("name").toString();
            QString timezone = location_Obj.value("timezone").toString();
            QString path = location_Obj.value("path").toString();
            QString loc_str = id + " " + name + " " + timezone + " " + path ;
            qDebug() << loc_str;

            /* daily预报天气3天，数组元素3个*/
            QJsonValue daily_Vaule = result_Obj.value("daily");
            if(daily_Vaule.isArray())
            {
                for(int idx = 0; idx <= 2; idx++)
                {
                    QJsonObject daily_Obj = daily_Vaule.toArray().at(idx).toObject();
                    QString date = " 日期：" + daily_Obj.value("date").toString();
                    QString text_day =" 白天天气：" +  daily_Obj.value("text_day").toString();
                    QString high = " 最高温度：" + daily_Obj.value("high").toString();
                    QString low = " 最低温度：" + daily_Obj.value("low").toString();
                    QString wind_direction = " 风向：" + daily_Obj.value("wind_direction").toString();
                    QString wind_scale = " 风级：" + daily_Obj.value("wind_scale").toString();
                    qDebug() << date + text_day + high + low + wind_direction + wind_scale;
                }
            }
        }
    }
    return 0;
}

int Parse_AQI_Json(void)
{
    QJsonParseError err_rpt;
    QJsonDocument  root_Doc = QJsonDocument::fromJson(AQI_json, &err_rpt);//字符串格式化为JSON
    if(err_rpt.error != QJsonParseError::NoError)
    {
        qDebug() << "JSON格式错误";
        return -1;
    }
    else    //JSON格式正确
    {
        //        qDebug() << "JSON格式正确：\n" << root_Doc;
        QJsonObject root_Obj = root_Doc.object();

        QString city = root_Obj.value("city").toString();
        QString citycode = root_Obj.value("citycode").toString();
        QString citye = root_Obj.value("citye").toString();
        QString status = root_Obj.value("status").toString();
        qDebug() << city + " " + citycode + " " + citye + " " + status;

        /* data键 */
        QJsonValue data_Vaule = root_Obj.value("data");
        if(data_Vaule.isArray())
        {
            for(int idx = 0; idx <= 10; idx++)
            {
                QJsonObject data_Obj = data_Vaule.toArray().at(idx).toObject();
                QString add = "地址：" + data_Obj.value("add").toString();
                QString aqi = " AQI：" + data_Obj.value("aqi").toString();
                QString lv = " 空气质量等级：" + data_Obj.value("lv").toString();
                QString per = " 空气质量：" + data_Obj.value("per").toString();
                QString pm25 = " PM2.5等级：" + data_Obj.value("pm25").toString();
                qDebug() << add + aqi + lv + per + pm25;
            }
        }
    }
    return 0;
}
//解析
int Parse_BJTime_Json(void)
{
    QJsonParseError err_rpt;
    QJsonDocument  root_Doc = QJsonDocument::fromJson(bj_time_json, &err_rpt);//字符串格式化为JSON
    if(err_rpt.error != QJsonParseError::NoError)
    {
        qDebug() << "JSON格式错误";
        return -1;
    }
    else    //JSON格式正确
    {
        //        qDebug() << "JSON格式正确：\n" << root_Doc;
        QJsonObject root_Obj = root_Doc.object();

        QString success = root_Obj.value("success").toString();
        /* result键 */
        QJsonObject result_Obj = root_Obj.value("result").toObject();
        QString datetime_1 = result_Obj.value("datetime_1").toString();
        QString datetime_2 = result_Obj.value("datetime_2").toString();
        QString timestamp = result_Obj.value("timestamp").toString();
        QString week_1 = result_Obj.value("week_1").toString();
        QString week_2 = result_Obj.value("week_2").toString();
        QString week_3 = result_Obj.value("week_3").toString();
        QString week_4 = result_Obj.value("week_4").toString();
        qDebug() << datetime_1 << datetime_2;
        qDebug() << week_1 << week_2 << week_3 << week_4;
    }
    return 0;
}

//解析数组嵌套的JSON字符串
int Parse_Oil_Price_Json(void)
{
    QJsonParseError err_rpt;
    QJsonDocument  root_Doc = QJsonDocument::fromJson(oil_price_json, &err_rpt);//字符串格式化为JSON
    if(err_rpt.error != QJsonParseError::NoError)
    {
        qDebug() << "JSON格式错误";
        return -1;
    }
    else    //JSON格式正确
    {
        //        qDebug() << "JSON格式正确：\n" << root_Doc;
        QJsonObject root_Obj = root_Doc.object();

        QString msg = root_Obj.value("msg").toString();
        QString update = root_Obj.value("update").toString();
        QString status = root_Obj.value("status").toString();
        QString About = root_Obj.value("About").toString();
        QString Home = root_Obj.value("Home").toString();
        qDebug() << msg << update << status << About << Home;

        /* data键解析 */
        QJsonValue data_Value = root_Obj.value("data");
        if(data_Value.isArray())    //数组中包含5个数组，每个数组5个字符串元素
        {
            for(int idx = 0; idx <= 4; idx++)
            {
                QJsonValue price_Obj = data_Value.toArray().at(idx);
                if(price_Obj.isArray())
                {
                    QString str1 = price_Obj.toArray().at(0).toString();// 每个元素是一个字符串
                    QString str2 = price_Obj.toArray().at(1).toString();
                    QString str3 = price_Obj.toArray().at(2).toString();
                    QString str4 = price_Obj.toArray().at(3).toString();
                    QString str5 = price_Obj.toArray().at(4).toString();
                    qDebug() << str1 << str2 << str3 << str4 << str5 ;
                }
            }
        }
    }
    return 0;
}

/*

二维码生成：http://api.k780.com:88/?app=qr.get&data=www.wangchaochao.top&level=L&size=6
7天天气预报
http://api.k780.com:88/?app=weather.future&weaid=1&&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=json

*/

//解析文件内容,weather.json

int Parse_File_Json(void)
{
    QFile file(":/json/weather.json");  //存放JSON字符串的文件

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
//        qDebug() << "文件打开失败";
        return -1;
    }

//    qDebug() << "文件打开成功!";
    QString json_Str = file.readAll();  //读取内容
    file.close();   //关闭文件

    QJsonParseError err_rpt;
    QJsonDocument root_Doc = QJsonDocument::fromJson(json_Str.toUtf8(), &err_rpt);//字符串格式化为JSON
    if(err_rpt.error != QJsonParseError::NoError)
    {
//        qDebug() << "JSON格式错误";
        return -1;
    }
    else    //JSON格式正确
    {
//        qDebug() << "JSON格式正确：\n" << root_Doc;
        QJsonObject root_Obj = root_Doc.object();

        QString success = root_Obj.value("success").toString();
        qDebug() << "解析状态：" + success;

        QJsonArray result_Arr = root_Obj.value("result").toArray();  //数组
        for(int idx = 0; idx <= 6; idx++)
        {
            QJsonObject result_Obj = result_Arr.at(idx).toObject();
            QString cityid = result_Obj.value("cityid").toString();
            QString citynm = result_Obj.value("citynm").toString();
            QString days = result_Obj.value("days").toString();
            QString week = result_Obj.value("week").toString();
            QString weather = result_Obj.value("weather").toString();
            QString temperature = result_Obj.value("temperature").toString();
            QString wind = result_Obj.value("wind").toString();
            QString winp = result_Obj.value("winp").toString();
            qDebug() << cityid << citynm << days << week << weather << temperature << wind << winp;
        }
    }
    return 0;
}

