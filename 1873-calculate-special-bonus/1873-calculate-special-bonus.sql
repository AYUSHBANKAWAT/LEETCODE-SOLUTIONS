select employee_id,
(
CASE 
    WHEN employee_id%2=1 and name not like 'M%' then salary
    else 0
    end
) as 'bonus' from Employees order by employee_id;

