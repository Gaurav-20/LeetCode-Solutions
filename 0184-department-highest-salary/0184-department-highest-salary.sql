# Write your MySQL query statement below
SELECT Department.name AS Department, e1.name AS Employee, e1.salary AS Salary
FROM Department JOIN Employee e1
ON Department.id = e1.departmentId
WHERE e1.salary = (
    SELECT Max(salary)
    FROM Employee e2
    WHERE e2.departmentId = e1.departmentId
);