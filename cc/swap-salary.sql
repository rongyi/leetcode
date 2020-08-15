-- http://leetcode.com/problems/swap-salary/description/
update salary set sex = CHAR(ASCII('f') ^ ASCII('m') ^ ASCII(sex))
