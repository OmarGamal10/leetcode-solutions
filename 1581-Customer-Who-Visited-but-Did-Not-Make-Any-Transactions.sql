# Write your MySQL query statement below
select customer_id, count(*) as count_no_trans
from Transactions
right join Visits
on Transactions.visit_id=Visits.visit_id
where Transactions.visit_id is null
group by customer_id;
