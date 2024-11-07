# Write your MySQL query statement below
select machine_id,Round(AVG
(CASE WHEN activity_type='end' then timestamp
 when activity_type='start' then -timestamp end)*2,3) as processing_time
from Activity
group by machine_id;
