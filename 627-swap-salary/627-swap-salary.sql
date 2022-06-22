# Write your MySQL query statement below
UPDATE Salary
SET sex = CHAR(ASCII(sex) ^ ASCII('m') ^ ASCII('f'));