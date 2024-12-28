-- 코드를 작성해주세요

# select year(b.DIFFERENTIATION_DATE) as byr, max(b.SIZE_OF_COLONY) as bm
#     from ECOLI_DATA b
#     group by byr
#     ;

select year(a.DIFFERENTIATION_DATE) as YEAR, (bm-SIZE_OF_COLONY) as YEAR_DEV, ID
from ECOLI_DATA a
left join (
    select year(b.DIFFERENTIATION_DATE) as byr, max(b.SIZE_OF_COLONY) as bm
    from ECOLI_DATA b
    group by byr
) c on year(DIFFERENTIATION_DATE)=c.byr
order by YEAR, YEAR_DEV ;