# Write your MySQL query statement below
SELECT DISTINCT a.num AS ConsecutiveNums
FROM Logs a JOIN Logs b
ON a.num = b.num AND a.id + 1 = b.id
JOIN Logs c
ON a.num = c.num AND a.id + 2 = c.id;