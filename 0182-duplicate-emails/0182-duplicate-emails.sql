# Write your MySQL query statement below
SELECT DISTINCT email FROM (SELECT ROW_NUMBER()   
OVER (PARTITION BY email) AS row_num, email
FROM Person) P
WHERE row_num > 1;