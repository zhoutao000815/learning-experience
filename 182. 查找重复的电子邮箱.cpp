//182. �����ظ��ĵ�������
//SQL�ܹ�
//��дһ�� SQL ��ѯ������ Person ���������ظ��ĵ������䡣
//
//ʾ����
//
//+ ---- + -------- - +
//| Id | Email |
//+---- + -------- - +
//| 1 | a@b.com |
//| 2 | c@d.com |
//| 3 | a@b.com |
//+---- + -------- - +
//�����������룬��Ĳ�ѯӦ�������½����
//
//+ -------- - +
//| Email |
//+-------- - +
//| a@b.com |
//+-------- - +
//˵�������е������䶼��Сд��ĸ��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/duplicate-emails
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


#�ӱ��ѯ
select DISTINCT Email from Person, (select Email el, count(Email) cnt from Person  group by Email having count(Email) > 1) tmp where tmp.el = Person.Email;

#��ʱ��
select Email from(select Email, count(Email) as cnt from Person group by Email) as tmp where cnt>1;

#��ʵ�����������Ե������������ش�ӡ������Ϊ��ʱ��
select Email from Person group by Email having count(Email)>1;