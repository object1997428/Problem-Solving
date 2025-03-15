select b.YY as YEAR, (b.MAXSIZE-SIZE_OF_COLONY) as YEAR_DEV ,ID
from ECOLI_DATA a
join (
    select year(DIFFERENTIATION_DATE) as `YY`, max(SIZE_OF_COLONY) as `MAXSIZE`
    from ECOLI_DATA
    group by year(DIFFERENTIATION_DATE)
) as b on year(a.DIFFERENTIATION_DATE)=b.YY
order by YEAR, YEAR_DEV;