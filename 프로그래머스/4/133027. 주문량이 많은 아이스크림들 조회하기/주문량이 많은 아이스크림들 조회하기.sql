with A as (
    select sum(TOTAL_ORDER) as `aSUM`, FLAVOR
    from JULY
    group by FLAVOR
),
B as (
    select sum(TOTAL_ORDER) as `bSUM`, FLAVOR
    from FIRST_HALF
    group by FLAVOR
)

select A.FLAVOR
from A
join B on A.FLAVOR=B.FLAVOR
order by (`aSUM`+`bSUM`) desc
limit 3