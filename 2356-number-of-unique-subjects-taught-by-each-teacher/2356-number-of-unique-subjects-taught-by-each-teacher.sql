# Write your MySQL query statement below
select teacher_id,
count(distinct subject_id) AS cnt from Teacher Group By teacher_id 