# Write your MySQL query statement below
SELECT sell_date,count(distinct(product)) as num_sold,GROUP_CONCAT(DISTINCT(PRODUCT)) as products from Activities 
group by sell_date 
order by sell_date asc;
