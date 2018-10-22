 -- http://leetcode.com/problems/employees-earning-more-than-their-managers/description/
 SELECT e1.Name as Employee FROM Employee e1
JOIN Employee e2 ON e1.ManagerId = e2.Id
WHERE e1.Salary > e2.Salary;
