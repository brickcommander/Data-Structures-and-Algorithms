# Write your MySQL query statement below
select event_day day, emp_id, SUM(out_time-in_time) as total_time
from Employees
group by emp_id, event_day;