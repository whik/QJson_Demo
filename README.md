# QJson_Demo

Qt环境下JSON解析库的使用示例，包含简单和复杂JSON字符串的解析和构建。

- 我的博客： [![](https://img.shields.io/badge/MyBlog-www.wangchaochao.top-orange.svg)](http://www.wangchaochao.top/)
- 编程语言：![](https://img.shields.io/badge/language-CPP-brightgreen.svg?style=plastic)
- Github仓库地址：[![](https://img.shields.io/badge/QJson_Demo-yellow.svg?style=social&logo=github)](https://github.com/whik/QJson_Demo)
- Gitee仓库地址：[![](https://img.shields.io/badge/Gitee-QJson_Demo-orange.svg)](https://gitee.com/whik/QJson_Demo)

使用示例工程基于**Qt 5.8 Windows**开发环境。

相关博客文章：

- [JSON简介](http://www.wangchaochao.top/2018/11/18/cJSON/)

#### JSON的解析

JSON的解析示例是在parse.cpp文件中。

示例的JSON字符串，包含在json_str.h中：

- he_now_json：和风天气实况天气数据的JSON数据
- seniverse_now_json：心知天气实况天气数据
- seniverse_forcast_json：心知天气3天预报信息
- AQI_json：空气质量AQI信息
- bj_time_json：北京时间
- oil_price_json：全国城市油价信息


解析函数：

- Parse_BJTime_Json()：解析北京时间，键的值是一个JSON对象
- Parse_AQI_Json()：解析空气质量AQI，数组嵌套对象
- Parse_HeWeather_Now_Json()：解析和风天气实时数据，一个数组嵌套多个对象
- Parse_Seniverse_Now_Json()：解析心知天气实时数据，一个数组嵌套多个对象
- Parse_Seniverse_Forecast_Json()：解析心知预报天气，数组内嵌套一个数组和多个对象
- Parse_Oil_Price_Json()：解析油价信息，一个数组内嵌套5个数组，每个数组包含5个字符串元素
- Parse_File_Json()：解析JSON文件，内容是7天天气预报信息。

#### JSON的构建

JSON的构建示例在create.cpp文件中。

构建函数：

- Create_Simple_JSON()：构建一个简单的json键值对

```json
{
    "Blog": "https://www.wangchaochao.top/",
    "CSDN": "https://blog.csdn.net/whik1194",
    "Github": "https://github.com/whik/",
    "cnblogs": "https://home.cnblogs.com/u/whik/",
    "enable": true,
    "status": 1,
    "update_time": "20190723"
}
```


- Create_BJTime_JSON()：键的值是一个JSON对象

```json
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
```


- Create_Array_Str_JSON()：JSON数组，元素是字符串

```json
["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
```


- Create_Array_JSON()：键的值是一个数组，数组包含多个对象元素

```json
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
```


- Create_Array_Nest_JSON()：数组内嵌套了5个数组，每个数组内有5个字符串元素

```json
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
```

#### 另一个JSON库此JSON的使用示例

- Github仓库地址：[![](https://img.shields.io/badge/cJSON_Demo-yellow.svg?style=social&logo=github)](https://github.com/whik/cJSON_Demo)
- Gitee仓库地址：[![](https://img.shields.io/badge/Gitee-cJSON_Demo-orange.svg)](https://gitee.com/whik/cJSON_Demo)
- [cJSON_Demo README文件](https://github.com/whik/cJSON_Demo/blob/master/README.md)

相关博客：

- [使用cJSON库解析和构建JSON字符串](http://www.wangchaochao.top/2019/07/21/cJSON-Demo/)

