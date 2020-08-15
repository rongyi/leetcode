-- http://leetcode.com/problems/department-top-three-salaries/description/

SELECT d.Name AS Department, e.Name AS Employee, e.Salary FROM
(SELECT e1.Name, e1.Salary, e1.DepartmentId FROM Employee e1 JOIN Employee e2
ON e1.DepartmentId = e2.DepartmentId AND e1.Salary <= e2.Salary GROUP BY e1.Id
HAVING COUNT(DISTINCT e2.Salary) <= 3) e JOIN Department d ON e.DepartmentId = d.Id
ORDER BY d.Name, e.Salary DESC;
