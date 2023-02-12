# Write your MySQL query statement below
SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
FROM Employee e, Department d
WHERE (
    SELECT COUNT(DISTINCT salary)
    FROM Employee
    WHERE salary > e.salary AND departmentId = d.id
) < 3 AND e.departmentId = d.Id
ORDER BY d.id, e.salary DESC;