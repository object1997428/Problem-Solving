with recursive cte_level as (
    select ID, PARENT_ID, 1 as level
    from ECOLI_DATA
    where PARENT_ID is null
    union all
    select A.ID, A.PARENT_ID, B.level+1
    from ECOLI_DATA A
    join cte_level B on A.PARENT_ID= B.ID
)

select ID
from cte_level
where level=3
order by ID asc;