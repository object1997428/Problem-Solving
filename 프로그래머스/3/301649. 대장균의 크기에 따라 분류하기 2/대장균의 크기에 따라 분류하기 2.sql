select ID,
case 
when r<=0.25 then 'CRITICAL'
when r<=0.5 then 'HIGH'
when r<=0.75 then 'MEDIUM'
else 'LOW' end as COLONY_NAME
from (
    select ID, percent_rank() over (order by SIZE_OF_COLONY desc) as r
    from ECOLI_DATA
) as a
order by ID asc;