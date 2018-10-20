SELECT MAX(Salary) as SecondHighestSalary FROM Employee
WHERE Salary NOT IN
(SELECT MAX(Salary) FROM Employee);
