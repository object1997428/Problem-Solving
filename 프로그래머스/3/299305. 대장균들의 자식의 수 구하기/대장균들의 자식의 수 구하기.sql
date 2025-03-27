select a.ID,
ifnull(b.CHILD_COUNT,0) as CHILD_COUNT
from ECOLI_DATA a
left join(
    select PARENT_ID as `PID`, count(1) as CHILD_COUNT
    from ECOLI_DATA
    where PARENT_ID is not null
    group by PARENT_ID
)as b on a.ID=b.PID
order by a.ID