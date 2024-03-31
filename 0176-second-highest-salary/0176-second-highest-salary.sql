# Write your MySQL query statement below
SELECT MAX(salary) AS secondHighestSalary
FROM Employee
WHERE salary NOT IN (
    SELECT MAX(salary)
    FROM Employee
);