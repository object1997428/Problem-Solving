select ID,
case when PERCENT <=0.25 then 'CRITICAL'
when PERCENT <=0.5 then 'HIGH'
when PERCENT <=0.75 then 'MEDIUM'
else 'LOW' end as 'COLONY_NAME'
from (
    select ID
    ,percent_rank() over (order by SIZE_OF_COLONY desc) as PERCENT
    from ECOLI_DATA
) as a
order by ID