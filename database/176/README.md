## SQL SELECT DISTINCT 语句

在表中，可能会包含重复值。这并不成问题，不过，有时您也许希望仅仅列出不同（distinct）的值。

关键词 DISTINCT 用于返回唯一不同的值。

#### SELECT DISTINCT 列名称 FROM 表名称

① 

```
select * from table limit 2,1;    
```             

//含义是跳过2条取出1条数据，limit后面是从第2条开始读，读取1条信息，即读取第3条数据

② 

```
select * from table limit 2 offset 1;
```      

//含义是从第1条（不包括）数据开始取出2条数据，limit后面跟的是2条数据，offset后面是从第1条开始读取，即读取第2,3条

IFNULL（对于不同的数据库这个关键词不同，mysql是）

```
select  r.status=1 and IFNULL(r.channel_code,'') != 'crm'
```

这种查询方式的意思就是说如果r.channel_code为空则设置为空字符串，自然而然的就不等于crm了。

主要是判断空值用的。