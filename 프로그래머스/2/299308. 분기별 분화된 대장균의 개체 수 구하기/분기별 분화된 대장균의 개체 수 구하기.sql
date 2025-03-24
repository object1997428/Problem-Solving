SELECT 
    case when month(DIFFERENTIATION_DATE)<=3 then '1Q'
    when month(DIFFERENTIATION_DATE)<=6 then '2Q'
    when month(DIFFERENTIATION_DATE)<=9 then '3Q'
    else '4Q' end as QUARTER
    ,count(ID) as ECOLI_COUNT
FROM ECOLI_DATA
GROUP BY QUARTER
ORDER BY QUARTER;
