# Write your MySQL query statement below
SELECT *
FROM Patients
WHERE conditions LIKE '% DIAB1%' || conditions LIKE 'DIAB1%';