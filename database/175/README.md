## 175. 组合两个表

外连接可分为：左连接、右连接、全然外连接。

1、左连接  left join 或 left outer join

SQL语句：select * from student left join course on student.ID=course.ID

左外连接包括left join左表所有行。

假设左表中某行在右表没有匹配，则结果中相应行右表的部分所有为空(NULL).

注：此时我们不能说结果的行数等于左表数据的行数。

当然此处查询结果的行数等于左表数据的行数，由于左右两表此时为一对一关系。