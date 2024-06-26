# Write your MySQL query statement below
WITH Manager AS (
    SELECT managerId AS id
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(*) >= 5
)
SELECT e.name
FROM Employee e JOIN Manager m
ON e.id = m.id;