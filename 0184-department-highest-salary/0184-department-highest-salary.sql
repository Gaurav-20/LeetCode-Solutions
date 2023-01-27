# Write your MySQL query statement below
SELECT dept.name AS Department, emp.name AS Employee, emp.salary AS Salary
FROM ( 
    SELECT d.id, d.name AS name, MAX(e.salary) AS maxSalary
    FROM Department d JOIN Employee e
    ON e.departmentId = d.id
    GROUP BY d.Id
) dept JOIN Employee emp
ON dept.id = emp.departmentId
AND emp.salary = dept.maxSalary;