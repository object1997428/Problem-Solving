select mSCORE as SCORE, a.EMP_NO, EMP_NAME, POSITION, EMAIL
from HR_EMPLOYEES a
join (
    select EMP_NO, sum(SCORE) as mSCORE
    from HR_GRADE
    where YEAR = 2022
    group by EMP_NO
    order by sum(SCORE) desc
    limit 1
) as b on a.EMP_NO=b.EMP_NO

