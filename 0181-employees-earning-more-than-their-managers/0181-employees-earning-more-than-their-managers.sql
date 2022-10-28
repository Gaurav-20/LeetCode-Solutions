# Write your MySQL query statement below
SELECT emp.name AS Employee
FROM (Employee emp LEFT JOIN Employee mngr ON emp.managerId = mngr.id)
WHERE emp.salary > mngr.salary;