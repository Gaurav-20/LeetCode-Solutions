# Write your MySQL query statement below
WITH cte AS (
    SELECT num, COUNT(*) AS cnt
    FROM MyNumbers
    GROUP BY num
)
SELECT MAX(num) AS num
FROM cte
WHERE cnt = 1;