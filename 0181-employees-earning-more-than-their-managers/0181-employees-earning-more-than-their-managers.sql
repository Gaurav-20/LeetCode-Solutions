# Write your MySQL query statement below
SELECT emp.name AS Employee
FROM Employee emp JOIN Employee manager
ON emp.managerId = manager.id
WHERE emp.salary > manager.salary;