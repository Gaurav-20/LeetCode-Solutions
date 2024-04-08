# Write your MySQL query statement below
SELECT name
FROM SalesPerson
WHERE name NOT IN (
    SELECT s.name
    FROM Orders o
    JOIN Company c
    ON o.com_id = c.com_id
    JOIN SalesPerson s
    ON o.sales_id = s.sales_id
    WHERE c.name = 'RED'
);