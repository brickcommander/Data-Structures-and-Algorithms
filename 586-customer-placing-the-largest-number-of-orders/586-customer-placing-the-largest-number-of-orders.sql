select customer_number from orders
group by customer_number 
order by COUNT(customer_number) DESC
LIMIT 1 OFFSET 0;