//177. 第N高的薪水
//编写一个 SQL 查询，获取 Employee 表中第 n 高的薪水（Salary）。
//
//+ ---- + -------- +
//| Id | Salary |
//+---- + -------- +
//| 1 | 100 |
//| 2 | 200 |
//| 3 | 300 |
//+---- + -------- +
//例如上述 Employee 表，n = 2 时，应返回第二高的薪水 200。如果不存在第 n 高的薪水，那么查询应返回 null。
//
//+ ------------------------ +
//| getNthHighestSalary(2) |
//+------------------------ +
//| 200 |
//+------------------------ +
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/nth-highest-salary
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N : = N - 1;
RETURN(
# Write your MySQL query statement below.
	select Salary from Employee GROUP BY salary order by Salary DESC limit 1 offset N                 //order by Salary DESC降序排列，GROUP BY salary分组去重，（偏移量从0开始是第1位）那就偏移N-1位，是第N位。
	);
END