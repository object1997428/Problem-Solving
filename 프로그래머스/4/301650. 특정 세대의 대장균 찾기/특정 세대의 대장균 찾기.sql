with recursive sum_tbl as (
    select ID, PARENT_ID, 1 as gen
    from ECOLI_DATA
    where PARENT_ID is null
    union all
    select a.ID, a.PARENT_ID, sum_tbl.gen+1
    from ECOLI_DATA a
    join sum_tbl on sum_tbl.ID=a.PARENT_ID
)

select ID
from sum_tbl
where gen=3