//177. ��N�ߵ�нˮ
//��дһ�� SQL ��ѯ����ȡ Employee ���е� n �ߵ�нˮ��Salary����
//
//+ ---- + -------- +
//| Id | Salary |
//+---- + -------- +
//| 1 | 100 |
//| 2 | 200 |
//| 3 | 300 |
//+---- + -------- +
//�������� Employee ��n = 2 ʱ��Ӧ���صڶ��ߵ�нˮ 200����������ڵ� n �ߵ�нˮ����ô��ѯӦ���� null��
//
//+ ------------------------ +
//| getNthHighestSalary(2) |
//+------------------------ +
//| 200 |
//+------------------------ +
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/nth-highest-salary
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N : = N - 1;
RETURN(
# Write your MySQL query statement below.
	select Salary from Employee GROUP BY salary order by Salary DESC limit 1 offset N                 //order by Salary DESC�������У�GROUP BY salary����ȥ�أ���ƫ������0��ʼ�ǵ�1λ���Ǿ�ƫ��N-1λ���ǵ�Nλ��
	);
END