# Write your MySQL query statement below
WITH CTE AS
(SELECT salary, dense_rank() OVER (ORDER BY salary DESC) AS rank_desc
FROM Employee)
SELECT MAX(salary) as SecondHighestSalary
FROM CTE
WHERE rank_desc = 2;